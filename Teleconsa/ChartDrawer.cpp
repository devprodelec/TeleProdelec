#include "StdAfx.h"
#include "ChartDrawer.h"
#include "Form1.h"

using namespace Teleconsa;


ChartDrawer::ChartDrawer(Form^ form) {
	this->mainForm = form;
	selectedChart = 0;
}

ChartDrawer::~ChartDrawer(void) {
}

void ChartDrawer::Log(String^ message) {
	Form1^ form = (Form1^)mainForm;
	form->Log(message);
}

DateTime ChartDrawer::GetDate(String^ date) {
	int yyyy = int::Parse(date->Substring(0,4));
	int mm = int::Parse(date->Substring(5,2));
	int dd = int::Parse(date->Substring(8,2));
	return DateTime(yyyy, mm, dd);
}

void ChartDrawer::LoadFile(String^ filePath) {
	Log("Selected File: " + filePath);
	FileInfo ^file = gcnew FileInfo(filePath);
	FileStream^ fs = File::OpenRead(filePath);
	fileContent = "";
	try {
		array<Byte>^b = gcnew array<Byte>(1024);
		UTF8Encoding^ temp = gcnew UTF8Encoding(true);
		while(fs->Read(b, 0, b->Length) > 0) {
			fileContent += temp->GetString(b);
			b->Clear(b, 0, b->Length);
		}
    } finally {
		if(fs) delete (IDisposable^)fs;
    }
	Log("File loaded.");
}

void ChartDrawer::ParseFile() {
	Form1^ form = (Form1^)mainForm;
	if(!fileContent->IsNullOrEmpty(fileContent)) {
		form->cbFechaChart->Items->Clear();
		dates = gcnew ArrayList;
		actives = gcnew ArrayList;
		reactives = gcnew ArrayList;
		array<String^>^ lines = fileContent->Split('\n');
		for(int i=0; i<lines->Length-1; i++) {
			array<String^>^ cols = lines[i]->Split(';');
			int row = 0;
			DateTime date = GetDate(cols[0]);
			if(dates->Contains(date)) {
				row = dates->IndexOf(date);
			} else {
				row = dates->Count;
				dates->Add(date);
			}
			array<float> ^activesDay = gcnew array<float>(24);
			array<float> ^reactivesDay = gcnew array<float>(24);
			if(cols[3]->Equals("kVarhD")) {
				for(int k=0; k<24; k++) {
					activesDay[k] = float::Parse(cols[k+4]);
				}
				actives->Add(activesDay);
			} else if(cols[3]->Equals("kWhD")) {
				for(int k=0; k<24; k++) {
					reactivesDay[k] = float::Parse(cols[k+4]);
				}
				reactives->Add(reactivesDay);
			}
		}
	}
}

void ChartDrawer::Draw() {
	if(selectedChart == 1) {
		this->DrawHourly();
	} else if(selectedChart == 2) {
		this->DrawMonth();
	}
}

void ChartDrawer::DrawHourly() {
	Form1^ form = (Form1^)mainForm;
	String ^dateStr = form->cbFechaChart->Text;
	DateTime date = GetDate(dateStr);
	int row = dates->IndexOf(date);
	Log(String::Format("{0}", row));
	array<float> ^activesDay = (array<float>^) actives[row];
	array<float> ^reactivesDay = (array<float>^) reactives[row];
	form->chart1->Series[0]->Points->Clear();
	form->chart1->Series[1]->Points->Clear();
	for(int i=0; i<24; i++) {
		Log(String::Format("{0:R}, {1:R}", activesDay[i], reactivesDay[i]));
		form->chart1->Series[0]->Points->AddXY(i,activesDay[i]);
		form->chart1->Series[1]->Points->AddXY(i,reactivesDay[i]);
	}
}

void ChartDrawer::CalcHourly() {
	selectedChart = 1;
	Form1^ form = (Form1^)mainForm;
	// Fill day list
	form->cbFechaChart->Text = "";
	form->cbFechaChart->Items->Clear();
	bool first = true;
	for(int i=0; i<dates->Count; i++) {
		DateTime datetime = (DateTime) dates[i];
		form->cbFechaChart->Items->Add(datetime.ToString("yyyy/MM/dd"));
		if(first) {
			form->cbFechaChart->Text = datetime.ToString("yyyy/MM/dd");
			first = false;
		}
	}
}

void ChartDrawer::CalcMonth() {
	selectedChart = 2;
	Form1^ form = (Form1^)mainForm;
	months = gcnew ArrayList;
	sumActives = gcnew ArrayList;
	sumReactives = gcnew ArrayList;
	for(int i=0; i<dates->Count; i++) {
		DateTime datetime = (DateTime) dates[i];
		String ^month = datetime.Year + "/" + String::Format("{0:D2}", datetime.Month);
		int row = 0;
		if(months->Contains(month)) {
			row = months->IndexOf(month);
		} else {
			row = months->Count;
			months->Add(month);
			array<float> ^activesDay = gcnew array<float>(31);
			array<float> ^reactivesDay = gcnew array<float>(31);
			for(int k=0; k<31; k++) {
				activesDay[k] = 0;
				reactivesDay[k] = 0;
			}
			sumActives->Add(activesDay);
			sumReactives->Add(reactivesDay);
		}
		array<float> ^activesHour = (array<float>^) actives[i];
		array<float> ^reactivesHour = (array<float>^) reactives[i];
		array<float> ^activesDay = (array<float>^) sumActives[row];
		array<float> ^reactivesDay = (array<float>^) sumReactives[row];
		for(int k=0; k<24; k++) {
			activesDay[datetime.Day] += activesHour[k];
			reactivesDay[datetime.Day] += reactivesHour[k];
		}
	}
	// Fill month list
	form->cbFechaChart->Text = "";
	form->cbFechaChart->Items->Clear();
	bool first = true;
	for(int i=0; i<months->Count; i++) {
		String^ month = (String^) months[i];
		form->cbFechaChart->Items->Add(month);
		if(first) {
			form->cbFechaChart->Text = month;
			first = false;
		}
	}
}

void ChartDrawer::DrawMonth() {
	Form1^ form = (Form1^)mainForm;
	String ^dateStr = form->cbFechaChart->Text;
	int row = months->IndexOf(dateStr);
	Log(String::Format("{0}", row));
	array<float> ^activesDay = (array<float>^) sumActives[row];
	array<float> ^reactivesDay = (array<float>^) sumReactives[row];
	form->chart1->Series[0]->Points->Clear();
	form->chart1->Series[1]->Points->Clear();
	for(int i=0; i<31; i++) {
		Log(String::Format("{0:R}, {1:R}", activesDay[i], reactivesDay[i]));
		form->chart1->Series[0]->Points->AddXY(i,activesDay[i]);
		form->chart1->Series[1]->Points->AddXY(i,reactivesDay[i]);
	}
}