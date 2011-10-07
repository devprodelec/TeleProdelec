#pragma once

#include "PortCommunicator.h"

using namespace System::IO;
using namespace System::IO::Ports;

ref class ModemController
{

public:
	ModemController(Form^ form);
	virtual ~ModemController(void);

	void Init();
	void Log(String^ message);
	void Process(String^ message);

private:
	String^ strMessage;
	Form ^mainForm;
	SerialPort^ serialPort1;
	PortCommunicator^ comm;
	ArrayList^ serials;
	int currentMeter;
};
