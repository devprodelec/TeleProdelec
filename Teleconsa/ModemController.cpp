#include "StdAfx.h"
#include "AppSettings.h"
#include "ModemController.h"
#include "Form1.h"

using namespace Teleconsa;
using namespace System::Collections;
using namespace System::Windows::Forms;

ModemController::ModemController(Form^ form)
{
	this->mainForm = form;
	this->comm = gcnew PortCommunicator(form);
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