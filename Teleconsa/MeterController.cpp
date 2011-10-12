#include "StdAfx.h"
#include "AppSettings.h"
#include "MeterController.h"
#include "Form1.h"

#define SIZE_BUFFER_METERS 12
#define SIZE_BUFFER_BREAKS 243
#define SIZE_BUFFER_LOAD_PROFILE 7
#define SIZE_BUFFER_FINALIZE 8

using namespace Teleconsa;
using namespace System::Collections;
using namespace System::Windows::Forms;

MeterController::MeterController(Form^ form, PortCommunicator^ comm) {
	this->mainForm = form;
	this->comm = comm;
	this->serials = gcnew ArrayList;
	this->currentMeter = 0;
}

MeterController::~MeterController(void) {
}

void MeterController::Init() {
	Form1^ form = (Form1^)mainForm;
	comm->serialPort->BaudRate = int::Parse(form->txtBaudRate->Text); // 9600
	Parity parity;
	if(form->cbParity->SelectedIndex == 0) { parity = Parity::None;
	} else if(form->cbParity->SelectedIndex == 1) { parity = Parity::Even;
	} else if(form->cbParity->SelectedIndex == 2) { parity = Parity::Odd;
	}
	comm->serialPort->Parity = parity; // None
	comm->serialPort->DataBits = int::Parse(form->txtDataBits->Text); // 8
	StopBits stop;
	if(form->cbStopBits->SelectedIndex == 0) { stop = StopBits::None;
	} else if(form->cbStopBits->SelectedIndex == 1) { stop = StopBits::One;
	} else if(form->cbStopBits->SelectedIndex == 2) { stop = StopBits::OnePointFive;
	} else if(form->cbStopBits->SelectedIndex == 3) { stop = StopBits::Two;
	}
	comm->serialPort->StopBits = stop; // One
}

void MeterController::Log(String^ message) {
	Form1^ form = (Form1^)mainForm;
	form->Log(message);
}

void MeterController::Process(String^ message) {
	Form1^ form = (Form1^)mainForm;
	form->Process(message);
}

String^ MeterController::UIntToChar(unsigned int value) {
	return Convert::ToString(Convert::ToChar(value));
}

array<unsigned char>^ MeterController::ConvertArray(ArrayList^ buffer) {
	array<unsigned char>^ ubuf = gcnew array<unsigned char>(buffer->Count);
	for(int i = 0; i < buffer->Count; i++) {
		ubuf[i] = (unsigned int) ((int) buffer[i]);
	}
	return ubuf;
}

float  MeterController::ConvertToFloat(ArrayList^ buffer, int index) {
	String ^binary = "";
	for(int i=index; i<index+4; i++) {
		binary = binary + Convert::ToString((int) buffer[i],2)->PadLeft(8,'0');
	}

	// Exchange sign bit to convert to IEEE 754 format
	String ^sign = binary->Substring(8,1);
	binary = binary->Remove(8,1);
	binary = binary->Insert(0,sign);

	// Convert and invert bytes (IEEE 754 is Little Endian)
	array<unsigned char>^ byteArray = {0, 0, 0, 0};
	for(int i=0; i<4; i++) {
		byteArray[3-i] = Convert::ToByte(binary->Substring(i*8, 8), 2);
	}
	return BitConverter::ToSingle(byteArray, 0);
}

array<unsigned char>^ MeterController::HexToChar(String^ hexString) {
	array<unsigned char>^ ubuf = gcnew array<unsigned char>(hexString->Length/2);
	for(int i=0; i<hexString->Length; i+=2) {
		String^ hexByte = hexString->Substring(i, 2);
		ubuf[i/2] = (unsigned char) Convert::ToUInt16(hexByte, 16);
	}
	return ubuf;
}

void MeterController::CreateBreaksFile(ArrayList^ buffer) {
	Form1^ form = (Form1^)mainForm;
	String^ startIdentifer = "";
	for(int i = 0; i < 3; i++) {
		int byte = (int)buffer[i];
		startIdentifer += UIntToChar((unsigned int) byte);
	}
	if(startIdentifer->CompareTo("-()") == 0) {
		String^ text = endLine;
		text += "                   INTERRUPCIONES REGISTRADAS                    " + endLine;
		text += "_________________________________________________________________" + endLine;
		text += "                     |                     |                     " + endLine;
		text += "    Fecha Inicial    |     Fecha Final     | Duracion (hh:mm:ss) " + endLine;
		text += "_____________________|_____________________|_____________________" + endLine;
		for(int i = 3; i < buffer->Count; i+=12) {
			if((int)buffer[i] != 255) {
				try {
					DateTime datetime1 = GetDate6(buffer, i);
					DateTime datetime2 = GetDate6(buffer, i+6);
					text += " " + GetStrDate(datetime1) + " - " + GetStrDate(datetime2) + " - " + GetBreakTime(datetime1, datetime2) + endLine;
				} catch(Exception^) {}
			}
		}
		form->txtBreaks->Text = text;
		
		String^ fileName = serials[currentMeter] + " (Interrupciones)";
		this->SaveFile(fileName, "int", text);
	} else {
		Log("ERROR: Identificador de inicio inválido. Operación abortada.");
	}
}

