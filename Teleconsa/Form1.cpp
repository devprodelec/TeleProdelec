#include "StdAfx.h"
#include "AppSettings.h"
#include "Form1.h"

using namespace Teleconsa;

void Form1::Log(String^ message) {
	logTextBox->AppendText(message + "\n");
	System::Console::WriteLine(message);
}

void Form1::Process(String^ message) {
	tsProcessing->Text = message;
	Log(message);
}

void Form1::ReadSettings() {
	AppSettings^ settings = gcnew AppSettings;

	// Read from config file
	String^ ACCESS_TYPE = settings->Read("settings", "ACCESS_TYPE", "0");
	String^ PORT_NUMBER = settings->Read("settings", "PORT_NUMBER", "2");
	String^ BAUD_RATE = settings->Read("settings", "BAUD_RATE", "9600");
	String^ DATA_BITS = settings->Read("settings", "DATA_BITS", "8");
	String^ PARITY = settings->Read("settings", "PARITY", "Ninguna");
	String^ STOP_BITS = settings->Read("settings", "STOP_BITS", "1");
	String^ HAND_SHAKING = settings->Read("settings", "HAND_SHAKING", "XOnXOff");
	String^ USE_DTR = settings->Read("settings", "USE_DTR", "1");
	//String^ USE_RTS = settings->Read("settings", "USE_RTS", "1");
	String^ FOLDER_PATH = settings->Read("settings", "FOLDER_PATH", "C:\\Teleprodelec");

	if(int::Parse(ACCESS_TYPE) == 0) {
		rbEnSitio->Checked = true;
		gbLlamada->Enabled = false;
	} else {
		rbRemoto->Checked = true;
		gbLlamada->Enabled = true;
	}
	portNumber->Value = int::Parse(PORT_NUMBER);
	txtBaudRate->Text = BAUD_RATE;
	txtDataBits->Text = DATA_BITS;
	cbParity->Text = PARITY;
	cbStopBits->Text = STOP_BITS;
	cbHandShaking->Text = HAND_SHAKING;
	cbDTR->Checked = (int::Parse(USE_DTR) == 0);
	//cbRTS->Checked = (int::Parse(USE_RTS) == 0);
	labSavePath->Text = FOLDER_PATH;

	
	Log("ACCESS_TYPE: " + ACCESS_TYPE);
	Log("PORT_NUMBER: " + PORT_NUMBER);
	Log("BAUD_RATE: " + BAUD_RATE);
	Log("DATA_BITS: " + DATA_BITS);
	Log("PARITY: " + PARITY);
	Log("STOP_BITS: " + STOP_BITS);
	Log("HAND_SHAKING: " + HAND_SHAKING);
	Log("USE_DTR: " + USE_DTR);
	//Log("USE_RTS: " + USE_RTS);
	Log("FOLDER_PATH: " + FOLDER_PATH);
}

void Form1::UpdateSettings() {
	AppSettings^ settings = gcnew AppSettings;
	this->tabControl1->SelectedIndex = 0;

	// Save to config file
	settings->Write("settings", "ACCESS_TYPE", (rbEnSitio->Checked ? "0" : "1"));
	settings->Write("settings", "PORT_NUMBER", ""+portNumber->Value);
	settings->Write("settings", "BAUD_RATE", txtBaudRate->Text);
	settings->Write("settings", "DATA_BITS", txtDataBits->Text);
	settings->Write("settings", "PARITY", cbParity->Text);
	settings->Write("settings", "STOP_BITS", cbStopBits->Text);
	settings->Write("settings", "HAND_SHAKING", cbHandShaking->Text);
	settings->Write("settings", "USE_DTR", (cbDTR->Checked ? "0" : "1"));
	//settings->Write("settings", "USE_RTS", (cbRTS->Checked ? "0" : "1"));
	settings->Write("settings", "FOLDER_PATH", labSavePath->Text);
}

void Form1::SwitchConnectionType() {
	if(rbEnSitio->Checked) {
		gbLlamada->Enabled = false;
	} else {
		gbLlamada->Enabled = true;
	}
}

void Form1::GotoConfig() {
	tabControl1->SelectedIndex = 3;
}

void Form1::CheckMeters() {
	ArrayList^ serials = meter->Check();
	UpdateSerials(serials);
}

void Form1::UpdateSerials(ArrayList^ serials) {
	if(serials->Count == 5) {
		strMessage = String::Format("Serial 1: {0}\n", serials[0]);
		strMessage += String::Format("Serial 2: {0}\n", serials[1]);
		strMessage += String::Format("Serial 3: {0}\n", serials[2]);
		strMessage += String::Format("Serial 4: {0}\n", serials[3]);
		strMessage += String::Format("Serial 5: {0}\n", serials[4]);
		Log(strMessage);
		
		int i = 0;
		int available = 0;
		available += SetSerial(cbUma1, i, serials[i++]);
		available += SetSerial(cbUma2, i, serials[i++]);
		available += SetSerial(cbUma3, i, serials[i++]);
		available += SetSerial(cbUma4, i, serials[i++]);
		available += SetSerial(cbUma5, i, serials[i++]);
		tsStatus->Text = "Medidores disponibles: " + available;
	}
}

int Form1::SetSerial(CheckBox^ cb, int index, Object^ serial) {
	cb->Text = String::Format("Medidor {0}: {1}", index, ((int)serial != 0 ? serial : "N/A"));
	cb->Enabled = ((int)serial != 0);
	return (int)((int)serial != 0);
}

