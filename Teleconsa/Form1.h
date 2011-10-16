#pragma once

#include "MeterController.h"
#include "ModemController.h"
#include "ChartDrawer.h"
#include "DbService.h"

namespace Teleconsa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace DataVisualization::Charting;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			InitializeTeleconsa();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	public: System::Windows::Forms::ToolStripStatusLabel^  tsStatus;
	public: System::Windows::Forms::ToolStripProgressBar^  tsProgressBar;
	private: DbService ^dbService;


	protected: 
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStripMenuItem^  herramientasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  opcionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  acercaDeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabConexion;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: System::Windows::Forms::Button^  btnDisconnect;
	private: 

	private: 

	private: 




	public: System::Windows::Forms::Button^  btnConnect;
	private: 


	public: 
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::NumericUpDown^  daysProfile;
	private: System::Windows::Forms::RadioButton^  rbDays;
	private: System::Windows::Forms::RadioButton^  rbComplete;


	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::CheckBox^  cbUma5;
	private: System::Windows::Forms::CheckBox^  cbUma4;
	private: System::Windows::Forms::CheckBox^  cbUma3;
	private: System::Windows::Forms::Button^  btnQueryMeters;

	private: System::Windows::Forms::CheckBox^  cbUma2;
	private: System::Windows::Forms::CheckBox^  cbUma1;
	private: System::Windows::Forms::TabPage^  tabClientes;
	private: System::Windows::Forms::TabPage^  tabLog;




	private: System::Windows::Forms::Button^  button7;

	private: System::Windows::Forms::RichTextBox^  logTextBox;
	private: System::Windows::Forms::TabPage^  tabConfig;



private: 


public: System::Windows::Forms::ComboBox^  cbStopBits;
public: System::Windows::Forms::ComboBox^  cbParity;

public: System::Windows::Forms::RadioButton^  rbOtro;
public: System::Windows::Forms::RadioButton^  rbCnet;
public: System::Windows::Forms::RadioButton^  rbTrend;
public: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Label^  label5;
public: 
private: System::Windows::Forms::Label^  label4;
public: System::Windows::Forms::TextBox^  txtDataBits;
private: 
private: System::Windows::Forms::Label^  label8;
public: 
private: System::Windows::Forms::Label^  label9;
public: System::Windows::Forms::TextBox^  txtBaudRate;





public: 
private: 

public: 



private: System::Windows::Forms::GroupBox^  groupBox4;
public: 

private: System::Windows::Forms::GroupBox^  groupBox5;




private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
private: System::Windows::Forms::ToolStripStatusLabel^  tsProcessing;

private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Button^  button5;
public: System::Windows::Forms::Label^  labSavePath;
private: 

private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;









private: System::Windows::Forms::TabPage^  tabReportes;
public: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
private: 
public: 

public: 




private: System::Windows::Forms::Button^  button8;
public: 
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Button^  button14;
public: System::Windows::Forms::Label^  label1;
public: System::Windows::Forms::ComboBox^  cbFechaChart;
private: System::Windows::Forms::BindingSource^  bindingSource1;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::DataGridView^  dataGridView2;
public: System::Windows::Forms::Button^  btnEditar;
private: 



public: System::Windows::Forms::Button^  btnNuevo;
private: 

private: System::Windows::Forms::Label^  label6;
public: System::Windows::Forms::TextBox^  txtApellidos;
public: System::Windows::Forms::Button^  btnGuardar;
private: 
public: 

private: 

public: System::Windows::Forms::TextBox^  txtExtension;


private: System::Windows::Forms::Label^  label3;
public: System::Windows::Forms::TextBox^  txtNumero;
private: 
public: 

private: 
private: System::Windows::Forms::Label^  label2;
public: System::Windows::Forms::TextBox^  txtNombres;
public: System::Windows::Forms::Button^  btnEliminar;
private: 
public: 



public: 



private: System::Windows::Forms::Label^  label11; 
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Apellidos;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Extension;
private: System::Windows::Forms::Label^  label12;
public: System::Windows::Forms::TextBox^  txtId;

public: 




private: System::Windows::Forms::TabControl^  tabControl2;
private: System::Windows::Forms::TabPage^  tabPage6;
public: System::Windows::Forms::RichTextBox^  txtBreaks;
private: 
private: System::Windows::Forms::TabPage^  tabPage7;
public: 
public: System::Windows::Forms::RichTextBox^  txtConsumo;
private: 
private: System::Windows::Forms::TabPage^  tabPage1;
public: 
public: System::Windows::Forms::RichTextBox^  txtTotales;
private: 
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::GroupBox^  gbLlamada;







private: System::Windows::Forms::Label^  label13;
public: System::Windows::Forms::TextBox^  txtPhoneExt;
private: 
private: System::Windows::Forms::Label^  label10;
public: 
public: System::Windows::Forms::TextBox^  txtPhoneNumber;
private: System::Windows::Forms::Button^  btnHangUp;
public: 

public: 
private: 

private: System::Windows::Forms::Button^  btnCall;
public: 

private: System::Windows::Forms::Label^  label14;
public: System::Windows::Forms::Button^  button15;
private: 

public: System::Windows::Forms::Button^  button19;
public: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::ProgressBar^  progressBar1;
private: System::Windows::Forms::DataGridView^  dataGridView1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  tblConfId;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  tblConfExtension;
private: System::Windows::Forms::Label^  labClientName;
public: System::Windows::Forms::NumericUpDown^  portNumber;
private: 
public: System::Windows::Forms::Label^  label7;
public: System::Windows::Forms::RadioButton^  rbEnSitio;
public: System::Windows::Forms::RadioButton^  rbRemoto;
public: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Label^  label15;
public: System::Windows::Forms::TextBox^  txtCmd;
private: 
public: System::Windows::Forms::Button^  btnSendCmd;
public: System::Windows::Forms::ComboBox^  cbHandShaking;

private: System::Windows::Forms::Label^  label16;
public: System::Windows::Forms::CheckBox^  cbRTS;
private: 

private: System::Windows::Forms::Label^  label18;
public: System::Windows::Forms::CheckBox^  cbDTR;
private: 


private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TabControl^  tabControl3;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::TabPage^  tabTable;
private: System::Windows::Forms::TabPage^  tabContEnerg;
private: System::Windows::Forms::DataGridView^  dataGridView3;
public: 


public: 

private: 
private: 
public: 

public: 

public: 

public: 





public: 


public: 

public: 


public: System::Windows::Forms::Button^  btnCancel;

