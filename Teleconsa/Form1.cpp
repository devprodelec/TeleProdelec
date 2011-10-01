#include "StdAfx.h"
#include "AppSettings.h"
#include "Form1.h"

using namespace Teleconsa;

void Form1::Log(String^ message) {
	logTextBox->AppendText(message + "\n");
	System::Console::WriteLine(message);
}

void Form1::Process(String^ message) {
	tsProcessing->Text = message;
	Log(message);
}

void Form1::ReadSettings() {
	AppSettings^ settings = gcnew AppSettings;

	// Read from config file
	String^ ACCESS_TYPE = settings->Read("settings", "ACCESS_TYPE", "0");
	String^ PORT_NUMBER = settings->Read("settings", "PORT_NUMBER", "2");
	String^ BAUD_RATE = settings->Read("settings", "BAUD_RATE", "9800");
	String^ DATA_BITS = settings->Read("settings", "DATA_BITS", "8");
	String^ PARITY = settings->Read("settings", "PARITY", "Ninguna");
	String^ STOP_BITS = settings->Read("settings", "STOP_BITS", "1");
	String^ FOLDER_PATH = settings->Read("settings", "FOLDER_PATH", "C:\\Teleprodelec");
	
	if(int::Parse(ACCESS_TYPE) == 0) {
		rbEnSitio->Checked = true;
	} else {
		rbRemoto->Checked = true;
	}
	portNumber->Value = int::Parse(PORT_NUMBER);
	txtBaudRate->Text = BAUD_RATE;
	txtDataBits->Text = DATA_BITS;
	cbParity->Text = PARITY;
	cbStopBits->Text = STOP_BITS;
	labSavePath->Text = FOLDER_PATH;
	
	Log("ACCESS_TYPE: " + ACCESS_TYPE);
	Log("PORT_NUMBER: " + PORT_NUMBER);
	Log("BAUD_RATE: " + BAUD_RATE);
	Log("DATA_BITS: " + DATA_BITS);
	Log("PARITY: " + PARITY);
	Log("STOP_BITS: " + STOP_BITS);
	Log("FOLDER_PATH: " + FOLDER_PATH);
}

void Form1::UpdateSettings() {
	AppSettings^ settings = gcnew AppSettings;
	this->labType->Text = "Tipo: " + (this->rbEnSitio->Checked ? "En sitio" : "Remoto");
	this->labCOM->Text = "Puerto COM: " + this->portNumber->Text;
	if(this->rbRemoto->Checked) {
		this->labPhone->Text = "Teléfono: " + this->txtPhoneNumber->Text;
		this->labExt->Text = "Ext: " + this->txtPhoneExt->Text;
		this->labPhone->Enabled = true;
		this->labExt->Enabled = true;
	} else {
		this->labPhone->Text = "Teléfono: ";
		this->labExt->Text = "Ext: ";
		this->labPhone->Enabled = false;
		this->labExt->Enabled = false;
	}
	this->tabControl1->SelectedIndex = 0;

	// Save to config file
	settings->Write("settings", "ACCESS_TYPE", (rbEnSitio->Checked ? "0" : "1"));
	settings->Write("settings", "PORT_NUMBER", ""+portNumber->Value);
	settings->Write("settings", "BAUD_RATE", txtBaudRate->Text);
	settings->Write("settings", "DATA_BITS", txtDataBits->Text);
	settings->Write("settings", "PARITY", cbParity->Text);
	settings->Write("settings", "STOP_BITS", cbStopBits->Text);
	settings->Write("settings", "FOLDER_PATH", labSavePath->Text);
}

void Form1::CheckMeters() {
	ArrayList^ serials = meter->Check();
	UpdateSerials(serials);
}

void Form1::UpdateSerials(ArrayList^ serials) {
	if(serials->Count == 5) {
		strMessage = String::Format("Serial 1: {0}\n", serials[0]);
		strMessage += String::Format("Serial 2: {0}\n", serials[1]);
		strMessage += String::Format("Serial 3: {0}\n", serials[2]);
		strMessage += String::Format("Serial 4: {0}\n", serials[3]);
		strMessage += String::Format("Serial 5: {0}\n", serials[4]);
		Log(strMessage);
		
		int i = 0;
		int available = 0;
		available += SetSerial(cbUma1, i, serials[i++]);
		available += SetSerial(cbUma2, i, serials[i++]);
		available += SetSerial(cbUma3, i, serials[i++]);
		available += SetSerial(cbUma4, i, serials[i++]);
		available += SetSerial(cbUma5, i, serials[i++]);
		tsStatus->Text = "Medidores disponibles: " + available;
	}
}

int Form1::SetSerial(CheckBox^ cb, int index, Object^ serial) {
	cb->Text = String::Format("Medidor {0}: {1}", index, ((int)serial != 0 ? serial : "N/A"));
	cb->Enabled = ((int)serial != 0);
	return (int)((int)serial != 0);
}

bool Form1::DownloadSelectedInfo() {
	if(!cbUma1->Checked && !cbUma2->Checked && !cbUma3->Checked && !cbUma4->Checked && !cbUma5->Checked) {
		strMessage = "Debe seleccionar al menos un medidor de la UMA para descargar";
		MessageBox::Show(strMessage, "ERROR 101", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	} else {
		if(DownloadBreaks()) {
			if(DownloadLoadProfile()) {
				this->tsStatus->Text = "Descarga finalizada.";
				return true;
			}
		}
	}
	this->tsStatus->Text = "Error en la descarga.";
	return false;
}

bool Form1::DownloadBreaks() {
	return meter->GetBreaks();
}

bool Form1::DownloadLoadProfile() {
	int numDays = 1;
	if(rbDays->Checked) {
		numDays = int::Parse(daysProfile->Text);
	}
	return meter->GetLoadProfile(numDays);
}

void Form1::EndMeterOperartions() {
	meter->End();
}

void Form1::RunTest() {
	/*this->tabControl1->SelectedIndex = 1;
	// Test code
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[0]->Points->AddXY(1,2);
	this->chart1->Series[0]->Points->AddXY(2,1);
	this->chart1->Series[0]->Points->AddXY(3,5);
	this->chart1->Series[0]->Points->AddXY(4,2);
	this->chart1->Series[0]->Points->AddXY(5,6);
	this->chart1->Series[1]->Points->AddXY(1,6);
	this->chart1->Series[1]->Points->AddXY(2,5);
	this->chart1->Series[1]->Points->AddXY(3,2);
	this->chart1->Series[1]->Points->AddXY(4,3);
	this->chart1->Series[1]->Points->AddXY(5,1);*/

	

	ArrayList^ rows = dbService->listar();
	//DbService ^dbService = gcnew DbService();
	//dbService->insertar("l", "t","t", "e");//
}

void Form1::SelectFile() {
	openFileDialog1->InitialDirectory = this->labSavePath->Text;
	openFileDialog1->ShowDialog();
	chart->LoadFile(openFileDialog1->FileName);
	//labSavePath->Text = openFileDialog1->SelectedPath;
}

void Form1::FillUsersData()
{
	ArrayList^ dbRows = dbService->listar();

	dataGridView2->Rows->Clear();
	
	MessageBox::Show(String::Format("{0}", dbRows->Count));

	for (int i=0;i<dbRows->Count;i++)
	{
		dataGridView2->Rows->Add((cli::array<String^, 1>^)dbRows[i]);
	}
}