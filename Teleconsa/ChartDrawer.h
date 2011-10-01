#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace DataVisualization::Charting;

ref class ChartDrawer
{
public:
	ChartDrawer(Form^ form);
	virtual ~ChartDrawer(void);

	void Log(String^ message);
	DateTime GetDate(String^ date);
	void LoadFile(String^ filePath);

	void ParseFile();
	void Draw();
	void DrawHourly();
	void DrawMonth();
	void CalcHourly();
	void CalcMonth();

	static String^ endLine = "\r\n";
	
private:
	int selectedChart;
	String^ strMessage;
	String^ fileContent;
	ArrayList^ dates;
	ArrayList^ months;
	ArrayList^ actives;
	ArrayList^ reactives;
	ArrayList^ sumActives;
	ArrayList^ sumReactives;
	Form ^mainForm;
};
