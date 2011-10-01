#pragma once

#include <Windows.h>
#include <vcclr.h>

using namespace System;
using namespace System::Collections;

ref class AppSettings
{

public:
	AppSettings(void);
	virtual ~AppSettings(void);

	bool Write(String^ section, String^ key, String^ value);
	String^ Read(String^ section, String^ key, String^ defValue);

private:
	String^ fileName;

};