bool Form1::DownloadSelectedInfo() {
	if(!cbUma1->Checked && !cbUma2->Checked && !cbUma3->Checked && !cbUma4->Checked && !cbUma5->Checked) {
		strMessage = "Debe seleccionar al menos un medidor de la UMA para descargar";
		MessageBox::Show(strMessage, "ERROR 101", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	} else {
		if(DownloadBreaks()) {
			if(DownloadLoadProfile()) {
				this->tsStatus->Text = "Descarga finalizada.";
				return true;
			}
		}
	}
	this->tsStatus->Text = "Error en la descarga.";
	return false;
}

bool Form1::DownloadBreaks() {
	return meter->GetBreaks();
}

bool Form1::DownloadLoadProfile() {
	int numDays = 1;
	if(rbDays->Checked) {
		numDays = int::Parse(daysProfile->Text);
	}
	return meter->GetLoadProfile(numDays);
}

void Form1::EndMeterOperartions() {
	meter->End();
}

void Form1::RunTest() {
	/*this->tabControl1->SelectedIndex = 1;
	// Test code
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[0]->Points->AddXY(1,2);
	this->chart1->Series[0]->Points->AddXY(2,1);
	this->chart1->Series[0]->Points->AddXY(3,5);
	this->chart1->Series[0]->Points->AddXY(4,2);
	this->chart1->Series[0]->Points->AddXY(5,6);
	this->chart1->Series[1]->Points->AddXY(1,6);
	this->chart1->Series[1]->Points->AddXY(2,5);
	this->chart1->Series[1]->Points->AddXY(3,2);
	this->chart1->Series[1]->Points->AddXY(4,3);
	this->chart1->Series[1]->Points->AddXY(5,1);*/

	

	ArrayList^ rows = dbService->listarCrud();
	//DbService ^dbService = gcnew DbService();
	//dbService->insertar("l", "t","t", "e");//
}

void Form1::SelectFile() {
	openFileDialog1->InitialDirectory = this->labSavePath->Text;
	openFileDialog1->ShowDialog();
	chart->LoadFile(openFileDialog1->FileName);
	//labSavePath->Text = openFileDialog1->SelectedPath;
}

void Form1::FillUsersDataCrud()
{
	ArrayList^ dbRows = dbService->listarCrud();

	dataGridView2->Rows->Clear();
	
	for (int i=0;i<dbRows->Count;i++)
	{
		dataGridView2->Rows->Add((cli::array<String^, 1>^)dbRows[i]);
	}
}

void Form1::FillUsersDataConf()
{
	ArrayList^ dbRows = dbService->listarConf();

	dataGridView1->Rows->Clear();
	
	for (int i=0;i<dbRows->Count;i++)
	{
		dataGridView1->Rows->Add((cli::array<String^, 1>^)dbRows[i]);
	}
}

void Form1::FillDetailedTextWithIndex(int i)
{
	this->txtId->Text = String::Format("{0}",dataGridView2->Rows[i]->Cells[0]->Value);
	this->txtNombres->Text = String::Format("{0}",dataGridView2->Rows[i]->Cells[1]->Value);
	this->txtApellidos->Text = String::Format("{0}",dataGridView2->Rows[i]->Cells[2]->Value);
	this->txtNumero->Text = String::Format("{0}",dataGridView2->Rows[i]->Cells[3]->Value);
	this->txtExtension->Text = String::Format("{0}",dataGridView2->Rows[i]->Cells[4]->Value);
}

void Form1::ClearDetailedTextFields()
{
	this->txtId->Text = "";
	this->txtNombres->Text = "";
	this->txtApellidos->Text = "";
	this->txtNumero->Text = "";
	this->txtExtension->Text = "";
}

void Form1::ShowDetailedTextFields()
{
	groupBox10->Visible = true;
}
		
void Form1::HideDetailedTextFields()
{
	groupBox10->Visible = false;
}

void Form1::Save()
{
	//MessageBox::Show(String::Format("Value: {0}", txtId->Text->Empty("")));
	if (txtId->Text->Length == 0)
	{
		SaveNewUser();
	}
	else
	{
		SaveExistingUser();
	}
}

void Form1::SaveNewUser()
{
	dbService->insertar(this->txtNombres->Text,this->txtApellidos->Text,this->txtNumero->Text,this->txtExtension->Text);
	FillUsersDataCrud();
}
		
void Form1::SaveExistingUser()
{
	dbService->actualizar(int::Parse(this->txtId->Text),this->txtNombres->Text,this->txtApellidos->Text,this->txtNumero->Text,this->txtExtension->Text);
	FillUsersDataCrud();
}
		
void Form1::DeleteExistinUserAtIndex(int i)
{
	int id = int::Parse(String::Format("{0}", dataGridView2->Rows[i]->Cells[0]->Value));
	dbService->eliminar(id);
	FillUsersDataCrud();
}

void Form1::SetConfigurationTelefoneNumberAtIndex(int i)
{
	labClientName->Text = String::Format("{0}", dataGridView1->Rows[i]->Cells[1]->Value);
	txtPhoneNumber->Text = String::Format("{0}", dataGridView1->Rows[i]->Cells[2]->Value);
	txtPhoneExt->Text = String::Format("{0}", dataGridView1->Rows[i]->Cells[3]->Value);
}