#include "StdAfx.h"
#include "AppSettings.h"

AppSettings::AppSettings(void) {
	fileName = "config.ini";
}

AppSettings::~AppSettings(void) {
}

bool AppSettings::Write(String^ section, String^ key, String^ value) {
	pin_ptr<const wchar_t> wSection = PtrToStringChars(section);
	pin_ptr<const wchar_t> wKey = PtrToStringChars(key);
	pin_ptr<const wchar_t> wValue = PtrToStringChars(value);
	pin_ptr<const wchar_t> wFileName = PtrToStringChars(fileName);
	return WritePrivateProfileString(wSection, wKey, wValue, wFileName);
}

String^ AppSettings::Read(String^ section, String^ key, String^ defValue) {
	pin_ptr<const wchar_t> wSection = PtrToStringChars(section);
	pin_ptr<const wchar_t> wKey = PtrToStringChars(key);
	pin_ptr<const wchar_t> wDefValue = PtrToStringChars(defValue);
	pin_ptr<const wchar_t> wFileName = PtrToStringChars(fileName);
	TCHAR outValue[255]; 
	GetPrivateProfileString(wSection, wKey, wDefValue, outValue, 255, wFileName);
	return gcnew String(outValue);
}
