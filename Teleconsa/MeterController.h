#pragma once

#include "PortCommunicator.h"

using namespace System::IO;
using namespace System::IO::Ports;

ref class MeterController
{

public:
	MeterController(Form^ form);
	virtual ~MeterController(void);

	void Init();
	void Log(String^ message);
	void Process(String^ message);

	String^ UIntToChar(unsigned int value);
	array<unsigned char>^ ConvertArray(ArrayList^ buffer);
	float ConvertToFloat(ArrayList^ buffer, int index);

	array<unsigned char>^ HexToChar(String^ hexString);
	void CreateBreaksFile(ArrayList^ buffer);
	void CreateEnergyFiles(ArrayList^ buffer);
	void SaveFile(String^ fileName, String^ extension, String^ text);
	
	DateTime GetDate6(ArrayList^ buffer, int i);
	DateTime GetDate5(ArrayList^ buffer, int i);
	String^ GetStrDate(DateTime datetime);
	String^ GetBreakTime(DateTime datetime1, DateTime datetime2);

	bool Connect();
	bool Disconnect();
	ArrayList^ Check();
	bool GetBreaks();
	bool GetLoadProfile(int numDays);
	bool DownloadData(ArrayList^ buffer, int numDays);
	void End();
	
	static String^ endLine = "\r\n";
	static int energyFrameSize = 13;

private:
	String^ strMessage;
	Form ^mainForm;
	PortCommunicator^ comm;
	ArrayList^ serials;
	int currentMeter;

};
