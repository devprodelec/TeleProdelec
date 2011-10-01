#pragma once

#using <System.dll>

using namespace System;
using namespace System::Collections;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Windows::Forms;

ref class PortCommunicator
{

public:

	PortCommunicator(Form^ form);
	virtual ~PortCommunicator();

	bool Start();
	void Stop();
	ArrayList^ Read();
	ArrayList^ Read(int buffer_size);
	void ReadBytes();
	void Write(String^ message);
	void WriteChars(array<unsigned char>^ message);

	static SerialPort^ serialPort;
	ArrayList^ buffer;
	int buffer_size;

private:
	
	Form ^mainForm;
    static bool _continue;
	static Thread^ _readThread;
	ToolStripProgressBar^ progress;

};