void MeterController::CreateEnergyFiles(ArrayList^ buffer) {
	array<unsigned char>^ byteArray = this->ConvertArray(buffer);
	Form1^ form = (Form1^)mainForm;
	String^ text = "";
	int i = 0;
	while((int)buffer[i] == 255) i++;
	ArrayList^ dates = gcnew ArrayList;
	ArrayList^ actives = gcnew ArrayList;
	ArrayList^ reactives = gcnew ArrayList;
	while(i <= buffer->Count-energyFrameSize) {
		DateTime datetime;
		bool validDate = false;
		try {
			datetime = this->GetDate5(buffer, i);
			validDate = true;
		} catch(Exception^ exc) {
			Log(exc->Message);
			validDate = false;
		}
		if(validDate) {
			float activeEnergy = this->ConvertToFloat(buffer, i+5);
			float reactiveEnergy = this->ConvertToFloat(buffer, i+9);
			text += String::Format("{0};{1};{2}", datetime.ToString("yyyy/MM/dd HH:mm"), activeEnergy, reactiveEnergy) + endLine;
			// Totales
			int row = 0;
			array<float> ^activesDay;
			array<float> ^reactivesDay;
			if(dates->Contains(datetime.ToString("yyyy/MM/dd"))) {
				row = dates->IndexOf(datetime.ToString("yyyy/MM/dd"));
			} else {
				row = dates->Count;
				activesDay = gcnew array<float>(24);
				reactivesDay = gcnew array<float>(24);
				for(int k=0; k<24; k++) {
					activesDay[k] = 0;
					reactivesDay[k] = 0;
				}
				dates->Add(datetime.ToString("yyyy/MM/dd"));
				actives->Add(activesDay);
				reactives->Add(reactivesDay);
			}
			int col = datetime.Hour;
			activesDay = (array<float>^) actives[row];
			reactivesDay = (array<float>^) reactives[row];
			activesDay[col] += activeEnergy;
			reactivesDay[col] += reactiveEnergy;
			i += energyFrameSize;
		} else {
			i++;
		}
	}
	form->txtConsumo->Text = text;
	String^ fileName = serials[currentMeter] + " (Consumos)";
	this->SaveFile(fileName, "nrg", text);
	// Totales
	String ^totales = "";
	for(int i=0; i<dates->Count; i++) {
		array<float> ^activesDay = (array<float>^) actives[i];
		array<float> ^reactivesDay = (array<float>^) reactives[i];
		String ^actDayStr = "";
		String ^reactDayStr = "";
		for(int j=0; j<24; j++) {
			actDayStr += ";" + String::Format("{0:R}", activesDay[j]);
			reactDayStr += ";" + String::Format("{0:R}", reactivesDay[j]);
		}
		totales += String::Format("{0};{1};{2};{3}{4}",dates[i],"0001",serials[currentMeter],"kVarhD",actDayStr) + endLine;
		totales += String::Format("{0};{1};{2};{3}{4}",dates[i],"0001",serials[currentMeter],"kWhD",reactDayStr) + endLine;
	}
	form->txtTotales->Text = totales;
	fileName = serials[currentMeter] + " (Totales)";
	this->SaveFile(fileName, "tot", totales);
}

void MeterController::SaveFile(String^ fileName, String^ extension, String^ text) {
	AppSettings^ settings = gcnew AppSettings;
	DateTime datetime = DateTime::Now;
	String^ date = datetime.ToString(" [yyyy-MM-dd HHmmss]");
	fileName = fileName + date + "." + extension;
	String^ filePath = settings->Read("settings", "FOLDER_PATH", "C:\\Teleprodelec") + "\\" + fileName;
	if(File::Exists(filePath)) {
		File::Delete(filePath);
	}
	FileInfo ^file = gcnew FileInfo(filePath);
	file->Directory->Create();
	FileStream^ fs = File::OpenWrite(filePath);
	try {
		array<Byte>^info = (gcnew UTF8Encoding(true))->GetBytes(text);
		fs->Write(info, 0, info->Length);
	} finally {
		if(fs) delete (IDisposable^)fs;
	}
}