private: 

private: 


private: 
private: 
	public: 

	private: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tsStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsProcessing = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->herramientasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opcionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabConexion = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->gbLlamada = (gcnew System::Windows::Forms::GroupBox());
			this->labClientName = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tblConfId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tblConfExtension = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtPhoneExt = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->btnHangUp = (gcnew System::Windows::Forms::Button());
			this->btnCall = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->portNumber = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->rbEnSitio = (gcnew System::Windows::Forms::RadioButton());
			this->rbRemoto = (gcnew System::Windows::Forms::RadioButton());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->daysProfile = (gcnew System::Windows::Forms::NumericUpDown());
			this->rbDays = (gcnew System::Windows::Forms::RadioButton());
			this->rbComplete = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cbUma5 = (gcnew System::Windows::Forms::CheckBox());
			this->cbUma4 = (gcnew System::Windows::Forms::CheckBox());
			this->cbUma3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbUma2 = (gcnew System::Windows::Forms::CheckBox());
			this->btnQueryMeters = (gcnew System::Windows::Forms::Button());
			this->cbUma1 = (gcnew System::Windows::Forms::CheckBox());
			this->tabReportes = (gcnew System::Windows::Forms::TabPage());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbFechaChart = (gcnew System::Windows::Forms::ComboBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabClientes = (gcnew System::Windows::Forms::TabPage());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Apellidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Extension = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->txtExtension = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNumero = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			this->tabConfig = (gcnew System::Windows::Forms::TabPage());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->labSavePath = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->rbTrend = (gcnew System::Windows::Forms::RadioButton());
			this->rbCnet = (gcnew System::Windows::Forms::RadioButton());
			this->rbOtro = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->cbRTS = (gcnew System::Windows::Forms::CheckBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->cbDTR = (gcnew System::Windows::Forms::CheckBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->cbHandShaking = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->cbStopBits = (gcnew System::Windows::Forms::ComboBox());
			this->cbParity = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBaudRate = (gcnew System::Windows::Forms::TextBox());
			this->txtDataBits = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->tabLog = (gcnew System::Windows::Forms::TabPage());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->txtBreaks = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->txtConsumo = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->txtTotales = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtCmd = (gcnew System::Windows::Forms::TextBox());
			this->btnSendCmd = (gcnew System::Windows::Forms::Button());
			this->logTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabContEnerg = (gcnew System::Windows::Forms::TabPage());
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabTable = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabConexion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->gbLlamada->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->portNumber))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->daysProfile))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tabReportes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->tabClientes->SuspendLayout();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->groupBox10->SuspendLayout();
			this->tabConfig->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabLog->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingSource1))->BeginInit();
			this->tabControl3->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabTable->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->tsStatus, this->tsProcessing, 
				this->tsProgressBar});
			this->statusStrip1->Location = System::Drawing::Point(0, 605);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(782, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tsStatus
			// 
			this->tsStatus->AutoSize = false;
			this->tsStatus->Name = L"tsStatus";
			this->tsStatus->Size = System::Drawing::Size(400, 17);
			this->tsStatus->Text = L"Listo";
			this->tsStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tsProcessing
			// 
			this->tsProcessing->AutoSize = false;
			this->tsProcessing->Name = L"tsProcessing";
			this->tsProcessing->Size = System::Drawing::Size(200, 17);
			this->tsProcessing->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tsProgressBar
			// 
			this->tsProgressBar->AutoSize = false;
			this->tsProgressBar->Name = L"tsProgressBar";
			this->tsProgressBar->Size = System::Drawing::Size(178, 16);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->archivoToolStripMenuItem, 
				this->herramientasToolStripMenuItem, this->ayudaToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(782, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->salirToolStripMenuItem});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(96, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::salirToolStripMenuItem_Click);
			// 
			// herramientasToolStripMenuItem
			// 
			this->herramientasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->opcionesToolStripMenuItem});
			this->herramientasToolStripMenuItem->Name = L"herramientasToolStripMenuItem";
			this->herramientasToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->herramientasToolStripMenuItem->Text = L"Herramientas";
			// 
			// opcionesToolStripMenuItem
			// 
			this->opcionesToolStripMenuItem->Name = L"opcionesToolStripMenuItem";
			this->opcionesToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->opcionesToolStripMenuItem->Text = L"Configuraci�n";
			this->opcionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::opcionesToolStripMenuItem_Click);
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->acercaDeToolStripMenuItem});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			this->acercaDeToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->acercaDeToolStripMenuItem->Text = L"Acerca de Teleconsa";
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->tabControl1);
			this->panel1->Location = System::Drawing::Point(-1, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(784, 582);
			this->panel1->TabIndex = 3;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabConexion);
			this->tabControl1->Controls->Add(this->tabConfig);
			this->tabControl1->Controls->Add(this->tabClientes);
			this->tabControl1->Controls->Add(this->tabReportes);
			this->tabControl1->Controls->Add(this->tabContEnerg);
			this->tabControl1->Controls->Add(this->tabLog);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(12, 125);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(760, 440);
			this->tabControl1->TabIndex = 1;
			// 
			// tabConexion
			// 
			this->tabConexion->Controls->Add(this->pictureBox1);
			this->tabConexion->Controls->Add(this->gbLlamada);
			this->tabConexion->Controls->Add(this->groupBox1);
			this->tabConexion->Controls->Add(this->groupBox7);
			this->tabConexion->Controls->Add(this->groupBox2);
			this->tabConexion->Location = System::Drawing::Point(4, 26);
			this->tabConexion->Name = L"tabConexion";
			this->tabConexion->Padding = System::Windows::Forms::Padding(3);
			this->tabConexion->Size = System::Drawing::Size(752, 410);
			this->tabConexion->TabIndex = 0;
			this->tabConexion->Text = L"Conexi�n";
			this->tabConexion->UseVisualStyleBackColor = true;
			this->tabConexion->Enter += gcnew System::EventHandler(this, &Form1::tabConexion_Enter);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(644, 286);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(87, 100);
			this->pictureBox1->TabIndex = 40;
			this->pictureBox1->TabStop = false;
			// 
			// gbLlamada
			// 
			this->gbLlamada->Controls->Add(this->labClientName);
			this->gbLlamada->Controls->Add(this->dataGridView1);
			this->gbLlamada->Controls->Add(this->label13);
			this->gbLlamada->Controls->Add(this->txtPhoneExt);
			this->gbLlamada->Controls->Add(this->label10);
			this->gbLlamada->Controls->Add(this->txtPhoneNumber);
			this->gbLlamada->Controls->Add(this->btnHangUp);
			this->gbLlamada->Controls->Add(this->btnCall);
			this->gbLlamada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gbLlamada->Location = System::Drawing::Point(266, 6);
			this->gbLlamada->Name = L"gbLlamada";
			this->gbLlamada->Size = System::Drawing::Size(480, 220);
			this->gbLlamada->TabIndex = 39;
			this->gbLlamada->TabStop = false;
			this->gbLlamada->Text = L"Llamada";
			// 
			// labClientName
			// 
			this->labClientName->AutoSize = true;
			this->labClientName->ForeColor = System::Drawing::Color::Gray;
			this->labClientName->Location = System::Drawing::Point(16, 28);
			this->labClientName->Name = L"labClientName";
			this->labClientName->Size = System::Drawing::Size(137, 17);
			this->labClientName->TabIndex = 23;
			this->labClientName->Text = L"Seleccione un cliente...";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->tblConfId, 
				this->Column1, this->Column2, this->tblConfExtension});
			this->dataGridView1->Location = System::Drawing::Point(195, 27);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->Size = System::Drawing::Size(270, 174);
			this->dataGridView1->TabIndex = 22;
			this->dataGridView1->DoubleClick += gcnew System::EventHandler(this, &Form1::dataGridView1_DoubleClick);
			// 
			// tblConfId
			// 
			this->tblConfId->HeaderText = L"tblConfId";
			this->tblConfId->Name = L"tblConfId";
			this->tblConfId->ReadOnly = true;
			this->tblConfId->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Nombre";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Tel�fono";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// tblConfExtension
			// 
			this->tblConfExtension->HeaderText = L"Ext";
			this->tblConfExtension->Name = L"tblConfExtension";
			this->tblConfExtension->ReadOnly = true;
			this->tblConfExtension->Width = 50;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(15, 107);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(63, 17);
			this->label13->TabIndex = 21;
			this->label13->Text = L"Extensi�n";
			// 
			// txtPhoneExt
			// 
			this->txtPhoneExt->Location = System::Drawing::Point(19, 131);
			this->txtPhoneExt->Name = L"txtPhoneExt";
			this->txtPhoneExt->Size = System::Drawing::Size(154, 25);
			this->txtPhoneExt->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 51);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(56, 17);
			this->label10->TabIndex = 10;
			this->label10->Text = L"N�mero";
			// 
			// txtPhoneNumber
			// 
			this->txtPhoneNumber->Location = System::Drawing::Point(17, 75);
			this->txtPhoneNumber->Name = L"txtPhoneNumber";
			this->txtPhoneNumber->Size = System::Drawing::Size(156, 25);
			this->txtPhoneNumber->TabIndex = 9;
			// 
			// btnHangUp
			// 
			this->btnHangUp->Enabled = false;
			this->btnHangUp->Location = System::Drawing::Point(98, 170);
			this->btnHangUp->Name = L"btnHangUp";
			this->btnHangUp->Size = System::Drawing::Size(75, 31);
			this->btnHangUp->TabIndex = 13;
			this->btnHangUp->Text = L"Colgar";
			this->btnHangUp->UseVisualStyleBackColor = true;
			this->btnHangUp->Click += gcnew System::EventHandler(this, &Form1::btnHangUp_Click);
			// 
			// btnCall
			// 
			this->btnCall->Enabled = false;
			this->btnCall->Location = System::Drawing::Point(17, 170);
			this->btnCall->Name = L"btnCall";
			this->btnCall->Size = System::Drawing::Size(75, 31);
			this->btnCall->TabIndex = 12;
			this->btnCall->Text = L"Llamar";
			this->btnCall->UseVisualStyleBackColor = true;
			this->btnCall->Click += gcnew System::EventHandler(this, &Form1::btnCall_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button20);
			this->groupBox1->Controls->Add(this->portNumber);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->rbEnSitio);
			this->groupBox1->Controls->Add(this->rbRemoto);
			this->groupBox1->Controls->Add(this->btnDisconnect);
			this->groupBox1->Controls->Add(this->btnConnect);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(247, 174);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Conexi�n";
			// 
			// button20
			// 
			this->button20->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button20.Image")));
			this->button20->Location = System::Drawing::Point(195, 28);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(37, 32);
			this->button20->TabIndex = 27;
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// portNumber
			// 
			this->portNumber->Location = System::Drawing::Point(56, 85);
			this->portNumber->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->portNumber->Name = L"portNumber";
			this->portNumber->Size = System::Drawing::Size(62, 25);
			this->portNumber->TabIndex = 25;
			this->portNumber->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 88);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 17);
			this->label7->TabIndex = 26;
			this->label7->Text = L"COM";
			// 
			// rbEnSitio
			// 
			this->rbEnSitio->AutoSize = true;
			this->rbEnSitio->Checked = true;
			this->rbEnSitio->Location = System::Drawing::Point(15, 27);
			this->rbEnSitio->Name = L"rbEnSitio";
			this->rbEnSitio->Size = System::Drawing::Size(127, 21);
			this->rbEnSitio->TabIndex = 24;
			this->rbEnSitio->TabStop = true;
			this->rbEnSitio->Text = L"Descarga en sitio";
			this->rbEnSitio->UseVisualStyleBackColor = true;
			this->rbEnSitio->CheckedChanged += gcnew System::EventHandler(this, &Form1::rbEnSitio_CheckedChanged);
			// 
			// rbRemoto
			// 
			this->rbRemoto->AutoSize = true;
			this->rbRemoto->Location = System::Drawing::Point(15, 54);
			this->rbRemoto->Name = L"rbRemoto";
			this->rbRemoto->Size = System::Drawing::Size(127, 21);
			this->rbRemoto->TabIndex = 23;
			this->rbRemoto->Text = L"Descarga remota";
			this->rbRemoto->UseVisualStyleBackColor = true;
			this->rbRemoto->CheckedChanged += gcnew System::EventHandler(this, &Form1::rbRemoto_CheckedChanged);
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Location = System::Drawing::Point(126, 126);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(106, 32);
			this->btnDisconnect->TabIndex = 11;
			this->btnDisconnect->Text = L"Desconectar";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			this->btnDisconnect->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(14, 126);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(106, 32);
			this->btnConnect->TabIndex = 12;
			this->btnConnect->Text = L"Conectar";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->daysProfile);
			this->groupBox7->Controls->Add(this->rbDays);
			this->groupBox7->Controls->Add(this->rbComplete);
			this->groupBox7->Controls->Add(this->checkBox8);
			this->groupBox7->Controls->Add(this->checkBox6);
			this->groupBox7->Controls->Add(this->button4);
			this->groupBox7->Controls->Add(this->button3);
			this->groupBox7->Location = System::Drawing::Point(266, 232);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(285, 164);
			this->groupBox7->TabIndex = 10;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Descarga";
			// 
			// daysProfile
			// 
			this->daysProfile->Location = System::Drawing::Point(208, 59);
			this->daysProfile->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->daysProfile->Name = L"daysProfile";
			this->daysProfile->Size = System::Drawing::Size(60, 25);
			this->daysProfile->TabIndex = 11;
			this->daysProfile->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// rbDays
			// 
			this->rbDays->AutoSize = true;
			this->rbDays->Checked = true;
			this->rbDays->Location = System::Drawing::Point(151, 59);
			this->rbDays->Name = L"rbDays";
			this->rbDays->Size = System::Drawing::Size(51, 21);
			this->rbDays->TabIndex = 20;
			this->rbDays->TabStop = true;
			this->rbDays->Text = L"D�as";
			this->rbDays->UseVisualStyleBackColor = true;
			// 
			// rbComplete
			// 
			this->rbComplete->AutoSize = true;
			this->rbComplete->Location = System::Drawing::Point(151, 24);
			this->rbComplete->Name = L"rbComplete";
			this->rbComplete->Size = System::Drawing::Size(83, 21);
			this->rbComplete->TabIndex = 19;
			this->rbComplete->Text = L"Completo";
			this->rbComplete->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Checked = true;
			this->checkBox8->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox8->Location = System::Drawing::Point(16, 60);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(82, 21);
			this->checkBox8->TabIndex = 17;
			this->checkBox8->Text = L"Consumo";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Checked = true;
			this->checkBox6->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox6->Location = System::Drawing::Point(16, 28);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(110, 21);
			this->checkBox6->TabIndex = 16;
			this->checkBox6->Text = L"Interrupciones";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(146, 114);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(124, 31);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Terminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(16, 114);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 31);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Iniciar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cbUma5);
			this->groupBox2->Controls->Add(this->cbUma4);
			this->groupBox2->Controls->Add(this->cbUma3);
			this->groupBox2->Controls->Add(this->cbUma2);
			this->groupBox2->Controls->Add(this->btnQueryMeters);
			this->groupBox2->Controls->Add(this->cbUma1);
			this->groupBox2->Location = System::Drawing::Point(6, 186);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(247, 210);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"UMA";
			// 
			// cbUma5
			// 
			this->cbUma5->AutoSize = true;
			this->cbUma5->Enabled = false;
			this->cbUma5->Location = System::Drawing::Point(14, 178);
			this->cbUma5->Name = L"cbUma5";
			this->cbUma5->Size = System::Drawing::Size(89, 21);
			this->cbUma5->TabIndex = 4;
			this->cbUma5->Text = L"Medidor 5";
			this->cbUma5->UseVisualStyleBackColor = true;
			// 
			// cbUma4
			// 
			this->cbUma4->AutoSize = true;
			this->cbUma4->Enabled = false;
			this->cbUma4->Location = System::Drawing::Point(14, 151);
			this->cbUma4->Name = L"cbUma4";
			this->cbUma4->Size = System::Drawing::Size(89, 21);
			this->cbUma4->TabIndex = 3;
			this->cbUma4->Text = L"Medidor 4";
			this->cbUma4->UseVisualStyleBackColor = true;
			// 
			// cbUma3
			// 
			this->cbUma3->AutoSize = true;
			this->cbUma3->Enabled = false;
			this->cbUma3->Location = System::Drawing::Point(14, 124);
			this->cbUma3->Name = L"cbUma3";
			this->cbUma3->Size = System::Drawing::Size(89, 21);
			this->cbUma3->TabIndex = 2;
			this->cbUma3->Text = L"Medidor 3";
			this->cbUma3->UseVisualStyleBackColor = true;
			// 
			// cbUma2
			// 
			this->cbUma2->AutoSize = true;
			this->cbUma2->Enabled = false;
			this->cbUma2->Location = System::Drawing::Point(14, 97);
			this->cbUma2->Name = L"cbUma2";
			this->cbUma2->Size = System::Drawing::Size(89, 21);
			this->cbUma2->TabIndex = 1;
			this->cbUma2->Text = L"Medidor 2";
			this->cbUma2->UseVisualStyleBackColor = true;
			// 
			// btnQueryMeters
			// 
			this->btnQueryMeters->Enabled = false;
			this->btnQueryMeters->Location = System::Drawing::Point(14, 27);
			this->btnQueryMeters->Name = L"btnQueryMeters";
			this->btnQueryMeters->Size = System::Drawing::Size(218, 31);
			this->btnQueryMeters->TabIndex = 7;
			this->btnQueryMeters->Text = L"Interrogar Medidores";
			this->btnQueryMeters->UseVisualStyleBackColor = true;
			this->btnQueryMeters->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// cbUma1
			// 
			this->cbUma1->AutoSize = true;
			this->cbUma1->Enabled = false;
			this->cbUma1->Location = System::Drawing::Point(14, 70);
			this->cbUma1->Name = L"cbUma1";
			this->cbUma1->Size = System::Drawing::Size(89, 21);
			this->cbUma1->TabIndex = 0;
			this->cbUma1->Text = L"Medidor 1";
			this->cbUma1->UseVisualStyleBackColor = true;
			// 
			// tabReportes
			// 
			this->tabReportes->Controls->Add(this->tabControl3);
			this->tabReportes->Controls->Add(this->button14);
			this->tabReportes->Controls->Add(this->label1);
			this->tabReportes->Controls->Add(this->cbFechaChart);
			this->tabReportes->Controls->Add(this->button12);
			this->tabReportes->Controls->Add(this->button11);
			this->tabReportes->Controls->Add(this->button9);
			this->tabReportes->Controls->Add(this->button8);
			this->tabReportes->Location = System::Drawing::Point(4, 26);
			this->tabReportes->Name = L"tabReportes";
			this->tabReportes->Padding = System::Windows::Forms::Padding(3);
			this->tabReportes->Size = System::Drawing::Size(752, 410);
			this->tabReportes->TabIndex = 6;
			this->tabReportes->Text = L"Reportes";
			this->tabReportes->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(654, 369);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(92, 31);
			this->button14->TabIndex = 41;
			this->button14->Text = L"Graficar";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(398, 374);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 17);
			this->label1->TabIndex = 40;
			this->label1->Text = L"Fecha:";
			// 
			// cbFechaChart
			// 
			this->cbFechaChart->FormattingEnabled = true;
			this->cbFechaChart->Location = System::Drawing::Point(454, 371);
			this->cbFechaChart->Name = L"cbFechaChart";
			this->cbFechaChart->Size = System::Drawing::Size(135, 25);
			this->cbFechaChart->TabIndex = 39;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(300, 369);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(92, 31);
			this->button12->TabIndex = 30;
			this->button12->Text = L"Semanal";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(202, 369);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(92, 31);
			this->button11->TabIndex = 29;
			this->button11->Text = L"Diario";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(104, 369);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(92, 31);
			this->button9->TabIndex = 28;
			this->button9->Text = L"Horario";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(6, 369);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(92, 31);
			this->button8->TabIndex = 27;
			this->button8->Text = L"Archivo";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// chart1
			// 
			chartArea1->Area3DStyle->Enable3D = true;
			chartArea1->Area3DStyle->LightStyle = System::Windows::Forms::DataVisualization::Charting::LightStyle::Realistic;
			chartArea1->Area3DStyle->PointDepth = 50;
			chartArea1->Area3DStyle->WallWidth = 2;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(6, 6);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SemiTransparent;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Activa";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Reactiva";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(719, 314);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// tabClientes
			// 
			this->tabClientes->Controls->Add(this->groupBox11);
			this->tabClientes->Controls->Add(this->groupBox10);
			this->tabClientes->Location = System::Drawing::Point(4, 26);
			this->tabClientes->Name = L"tabClientes";
			this->tabClientes->Padding = System::Windows::Forms::Padding(3);
			this->tabClientes->Size = System::Drawing::Size(752, 410);
			this->tabClientes->TabIndex = 2;
			this->tabClientes->Text = L"Clientes";
			this->tabClientes->UseVisualStyleBackColor = true;
			this->tabClientes->Enter += gcnew System::EventHandler(this, &Form1::tabClientes_Enter);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->btnEliminar);
			this->groupBox11->Controls->Add(this->btnEditar);
			this->groupBox11->Controls->Add(this->btnNuevo);
			this->groupBox11->Controls->Add(this->dataGridView2);
			this->groupBox11->Location = System::Drawing::Point(6, 6);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(513, 394);
			this->groupBox11->TabIndex = 3;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Clientes";
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(255, 349);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(114, 32);
			this->btnEliminar->TabIndex = 9;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &Form1::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(133, 349);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(114, 32);
			this->btnEditar->TabIndex = 8;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &Form1::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(11, 349);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(114, 32);
			this->btnNuevo->TabIndex = 7;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Id, this->dataGridViewTextBoxColumn1, 
				this->Apellidos, this->dataGridViewTextBoxColumn2, this->Extension});
			this->dataGridView2->Location = System::Drawing::Point(11, 26);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(490, 315);
			this->dataGridView2->TabIndex = 1;
			this->dataGridView2->DoubleClick += gcnew System::EventHandler(this, &Form1::dataGridView2_DoubleClick);
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Visible = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Nombres";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// Apellidos
			// 
			this->Apellidos->HeaderText = L"Apellidos";
			this->Apellidos->Name = L"Apellidos";
			this->Apellidos->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Tel�fono";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// Extension
			// 
			this->Extension->HeaderText = L"Extension";
			this->Extension->Name = L"Extension";
			this->Extension->ReadOnly = true;
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->btnCancel);
			this->groupBox10->Controls->Add(this->label12);
			this->groupBox10->Controls->Add(this->txtId);
			this->groupBox10->Controls->Add(this->label11);
			this->groupBox10->Controls->Add(this->label6);
			this->groupBox10->Controls->Add(this->txtApellidos);
			this->groupBox10->Controls->Add(this->btnGuardar);
			this->groupBox10->Controls->Add(this->txtExtension);
			this->groupBox10->Controls->Add(this->label3);
			this->groupBox10->Controls->Add(this->txtNumero);
			this->groupBox10->Controls->Add(this->label2);
			this->groupBox10->Controls->Add(this->txtNombres);
			this->groupBox10->Location = System::Drawing::Point(525, 6);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(221, 394);
			this->groupBox10->TabIndex = 2;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Cliente";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(14, 349);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(85, 32);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Form1::btnCancel_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(13, 264);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(19, 17);
			this->label12->TabIndex = 39;
			this->label12->Text = L"Id";
			this->label12->Visible = false;
			// 
			// txtId
			// 
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(14, 288);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(194, 25);
			this->txtId->TabIndex = 38;
			this->txtId->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(11, 203);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 17);
			this->label11->TabIndex = 37;
			this->label11->Text = L"Extensi�n";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 17);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Apellidos";
			// 
			// txtApellidos
			// 
			this->txtApellidos->Location = System::Drawing::Point(14, 111);
			this->txtApellidos->Name = L"txtApellidos";
			this->txtApellidos->Size = System::Drawing::Size(194, 25);
			this->txtApellidos->TabIndex = 2;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(123, 349);
			this->btnGuardar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(85, 32);
			this->btnGuardar->TabIndex = 6;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Form1::btnGuardar_Click);
			// 
			// txtExtension
			// 
			this->txtExtension->Location = System::Drawing::Point(14, 227);
			this->txtExtension->Name = L"txtExtension";
			this->txtExtension->Size = System::Drawing::Size(194, 25);
			this->txtExtension->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 17);
			this->label3->TabIndex = 14;
			this->label3->Text = L"N�mero";
			// 
			// txtNumero
			// 
			this->txtNumero->Location = System::Drawing::Point(14, 167);
			this->txtNumero->Name = L"txtNumero";
			this->txtNumero->Size = System::Drawing::Size(196, 25);
			this->txtNumero->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Nombres";
			// 
			// txtNombres
			// 
			this->txtNombres->Location = System::Drawing::Point(14, 55);
			this->txtNombres->Name = L"txtNombres";
			this->txtNombres->Size = System::Drawing::Size(194, 25);
			this->txtNombres->TabIndex = 1;
			// 
			// tabConfig
			// 
			this->tabConfig->Controls->Add(this->groupBox9);
			this->tabConfig->Controls->Add(this->groupBox5);
			this->tabConfig->Controls->Add(this->groupBox4);
			this->tabConfig->Controls->Add(this->button10);
			this->tabConfig->Location = System::Drawing::Point(4, 26);
			this->tabConfig->Name = L"tabConfig";
			this->tabConfig->Padding = System::Windows::Forms::Padding(3);
			this->tabConfig->Size = System::Drawing::Size(752, 410);
			this->tabConfig->TabIndex = 5;
			this->tabConfig->Text = L"Configuraci�n";
			this->tabConfig->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->button5);
			this->groupBox9->Controls->Add(this->labSavePath);
			this->groupBox9->Location = System::Drawing::Point(7, 333);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(608, 65);
			this->groupBox9->TabIndex = 39;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Guardar archivos en:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(493, 23);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(105, 31);
			this->button5->TabIndex = 26;
			this->button5->Text = L"Seleccionar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// labSavePath
			// 
			this->labSavePath->AutoSize = true;
			this->labSavePath->Location = System::Drawing::Point(11, 29);
			this->labSavePath->Name = L"labSavePath";
			this->labSavePath->Size = System::Drawing::Size(24, 17);
			this->labSavePath->TabIndex = 25;
			this->labSavePath->Text = L"C:\\";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button19);
			this->groupBox5->Controls->Add(this->button18);
			this->groupBox5->Controls->Add(this->progressBar1);
			this->groupBox5->Controls->Add(this->label14);
			this->groupBox5->Controls->Add(this->button15);
			this->groupBox5->Controls->Add(this->rbTrend);
			this->groupBox5->Controls->Add(this->rbCnet);
			this->groupBox5->Controls->Add(this->rbOtro);
			this->groupBox5->Location = System::Drawing::Point(273, 7);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(225, 320);
			this->groupBox5->TabIndex = 36;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Modem";
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(180, 132);
			this->button19->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(33, 32);
			this->button19->TabIndex = 42;
			this->button19->Text = L"+";
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(13, 132);
			this->button18->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(33, 32);
			this->button18->TabIndex = 41;
			this->button18->Text = L"-";
			this->button18->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(53, 132);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(120, 32);
			this->progressBar1->TabIndex = 40;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(10, 110);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(113, 17);
			this->label14->TabIndex = 39;
			this->label14->Text = L"Volumen Speaker:";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(13, 274);
			this->button15->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(200, 32);
			this->button15->TabIndex = 38;
			this->button15->Text = L"Reset Modem";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// rbTrend
			// 
			this->rbTrend->AutoSize = true;
			this->rbTrend->Location = System::Drawing::Point(15, 25);
			this->rbTrend->Name = L"rbTrend";
			this->rbTrend->Size = System::Drawing::Size(85, 21);
			this->rbTrend->TabIndex = 34;
			this->rbTrend->TabStop = true;
			this->rbTrend->Text = L"TRENDnet";
			this->rbTrend->UseVisualStyleBackColor = true;
			// 
			// rbCnet
			// 
			this->rbCnet->AutoSize = true;
			this->rbCnet->Location = System::Drawing::Point(16, 52);
			this->rbCnet->Name = L"rbCnet";
			this->rbCnet->Size = System::Drawing::Size(58, 21);
			this->rbCnet->TabIndex = 35;
			this->rbCnet->TabStop = true;
			this->rbCnet->Text = L"CNET";
			this->rbCnet->UseVisualStyleBackColor = true;
			// 
			// rbOtro
			// 
			this->rbOtro->AutoSize = true;
			this->rbOtro->Location = System::Drawing::Point(16, 79);
			this->rbOtro->Name = L"rbOtro";
			this->rbOtro->Size = System::Drawing::Size(53, 21);
			this->rbOtro->TabIndex = 36;
			this->rbOtro->TabStop = true;
			this->rbOtro->Text = L"Otro";
			this->rbOtro->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->cbRTS);
			this->groupBox4->Controls->Add(this->label18);
			this->groupBox4->Controls->Add(this->cbDTR);
			this->groupBox4->Controls->Add(this->label17);
			this->groupBox4->Controls->Add(this->cbHandShaking);
			this->groupBox4->Controls->Add(this->label16);
			this->groupBox4->Controls->Add(this->cbStopBits);
			this->groupBox4->Controls->Add(this->cbParity);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->txtBaudRate);
			this->groupBox4->Controls->Add(this->txtDataBits);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Location = System::Drawing::Point(7, 7);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(260, 320);
			this->groupBox4->TabIndex = 35;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Puerto COM";
			// 
			// cbRTS
			// 
			this->cbRTS->AutoSize = true;
			this->cbRTS->Checked = true;
			this->cbRTS->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbRTS->Location = System::Drawing::Point(98, 242);
			this->cbRTS->Name = L"cbRTS";
			this->cbRTS->Size = System::Drawing::Size(15, 14);
			this->cbRTS->TabIndex = 45;
			this->cbRTS->UseVisualStyleBackColor = true;
			this->cbRTS->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(13, 240);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(56, 17);
			this->label18->TabIndex = 44;
			this->label18->Text = L"Use RTS";
			this->label18->Visible = false;
			// 
			// cbDTR
			// 
			this->cbDTR->AutoSize = true;
			this->cbDTR->Checked = true;
			this->cbDTR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbDTR->Location = System::Drawing::Point(98, 212);
			this->cbDTR->Name = L"cbDTR";
			this->cbDTR->Size = System::Drawing::Size(15, 14);
			this->cbDTR->TabIndex = 43;
			this->cbDTR->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(13, 210);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(58, 17);
			this->label17->TabIndex = 42;
			this->label17->Text = L"Use DTR";
			// 
			// cbHandShaking
			// 
			this->cbHandShaking->FormattingEnabled = true;
			this->cbHandShaking->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"RequestToSend", L"RequestToSendXOnXOff", 
				L"XOnXOff"});
			this->cbHandShaking->Location = System::Drawing::Point(97, 172);
			this->cbHandShaking->Name = L"cbHandShaking";
			this->cbHandShaking->Size = System::Drawing::Size(149, 25);
			this->cbHandShaking->TabIndex = 41;
			this->cbHandShaking->Text = L"XOnXOff";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(12, 175);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(77, 17);
			this->label16->TabIndex = 40;
			this->label16->Text = L"Hand Shake";
			// 
			// cbStopBits
			// 
			this->cbStopBits->FormattingEnabled = true;
			this->cbStopBits->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"0", L"1", L"1.5", L"2"});
			this->cbStopBits->Location = System::Drawing::Point(97, 136);
			this->cbStopBits->Name = L"cbStopBits";
			this->cbStopBits->Size = System::Drawing::Size(149, 25);
			this->cbStopBits->TabIndex = 39;
			this->cbStopBits->Text = L"1";
			// 
			// cbParity
			// 
			this->cbParity->FormattingEnabled = true;
			this->cbParity->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Ninguna", L"Par", L"Inpar"});
			this->cbParity->Location = System::Drawing::Point(97, 100);
			this->cbParity->Name = L"cbParity";
			this->cbParity->Size = System::Drawing::Size(149, 25);
			this->cbParity->TabIndex = 38;
			this->cbParity->Text = L"Ninguna";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 17);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Stop Bits";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 17);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Baud Rate";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 17);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Parity";
			// 
			// txtBaudRate
			// 
			this->txtBaudRate->Location = System::Drawing::Point(97, 29);
			this->txtBaudRate->Name = L"txtBaudRate";
			this->txtBaudRate->Size = System::Drawing::Size(149, 25);
			this->txtBaudRate->TabIndex = 23;
			this->txtBaudRate->Text = L"9600";
			// 
			// txtDataBits
			// 
			this->txtDataBits->Location = System::Drawing::Point(97, 65);
			this->txtDataBits->Name = L"txtDataBits";
			this->txtDataBits->Size = System::Drawing::Size(149, 25);
			this->txtDataBits->TabIndex = 26;
			this->txtDataBits->Text = L"8";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 17);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Data Bits";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(626, 356);
			this->button10->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(114, 32);
			this->button10->TabIndex = 33;
			this->button10->Text = L"Guardar";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// tabLog
			// 
			this->tabLog->Controls->Add(this->tabControl2);
			this->tabLog->Controls->Add(this->button7);
			this->tabLog->Location = System::Drawing::Point(4, 26);
			this->tabLog->Name = L"tabLog";
			this->tabLog->Padding = System::Windows::Forms::Padding(3);
			this->tabLog->Size = System::Drawing::Size(752, 410);
			this->tabLog->TabIndex = 4;
			this->tabLog->Text = L"Logs";
			this->tabLog->UseVisualStyleBackColor = true;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage6);
			this->tabControl2->Controls->Add(this->tabPage7);
			this->tabControl2->Controls->Add(this->tabPage1);
			this->tabControl2->Controls->Add(this->tabPage2);
			this->tabControl2->Location = System::Drawing::Point(9, 6);
			this->tabControl2->Multiline = true;
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(740, 357);
			this->tabControl2->TabIndex = 15;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->txtBreaks);
			this->tabPage6->Location = System::Drawing::Point(4, 26);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(732, 327);
			this->tabPage6->TabIndex = 0;
			this->tabPage6->Text = L"Interrupciones";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// txtBreaks
			// 
			this->txtBreaks->BackColor = System::Drawing::Color::WhiteSmoke;
			this->txtBreaks->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBreaks->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtBreaks->Location = System::Drawing::Point(6, 6);
			this->txtBreaks->Name = L"txtBreaks";
			this->txtBreaks->ReadOnly = true;
			this->txtBreaks->Size = System::Drawing::Size(720, 311);
			this->txtBreaks->TabIndex = 12;
			this->txtBreaks->Text = L"";
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->txtConsumo);
			this->tabPage7->Location = System::Drawing::Point(4, 26);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(732, 327);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"Consumo";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// txtConsumo
			// 
			this->txtConsumo->BackColor = System::Drawing::Color::WhiteSmoke;
			this->txtConsumo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtConsumo->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtConsumo->Location = System::Drawing::Point(6, 6);
			this->txtConsumo->Name = L"txtConsumo";
			this->txtConsumo->ReadOnly = true;
			this->txtConsumo->Size = System::Drawing::Size(720, 311);
			this->txtConsumo->TabIndex = 13;
			this->txtConsumo->Text = L"";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->txtTotales);
			this->tabPage1->Location = System::Drawing::Point(4, 26);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(732, 327);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Totales";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// txtTotales
			// 
			this->txtTotales->BackColor = System::Drawing::Color::WhiteSmoke;
			this->txtTotales->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTotales->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtTotales->Location = System::Drawing::Point(6, 6);
			this->txtTotales->Name = L"txtTotales";
			this->txtTotales->ReadOnly = true;
			this->txtTotales->Size = System::Drawing::Size(720, 311);
			this->txtTotales->TabIndex = 14;
			this->txtTotales->Text = L"";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->txtCmd);
			this->tabPage2->Controls->Add(this->btnSendCmd);
			this->tabPage2->Controls->Add(this->logTextBox);
			this->tabPage2->Location = System::Drawing::Point(4, 26);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(732, 327);
			this->tabPage2->TabIndex = 3;
			this->tabPage2->Text = L"Consola";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 9);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(110, 17);
			this->label15->TabIndex = 48;
			this->label15->Text = L"Enviar Comandos";
			// 
			// txtCmd
			// 
			this->txtCmd->Location = System::Drawing::Point(123, 6);
			this->txtCmd->Name = L"txtCmd";
			this->txtCmd->Size = System::Drawing::Size(476, 25);
			this->txtCmd->TabIndex = 47;
			// 
			// btnSendCmd
			// 
			this->btnSendCmd->Location = System::Drawing::Point(606, 6);
			this->btnSendCmd->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnSendCmd->Name = L"btnSendCmd";
			this->btnSendCmd->Size = System::Drawing::Size(120, 25);
			this->btnSendCmd->TabIndex = 46;
			this->btnSendCmd->Text = L"Enviar";
			this->btnSendCmd->UseVisualStyleBackColor = true;
			this->btnSendCmd->Click += gcnew System::EventHandler(this, &Form1::btnSendCmd_Click);
			// 
			// logTextBox
			// 
			this->logTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->logTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->logTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->logTextBox->Location = System::Drawing::Point(6, 37);
			this->logTextBox->Name = L"logTextBox";
			this->logTextBox->ReadOnly = true;
			this->logTextBox->Size = System::Drawing::Size(720, 280);
			this->logTextBox->TabIndex = 11;
			this->logTextBox->Text = L"";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(618, 369);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(128, 31);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Limpiar";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 17);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"tot";
			this->openFileDialog1->Filter = L"Totales (*.tot)|*.tot";
			// 
			// tabContEnerg
			// 
			this->tabContEnerg->Location = System::Drawing::Point(4, 26);
			this->tabContEnerg->Name = L"tabContEnerg";
			this->tabContEnerg->Padding = System::Windows::Forms::Padding(3);
			this->tabContEnerg->Size = System::Drawing::Size(752, 410);
			this->tabContEnerg->TabIndex = 7;
			this->tabContEnerg->Text = L"Contabilidad Energ�tica";
			this->tabContEnerg->UseVisualStyleBackColor = true;
			// 
			// tabControl3
			// 
			this->tabControl3->Controls->Add(this->tabPage3);
			this->tabControl3->Controls->Add(this->tabTable);
			this->tabControl3->Location = System::Drawing::Point(7, 7);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(739, 356);
			this->tabControl3->TabIndex = 42;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->chart1);
			this->tabPage3->Location = System::Drawing::Point(4, 26);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(731, 326);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Gr�fica";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabTable
			// 
			this->tabTable->Controls->Add(this->dataGridView3);
			this->tabTable->Location = System::Drawing::Point(4, 26);
			this->tabTable->Name = L"tabTable";
			this->tabTable->Padding = System::Windows::Forms::Padding(3);
			this->tabTable->Size = System::Drawing::Size(731, 326);
			this->tabTable->TabIndex = 1;
			this->tabTable->Text = L"Tabla";
			this->tabTable->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(6, 6);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(719, 314);
			this->dataGridView3->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(782, 627);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"TeleProdelec";
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabConexion->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->gbLlamada->ResumeLayout(false);
			this->gbLlamada->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->portNumber))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->daysProfile))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabReportes->ResumeLayout(false);
			this->tabReportes->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->tabClientes->ResumeLayout(false);
			this->groupBox11->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->tabConfig->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabLog->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingSource1))->EndInit();
			this->tabControl3->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabTable->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	// Teleconsa
	public:
		void Log(String^ message);
		void Process(String^ message);
		void ReadSettings();
		void UpdateSettings();
		void GotoConfig();
		void SwitchConnectionType();
		void UpdateSerials(ArrayList^ serials);
		int  SetSerial(CheckBox^ cb, int index, Object^ serial);

		void FillUsersDataCrud();
		void FillUsersDataConf();

		void FillDetailedTextWithIndex(int i);
		void ClearDetailedTextFields();

		void ShowDetailedTextFields();
		void HideDetailedTextFields();
		
		void Save();
		void SaveNewUser();
		void SaveExistingUser();
		void DeleteExistinUserAtIndex(int i);

		void SetConfigurationTelefoneNumberAtIndex(int i);

		void CheckMeters();
		bool DownloadSelectedInfo();
		bool DownloadBreaks();
		bool DownloadLoadProfile();
		void EndMeterOperartions();
		void RunTest();
		void SelectFile();

	private:
		PortCommunicator^ comm;
		MeterController^ meter;
		ModemController^ modem;
		ChartDrawer^ chart;
		String^ strMessage;

		System::Void InitializeTeleconsa() {
			ReadSettings();
			comm = gcnew PortCommunicator(this);
			meter = gcnew MeterController(this, comm);
			modem = gcnew ModemController(this, comm);
			chart = gcnew ChartDrawer(this);
			dbService = gcnew DbService();
			HideDetailedTextFields();
		}

		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			UpdateSettings();
			bool connected = false;
			if(this->rbRemoto->Checked) {
				modem->Init();
				connected = modem->Connect();
			} else {
				meter->Init();
				connected = meter->Connect();
			}
			if(connected) {
				btnQueryMeters->Enabled = true;
				btnCall->Enabled = true;
				btnHangUp->Enabled = true;
				rbRemoto->Enabled = false;
				rbEnSitio->Enabled = false;
			}
		}

		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			if(meter->Disconnect()) {
				btnQueryMeters->Enabled = false;
				btnCall->Enabled = false;
				btnHangUp->Enabled = false;
				rbRemoto->Enabled = true;
				rbEnSitio->Enabled = true;
			}
		}

		System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			DownloadSelectedInfo();
		}

		System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			CheckMeters();
		}

		System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			UpdateSettings();
		}
		
		System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			folderBrowserDialog1->ShowDialog();
			labSavePath->Text = folderBrowserDialog1->SelectedPath;
		}
		System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			EndMeterOperartions();
		}
		System::Void opcionesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			tabControl1->SelectedIndex = 3;
		}
		System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			logTextBox->Text = "";
		}
		System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			RunTest();
		}
		System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			SelectFile();
		}
		System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			chart->ParseFile();
			chart->CalcHourly();
		}
		System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			chart->Draw();
		}
		System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			chart->ParseFile();
			chart->CalcMonth();
		}

		System::Void tabClientes_Enter(System::Object^  sender, System::EventArgs^  e) 
		{
			FillUsersDataCrud();
		}

		System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ClearDetailedTextFields();
			ShowDetailedTextFields();
		}

		System::Void btnGuardar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Save();
			HideDetailedTextFields();
		}
		
		System::Void dataGridView2_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
		{
			if (dataGridView2->CurrentRow)
			{
				FillDetailedTextWithIndex(dataGridView2->CurrentRow->Index);
				ShowDetailedTextFields();
			}
		}

		System::Void btnEliminar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (dataGridView2->CurrentRow)
			{
				DeleteExistinUserAtIndex(dataGridView2->CurrentRow->Index);
				HideDetailedTextFields();
			}
			
		}
		System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ClearDetailedTextFields();
			HideDetailedTextFields();
		}
		System::Void dataGridView1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
		{
			if (dataGridView1->CurrentRow)
			{
				SetConfigurationTelefoneNumberAtIndex(dataGridView1->CurrentRow->Index);
			}
		}
		System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void btnEditar_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void tabConexion_Enter(System::Object^  sender, System::EventArgs^  e) {
			FillUsersDataConf();
		}
		System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			GotoConfig();
		}
		System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		}
		System::Void rbEnSitio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			SwitchConnectionType();
		}
		System::Void rbRemoto_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			SwitchConnectionType();
		}
		System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			modem->Reset();
		}
		System::Void btnCall_Click(System::Object^  sender, System::EventArgs^  e) {
			modem->Call(txtPhoneNumber->Text, txtPhoneExt->Text);
		}
		System::Void btnHangUp_Click(System::Object^  sender, System::EventArgs^  e) {
			modem->HangUp();
		}
		System::Void btnSendCmd_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->rbRemoto->Checked) {
				modem->SendCmd(txtCmd->Text);
			} else {
				meter->SendCmd(txtCmd->Text);
			}
			txtCmd->Text = "";
		}
	};
}

