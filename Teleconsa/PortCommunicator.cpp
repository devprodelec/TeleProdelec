#include "StdAfx.h"
#include "Form1.h"
#include "PortCommunicator.h"

using namespace Teleconsa;

PortCommunicator::PortCommunicator(Form^ form) {
	this->mainForm = form;
	this->serialPort = gcnew SerialPort();
}

PortCommunicator::~PortCommunicator() {
}

bool PortCommunicator::Start()
{
	Form1^ form = (Form1^)mainForm;
	if(!this->serialPort->IsOpen) {
		form->Log("ERROR: El puerto esta cerrado");
		return false;
	}
	
    serialPort->ReadTimeout = 2000;
    serialPort->WriteTimeout = 2000;
	return true;
}

ArrayList^ PortCommunicator::Read() {
	Form1^ form = (Form1^)mainForm;
	buffer = gcnew ArrayList;
	_continue = true;
	int cant = 0;
	while (_continue)
    {
        try
        {
			int byte = serialPort->ReadByte();
			buffer->Add(byte);
			//MessageBox::Show(String::Format("Mensaje recibido ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
        }
        catch (TimeoutException^) 
		{
			form->tsProgressBar->Value = 0;
			//MessageBox::Show(String::Format("TIMEOUT recibiendo mensaje"), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			//MessageBox::Show(String::Format("Mensaje de error ({0}):", exc->ToString()), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Stop();
		}
    }
	return buffer;
}

ArrayList^ PortCommunicator::Read(int buffer_size) {
	Form1^ form = (Form1^)mainForm;
	this->progress = form->tsProgressBar;
	this->buffer_size = buffer_size; 
	this->progress->Maximum = buffer_size-1;
	
	this->buffer = gcnew ArrayList;
	ReadBytes();
	/*
	PortCommunicator^ pc = gcnew PortCommunicator(form);
	pc->progress = form->tsProgressBar;
	pc->buffer = this->buffer;
	pc->buffer_size = buffer_size;
    _readThread = gcnew Thread(gcnew ThreadStart(pc, &PortCommunicator::ReadBytes));
    _readThread->Start();
	_readThread->Join();
	*/
	return this->buffer;
}

void PortCommunicator::ReadBytes() {
	_continue = true;
	int cant = 0;
	while (_continue)
    {
        try
        {
			if(cant < buffer_size) {
				int byte = serialPort->ReadByte();
				buffer->Add(byte);
				progress->Value = cant++;
			} else {
				Stop();
			}
			//MessageBox::Show(String::Format("Mensaje recibido ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
        }
        catch (TimeoutException^) 
		{
			progress->Value = 0;
			//MessageBox::Show(String::Format("TIMEOUT recibiendo mensaje"), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			//MessageBox::Show(String::Format("Mensaje de error ({0}):", exc->ToString()), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Stop();
		}
    }
}

void PortCommunicator::Write(String^ message)
{
	try
	{
		serialPort->Write(message);
		//MessageBox::Show(String::Format("Mensaje enviado ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	catch (Exception^ exc)
	{
		MessageBox::Show(String::Format("ERROR enviando mensaje ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		MessageBox::Show(String::Format("Mensaje de error ({0}):", exc->ToString()), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		Stop();
	}
}

void PortCommunicator::WriteChars(array<unsigned char>^ message)
{
	try
	{
		serialPort->Write(message, 0, message->Length);
		//MessageBox::Show(String::Format("Mensaje enviado ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	catch (Exception^ exc)
	{
		MessageBox::Show(String::Format("ERROR enviando mensaje ({0}):", message), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		MessageBox::Show(String::Format("Mensaje de error ({0}):", exc->ToString()), "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		Stop();
	}
}

void PortCommunicator::Stop()
{
	_continue = false;
	//if(_readThread != nullptr) _readThread->Join();
}