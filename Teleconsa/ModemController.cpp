#include "StdAfx.h"
#include "AppSettings.h"
#include "ModemController.h"
#include "Form1.h"

using namespace Teleconsa;
using namespace System::Collections;
using namespace System::Windows::Forms;

ModemController::ModemController(Form^ form, PortCommunicator^ comm)
{
	this->mainForm = form;
	this->comm = comm;
	this->serialPort1 = gcnew SerialPort();
	this->currentMeter = 0;
}

ModemController::~ModemController(void)
{
}

void ModemController::Init(void)
{
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

void ModemController::Log(String^ message) {
	Form1^ form = (Form1^)mainForm;
	form->Log(message);
}

void ModemController::Process(String^ message) {
	Form1^ form = (Form1^)mainForm;
	form->Process(message);
}

bool ModemController::Connect() {
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

bool ModemController::Disconnect() {
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

String^ ModemController::WriteAndLogResponse(String^ message) {
	comm->WriteLine(message);
	ArrayList^ buffer = comm->Read();
	Log("Recibidos: [" + buffer->Count + "]");
	
	String^ download = "";
	for each(int byte in buffer) {
		download += String::Format("{0:X2} ", byte);
	}
	Log("Respuesta: " + endLine + download + endLine);
	return download;
}

void ModemController::SendCmd(String^ cmd) {
	Form1^ form = (Form1^)mainForm;
	if(comm->Start()) {
		Process(String::Format("Enviando: {0}", cmd));
		WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));
	}
	Process("");
}

bool ModemController::Reset() {
	Form1^ form = (Form1^)mainForm;
	Process("Reiniciando modem...");
	bool success = false;
	if(comm->Start()) {
		String ^cmd = "AT&F";
		Process(String::Format("Enviando: {0}", cmd));
		String ^response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));

		cmd = "AT+MS=V32";
		Process(String::Format("Enviando: {0}", cmd));
		response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));

		cmd = "ATS0=0Q0V0E0&D2&S0&K0";
		Process(String::Format("Enviando: {0}", cmd));
		response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));

		cmd = "AT&Y0&W0";
		Process(String::Format("Enviando: {0}", cmd));
		response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));
		
		if(success = response->StartsWith("30 0D")) {
			Log("Reset OK");
		} else {
			Log("Reset ERROR");
		}
	}
	Process("");
	return success;
}

String^ ModemController::Call(String^ phone, String^ ext) {
	Form1^ form = (Form1^)mainForm;
	String^ response = "";
	if(comm->Start()) {
		if(Reset()) {
			String ^cmd = String::Format("ATDT{0}{1}", phone, ext);
			Process(String::Format("Llamando: {0}", cmd));
			response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));

			if(response->StartsWith("31 32")) {
				Log("Llamada OK");
			} else {
				Log("Llamada ERROR");
			}
		}
	}
	Process("");
	return response;
}

bool ModemController::HangUp() {
	Form1^ form = (Form1^)mainForm;
	Process("Reiniciando modem...");
	bool success = false;
	if(comm->Start()) {
		String ^cmd = "+++";
		Process(String::Format("Enviando: {0}", cmd));
		String ^response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));

		Sleep(500);
		cmd = "ATH";
		Process(String::Format("Enviando: {0}", cmd));
		response = WriteAndLogResponse(String::Format("{0}{1}", cmd, cr));
		
		if(success = response->StartsWith("30 0D")) {
			Log("Colgado OK");
		} else {
			Log("Colgado ERROR");
		}
	}
	Process("");
	return success;
}