DateTime MeterController::GetDate6(ArrayList^ buffer, int i) {
	int dd = int::Parse(((int)buffer[i]).ToString("X"));
	int mm = int::Parse(((int)buffer[i+1]).ToString("X"));
	int yyyy = 2000 + int::Parse(((int)buffer[i+2]).ToString("X"));
	int hh = int::Parse(((int)buffer[i+3]).ToString("X"));
	int mi = int::Parse(((int)buffer[i+4]).ToString("X"));
	int ss = int::Parse(((int)buffer[i+5]).ToString("X"));
	return DateTime(yyyy, mm, dd, hh, mi, ss);
}

DateTime MeterController::GetDate5(ArrayList^ buffer, int i) {
	int hh = int::Parse(((int)buffer[i]).ToString("X"));
	int mi = int::Parse(((int)buffer[i+1]).ToString("X"));
	int ss = 0;
	int dd = int::Parse(((int)buffer[i+2]).ToString("X"));
	int mm = int::Parse(((int)buffer[i+3]).ToString("X"));
	int yyyy = 2000 + int::Parse(((int)buffer[i+4]).ToString("X"));
	return DateTime(yyyy, mm, dd, hh, mi, ss);
}

String^ MeterController::GetStrDate(DateTime datetime) {
	return datetime.ToString("yyyy/MM/dd HH:mm:ss");
}

String^ MeterController::GetBreakTime(DateTime datetime1, DateTime datetime2) {
	TimeSpan diff = datetime2.Subtract(datetime1);
	return diff.ToString();
}

