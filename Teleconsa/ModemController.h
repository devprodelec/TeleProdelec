#pragma once

#include "PortCommunicator.h"

using namespace System::IO;
using namespace System::IO::Ports;

ref class ModemController
{

public:
	ModemController(Form^ form, PortCommunicator^ comm);
	virtual ~ModemController(void);

	void Init();
	void Log(String^ message);
	void Process(String^ message);
	String^ WriteAndLogResponse(String^ message);
	
	bool Connect();
	bool Disconnect();
	bool Reset();
	void SendCmd(String^ cmd);
	String^ Call(String^ phone, String^ ext);
	bool HangUp();

	static String^ cr = "\r";
	static String^ endLine = "\r\n";

private:
	String^ strMessage;
	Form ^mainForm;
	SerialPort^ serialPort1;
	PortCommunicator^ comm;
	ArrayList^ serials;
	int currentMeter;
};