bool MeterController::Connect() {
	Form1^ form = (Form1^)mainForm;
	Decimal portNumber = form->portNumber->Value;
	try {
		Process(String::Format("Abriendo puerto {0}...", "COM"+portNumber));
		comm->serialPort->PortName = "COM"+portNumber;
		comm->serialPort->Open();
		strMessage = String::Format("Conectado a {0}\n", "COM"+portNumber);
		form->tsStatus->Text = strMessage;
		Log(strMessage);
		Process("");
		return true;
	} catch (Exception^ exc) {
		strMessage = String::Format("ERROR abriendo el puerto ({0})\nIntente cerrarlo primero.", "COM"+portNumber);
		MessageBox::Show(strMessage, "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		Log(exc->ToString());
	}
	return false;
}

ArrayList^ MeterController::Check() {
	serials->Clear();
	Form1^ form = (Form1^)mainForm;
	if(comm->Start()) {
		Process("Interrogando medidores...");
		comm->Write("6");
		ArrayList^ buffer = comm->Read(SIZE_BUFFER_METERS);
		Log("Recibidos: [" + buffer->Count + "]");
		String^ download = endLine;
		for each(int byte in buffer) {
			download += String::Format("{0:X2}", byte) + "  ";
		}
		Log("Respuesta: " + download + "\n");
		if(buffer->Count > 10) {
			for(int i=0; i<10; i+=2) {
				serials->Add((int)buffer[i+1] + (int)buffer[i+2]*256);
			}
		}
		Process("");
	}
	return serials;
}

bool MeterController::Disconnect() {
	Form1^ form = (Form1^)mainForm;
	strMessage = String::Format("Cerrando puerto {0}...", "COM"+form->portNumber->Value);
	if(comm->serialPort->IsOpen) {
		Process(strMessage);
		comm->serialPort->Close();
		strMessage = String::Format("Puerto {0} cerrado.", comm->serialPort->PortName);
		form->tsStatus->Text = strMessage;
		Log(strMessage);
		Process("");
		return true;
	} else {
		strMessage = String::Format("El puerto {0} ya estaba cerrado.", comm->serialPort->PortName);
		MessageBox::Show(strMessage, "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		form->tsStatus->Text = strMessage;
		Log(strMessage);
		return false;
	}
}

void MeterController::SendCmd(String^ cmd) {
	Form1^ form = (Form1^)mainForm;
	if(comm->Start()) {
		Process(String::Format("Enviando: {0}", cmd));
		comm->Write(cmd);
		ArrayList^ buffer = comm->Read();
		Log("Recibidos: [" + buffer->Count + "]");
		String^ download = endLine;
		for each(int byte in buffer) {
			download += String::Format("{0:X2}", byte) + "  ";
		}
		Log("Respuesta: " + download + endLine);
	}
	Process("");
}

bool MeterController::GetBreaks() {
	Form1^ form = (Form1^)mainForm;
	Process("Descargando interrupciones...");
	if(comm->Start()) {
		comm->Write("W");
		ArrayList^ buffer = comm->Read(SIZE_BUFFER_BREAKS);
		Log("Recibidos: [" + buffer->Count + "]");
		String^ download = endLine;
		for each(int byte in buffer) {
			download += String::Format("{0:X2}", byte) + "  ";
		}
		Log("Respuesta: " + download + endLine);
		if(buffer->Count == SIZE_BUFFER_BREAKS) {
			CreateBreaksFile(buffer);
			Process("");
			return true;
		} else {
			form->tsStatus->Text = "Error descargando interrupciones.";
		}
	}
	Process("");
	return false;
}

bool MeterController::GetLoadProfile(int numDays) {
	Form1^ form = (Form1^)mainForm;
	Process("Descargando perfil de carga...");
	if(comm->Start()) {
		comm->Write("1");
		ArrayList^ buffer = comm->Read(SIZE_BUFFER_LOAD_PROFILE);
		Log("Recibidos: [" + buffer->Count + "]");
		String^ download = endLine;
		for each(int byte in buffer) {
			download += String::Format("{0:X2}", byte) + "  ";
		}
		Log("Respuesta: " + download);
		if(buffer->Count == SIZE_BUFFER_LOAD_PROFILE) {
			DownloadData(buffer, numDays);
			Process("");
			return true;
		} else {
			form->tsStatus->Text = "Error descargando interrupciones.";
		}
	}
	Process("");
	return false;
}

bool MeterController::DownloadData(ArrayList^ buffer, int numDays) {
	Process("Creando solicitud...");
	int addressLow = (int)buffer[1];
	int addressHigh = (int)buffer[2];
	int writeAddress = (int)buffer[3];
	int hours = 0;
	int minutes = 0;
	try {
		hours = int::Parse(((int)buffer[4]).ToString("X"));
		minutes = int::Parse(((int)buffer[5]).ToString("X"));
	} catch(Exception^) {
		Log("Horas/Minutos con formato inválido.");
	}
	Log(String::Format("Tiempo: {0:D2}:{1:D2}", hours, minutes));
	int addressTotal = addressLow + (addressHigh * 256);
	if(writeAddress == 168) {
		addressTotal += (int)Math::Pow(2, 16);
	} else if(writeAddress == 162) {
		addressTotal += (int)Math::Pow(2, 17);
	} else if(writeAddress == 170) {
		addressTotal += (int)Math::Pow(2, 16) + (int)Math::Pow(2, 17);
	}

	if(hours > 23) hours = 23;
	if(minutes > 45) minutes = 45;

	int shiftTime = (((hours * 60 + minutes) / 15) + 1) * 13;
	addressTotal = addressTotal - shiftTime;
	Log(String::Format("Direccion Total: {0:D} <{0:X4}>", addressTotal));

	int shiftDays = numDays * 24 * 4 * 13;
	int addressIni = addressTotal - shiftDays;

	int size = shiftDays + shiftTime;

	if(addressIni < 91 && addressIni >= 0) {
		addressIni = (int)Math::Pow(2, 18) - (91 - addressIni);
	}
	if(addressIni < 0) {
		addressIni = (int)Math::Pow(2, 18) - (91 + Math::Abs(addressIni));
	}
	Log(String::Format("Direccion Inicial: {0:D} <{0:X4}>", addressIni));
	Log(String::Format("Tamaño: {0:D} <{0:X4}>", size));
	
	String^ readAddressOut;
	if((addressIni > (int)Math::Pow(2, 17)) && ((addressIni - (int)Math::Pow(2, 17)) > (int)Math::Pow(2, 16))) {
		readAddressOut = "AB";
	} else if((addressIni > (int)Math::Pow(2, 17)) && ((addressIni - (int)Math::Pow(2, 17)) < (int)Math::Pow(2, 16))) {
		readAddressOut = "A3";
	} else if((addressIni < (int)Math::Pow(2, 17)) && (addressIni > (int)Math::Pow(2, 16))) {
		readAddressOut = "A9";
	} else {
		readAddressOut = "A1";
	}
	
	Process("Descargando consumo...");
	String^ command = String::Format("{0:X4}{1}{2:X4}", _byteswap_ushort((unsigned short) addressIni), readAddressOut, (unsigned short) size);
	Log(String::Format("Instrucción de Lectura 1: {0}", command));
	if(comm->Start()) {
		comm->WriteChars(HexToChar(command));
		ArrayList^ buffer = comm->Read(size);
		Log("Recibidos: [" + buffer->Count + "]");
		String^ download = endLine;
		for each(int byte in buffer) {
			download += String::Format("{0:X2}", byte) + "  ";
		}
		Log("Respuesta: " + download);
		this->CreateEnergyFiles(buffer);
	}
	End();
	Process("");
	return false;
}

void MeterController::End() {
	Form1^ form = (Form1^)mainForm;
	Process("Finalizando...");
	if(comm->Start()) {
		comm->Write("Z");
	}
	form->tsStatus->Text = "Finalizado.";
	Process("");
}