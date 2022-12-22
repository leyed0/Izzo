#pragma once

namespace Izzo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			//toggle_timer->DataBindings->Add("Enabled", Arduinooo, "IsOpen", false, DataSourceUpdateMode::OnPropertyChanged);
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ interval_lbl;
	private: System::Windows::Forms::NumericUpDown^ Interval_txtb;

	private: System::Windows::Forms::Button^ toggle_timer;
	private: System::Windows::Forms::SaveFileDialog^ SaveFile;




	private: System::Windows::Forms::ToolStripMenuItem^ connectionToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ portToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ toolStripPort_cbx;
	private: System::Windows::Forms::ToolStripMenuItem^ baudToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ toolStripBaud_cbx;
	private: System::Windows::Forms::ToolStripMenuItem^ connectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ logToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pathToolStripMenuItem;

	private: System::Windows::Forms::MenuStrip^ TopMenu;
	private: System::IO::Ports::SerialPort^ Arduinooo;
	private: System::IO::TextWriter^ File;
	private: System::Windows::Forms::Label^ UM_lbl;
	private: System::Windows::Forms::TextBox^ UM_txb;
	private: System::Windows::Forms::Timer^ Dbg_Timer;
	public: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ Cursor_gbx;
	public:
	private: System::Windows::Forms::TextBox^ YVal_txtb;
	private: System::Windows::Forms::TextBox^ XVal_txtb;
	private: System::Windows::Forms::Label^ YVal_lbl;
	private: System::Windows::Forms::Label^ XVal_lbl;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::NumericUpDown^ ConvConst_txtb;
	private: System::Windows::Forms::NumericUpDown^ RefZero_txtb;
	private: System::Data::DataSet^ DataSet;
	private: System::Data::DataTable^ Readdings;
	private: System::Data::DataColumn^ dataColumn1;
	private: System::Data::DataColumn^ dataColumn2;
	private: System::Data::DataColumn^ dataColumn3;
	private: System::Data::DataTable^ Parameters;
	private: System::Data::DataColumn^ dataColumn4;
	private: System::Data::DataColumn^ dataColumn5;
	private: System::Data::DataColumn^ dataColumn6;
	private: System::Data::DataColumn^ dataColumn7;
	private: System::Data::DataColumn^ dataColumn8;
	private: System::Data::DataColumn^ dataColumn9;
	private: System::Windows::Forms::Label^ Debug_lbl;
	private: System::Windows::Forms::Button^ Dbg_Btn;
	private: System::Data::DataColumn^ CSVPath;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private:




	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
	private: System::IO::Ports::SerialPort^ Arduinoo;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::BackgroundWorker^ backgroundWorker1;
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->DataSet = (gcnew System::Data::DataSet());
			this->Readdings = (gcnew System::Data::DataTable());
			this->dataColumn1 = (gcnew System::Data::DataColumn());
			this->dataColumn2 = (gcnew System::Data::DataColumn());
			this->dataColumn3 = (gcnew System::Data::DataColumn());
			this->Parameters = (gcnew System::Data::DataTable());
			this->dataColumn4 = (gcnew System::Data::DataColumn());
			this->dataColumn5 = (gcnew System::Data::DataColumn());
			this->dataColumn6 = (gcnew System::Data::DataColumn());
			this->dataColumn7 = (gcnew System::Data::DataColumn());
			this->dataColumn8 = (gcnew System::Data::DataColumn());
			this->dataColumn9 = (gcnew System::Data::DataColumn());
			this->CSVPath = (gcnew System::Data::DataColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Dbg_Btn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ConvConst_txtb = (gcnew System::Windows::Forms::NumericUpDown());
			this->RefZero_txtb = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UM_lbl = (gcnew System::Windows::Forms::Label());
			this->UM_txb = (gcnew System::Windows::Forms::TextBox());
			this->Cursor_gbx = (gcnew System::Windows::Forms::GroupBox());
			this->YVal_txtb = (gcnew System::Windows::Forms::TextBox());
			this->XVal_txtb = (gcnew System::Windows::Forms::TextBox());
			this->YVal_lbl = (gcnew System::Windows::Forms::Label());
			this->XVal_lbl = (gcnew System::Windows::Forms::Label());
			this->Debug_lbl = (gcnew System::Windows::Forms::Label());
			this->toggle_timer = (gcnew System::Windows::Forms::Button());
			this->Interval_txtb = (gcnew System::Windows::Forms::NumericUpDown());
			this->interval_lbl = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->SaveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->connectionToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripPort_cbx = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->baudToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripBaud_cbx = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->connectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pathToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TopMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->Arduinooo = (gcnew System::IO::Ports::SerialPort(this->components));
			this->Dbg_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Readdings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Parameters))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConvConst_txtb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefZero_txtb))->BeginInit();
			this->Cursor_gbx->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Interval_txtb))->BeginInit();
			this->TopMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				181)));
			this->tableLayoutPanel1->Controls->Add(this->chart1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->statusStrip1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5.542725F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 94.45728F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1163, 575);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// chart1
			// 
			chartArea1->AxisX->MajorGrid->Enabled = false;
			chartArea1->AxisX2->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->AxisX2->Title = L"teste[";
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->AxisY->MajorGrid->Enabled = false;
			chartArea1->AxisY->Maximum = 350;
			chartArea1->AxisY->Minimum = -10;
			chartArea1->AxisY->Title = L"UM";
			chartArea1->CursorX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->CursorY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->Name = L"Main";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->DataSource = this->DataSet;
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(4, 35);
			this->chart1->Margin = System::Windows::Forms::Padding(4);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"Main";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			series1->Legend = L"Legend1";
			series1->LegendText = L"UM";
			series1->Name = L"UM";
			series1->XValueMember = L"DateTime";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"Val";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(974, 536);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MainForm::chart1_Click);
			this->chart1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::chart1_MouseMove);
			// 
			// DataSet
			// 
			this->DataSet->DataSetName = L"DataSet";
			this->DataSet->Tables->AddRange(gcnew cli::array< System::Data::DataTable^  >(2) { this->Readdings, this->Parameters });
			// 
			// Readdings
			// 
			this->Readdings->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(3) {
				this->dataColumn1, this->dataColumn2,
					this->dataColumn3
			});
			this->Readdings->TableName = L"Readdings";
			// 
			// dataColumn1
			// 
			this->dataColumn1->ColumnName = L"DateTime";
			this->dataColumn1->DataType = System::DateTime::typeid;
			// 
			// dataColumn2
			// 
			this->dataColumn2->ColumnName = L"Read";
			this->dataColumn2->DataType = System::Int32::typeid;
			// 
			// dataColumn3
			// 
			this->dataColumn3->ColumnName = L"Val";
			this->dataColumn3->DataType = System::Double::typeid;
			// 
			// Parameters
			// 
			this->Parameters->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(7) {
				this->dataColumn4, this->dataColumn5,
					this->dataColumn6, this->dataColumn7, this->dataColumn8, this->dataColumn9, this->CSVPath
			});
			this->Parameters->TableName = L"Parameters";
			// 
			// dataColumn4
			// 
			this->dataColumn4->ColumnName = L"Zero";
			this->dataColumn4->DataType = System::Decimal::typeid;
			// 
			// dataColumn5
			// 
			this->dataColumn5->ColumnName = L"UM";
			// 
			// dataColumn6
			// 
			this->dataColumn6->ColumnName = L"Constant";
			this->dataColumn6->DataType = System::Decimal::typeid;
			// 
			// dataColumn7
			// 
			this->dataColumn7->ColumnName = L"Interval";
			this->dataColumn7->DataType = System::Decimal::typeid;
			// 
			// dataColumn8
			// 
			this->dataColumn8->ColumnName = L"COM";
			// 
			// dataColumn9
			// 
			this->dataColumn9->ColumnName = L"Baud";
			// 
			// CSVPath
			// 
			this->CSVPath->ColumnName = L"CSVPath";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Dbg_Btn);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->Cursor_gbx);
			this->panel1->Controls->Add(this->Debug_lbl);
			this->panel1->Controls->Add(this->toggle_timer);
			this->panel1->Controls->Add(this->Interval_txtb);
			this->panel1->Controls->Add(this->interval_lbl);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(986, 35);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(173, 536);
			this->panel1->TabIndex = 2;
			// 
			// Dbg_Btn
			// 
			this->Dbg_Btn->Location = System::Drawing::Point(0, 308);
			this->Dbg_Btn->Name = L"Dbg_Btn";
			this->Dbg_Btn->Size = System::Drawing::Size(75, 23);
			this->Dbg_Btn->TabIndex = 11;
			this->Dbg_Btn->Text = L"Debug";
			this->Dbg_Btn->UseVisualStyleBackColor = true;
			this->Dbg_Btn->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Dbg_Btn_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ConvConst_txtb);
			this->groupBox1->Controls->Add(this->RefZero_txtb);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->UM_lbl);
			this->groupBox1->Controls->Add(this->UM_txb);
			this->groupBox1->Location = System::Drawing::Point(5, 109);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(163, 176);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parametros";
			// 
			// ConvConst_txtb
			// 
			this->ConvConst_txtb->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Value", this->DataSet, L"Parameters.Constant",
				true)));
			this->ConvConst_txtb->DecimalPlaces = 5;
			this->ConvConst_txtb->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 327680 });
			this->ConvConst_txtb->Location = System::Drawing::Point(6, 139);
			this->ConvConst_txtb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->ConvConst_txtb->Name = L"ConvConst_txtb";
			this->ConvConst_txtb->Size = System::Drawing::Size(129, 22);
			this->ConvConst_txtb->TabIndex = 11;
			this->ConvConst_txtb->ValueChanged += gcnew System::EventHandler(this, &MainForm::ConvConst_txtb_ValueChanged);
			// 
			// RefZero_txtb
			// 
			this->RefZero_txtb->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Value", this->DataSet, L"Parameters.Zero", true)));
			this->RefZero_txtb->Location = System::Drawing::Point(6, 91);
			this->RefZero_txtb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->RefZero_txtb->Name = L"RefZero_txtb";
			this->RefZero_txtb->Size = System::Drawing::Size(129, 22);
			this->RefZero_txtb->TabIndex = 11;
			this->RefZero_txtb->ValueChanged += gcnew System::EventHandler(this, &MainForm::RefZero_txtb_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Constante de conversão";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Referencia zero";
			// 
			// UM_lbl
			// 
			this->UM_lbl->AutoSize = true;
			this->UM_lbl->Location = System::Drawing::Point(6, 23);
			this->UM_lbl->Name = L"UM_lbl";
			this->UM_lbl->Size = System::Drawing::Size(129, 16);
			this->UM_lbl->TabIndex = 7;
			this->UM_lbl->Text = L"Unidade De Medida";
			// 
			// UM_txb
			// 
			this->UM_txb->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->DataSet, L"Parameters.UM", true)));
			this->UM_txb->Location = System::Drawing::Point(6, 43);
			this->UM_txb->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UM_txb->Name = L"UM_txb";
			this->UM_txb->Size = System::Drawing::Size(129, 22);
			this->UM_txb->TabIndex = 8;
			this->UM_txb->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// Cursor_gbx
			// 
			this->Cursor_gbx->Controls->Add(this->YVal_txtb);
			this->Cursor_gbx->Controls->Add(this->XVal_txtb);
			this->Cursor_gbx->Controls->Add(this->YVal_lbl);
			this->Cursor_gbx->Controls->Add(this->XVal_lbl);
			this->Cursor_gbx->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Cursor_gbx->Location = System::Drawing::Point(0, 391);
			this->Cursor_gbx->Name = L"Cursor_gbx";
			this->Cursor_gbx->Size = System::Drawing::Size(173, 145);
			this->Cursor_gbx->TabIndex = 9;
			this->Cursor_gbx->TabStop = false;
			this->Cursor_gbx->Text = L"Cursor:";
			// 
			// YVal_txtb
			// 
			this->YVal_txtb->Location = System::Drawing::Point(7, 87);
			this->YVal_txtb->Name = L"YVal_txtb";
			this->YVal_txtb->ReadOnly = true;
			this->YVal_txtb->Size = System::Drawing::Size(163, 22);
			this->YVal_txtb->TabIndex = 1;
			// 
			// XVal_txtb
			// 
			this->XVal_txtb->Location = System::Drawing::Point(7, 42);
			this->XVal_txtb->Name = L"XVal_txtb";
			this->XVal_txtb->ReadOnly = true;
			this->XVal_txtb->Size = System::Drawing::Size(163, 22);
			this->XVal_txtb->TabIndex = 1;
			// 
			// YVal_lbl
			// 
			this->YVal_lbl->AutoSize = true;
			this->YVal_lbl->Location = System::Drawing::Point(7, 67);
			this->YVal_lbl->Name = L"YVal_lbl";
			this->YVal_lbl->Size = System::Drawing::Size(54, 16);
			this->YVal_lbl->TabIndex = 0;
			this->YVal_lbl->Text = L"Y Value";
			// 
			// XVal_lbl
			// 
			this->XVal_lbl->AutoSize = true;
			this->XVal_lbl->Location = System::Drawing::Point(7, 22);
			this->XVal_lbl->Name = L"XVal_lbl";
			this->XVal_lbl->Size = System::Drawing::Size(53, 16);
			this->XVal_lbl->TabIndex = 0;
			this->XVal_lbl->Text = L"X Value";
			// 
			// Debug_lbl
			// 
			this->Debug_lbl->AutoSize = true;
			this->Debug_lbl->Location = System::Drawing::Point(7, 288);
			this->Debug_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Debug_lbl->Name = L"Debug_lbl";
			this->Debug_lbl->Size = System::Drawing::Size(48, 16);
			this->Debug_lbl->TabIndex = 6;
			this->Debug_lbl->Text = L"Debug";
			// 
			// toggle_timer
			// 
			this->toggle_timer->Location = System::Drawing::Point(8, 74);
			this->toggle_timer->Margin = System::Windows::Forms::Padding(4);
			this->toggle_timer->Name = L"toggle_timer";
			this->toggle_timer->Size = System::Drawing::Size(100, 28);
			this->toggle_timer->TabIndex = 5;
			this->toggle_timer->Text = L"Start";
			this->toggle_timer->UseVisualStyleBackColor = true;
			this->toggle_timer->Click += gcnew System::EventHandler(this, &MainForm::toggle_timer_Click);
			// 
			// Interval_txtb
			// 
			this->Interval_txtb->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Value", this->DataSet, L"Parameters.Interval",
				true)));
			this->Interval_txtb->Location = System::Drawing::Point(5, 39);
			this->Interval_txtb->Margin = System::Windows::Forms::Padding(4);
			this->Interval_txtb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->Interval_txtb->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Interval_txtb->Name = L"Interval_txtb";
			this->Interval_txtb->Size = System::Drawing::Size(160, 22);
			this->Interval_txtb->TabIndex = 4;
			this->Interval_txtb->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->Interval_txtb->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown1_ValueChanged);
			// 
			// interval_lbl
			// 
			this->interval_lbl->AutoSize = true;
			this->interval_lbl->Location = System::Drawing::Point(4, 20);
			this->interval_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->interval_lbl->Name = L"interval_lbl";
			this->interval_lbl->Size = System::Drawing::Size(147, 16);
			this->interval_lbl->TabIndex = 3;
			this->interval_lbl->Text = L"Intervalo Amostras (ms)";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Location = System::Drawing::Point(0, 9);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(982, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// SaveFile
			// 
			this->SaveFile->DefaultExt = L"csv";
			this->SaveFile->FileName = L"LogSWCC.csv";
			this->SaveFile->Filter = L"Arquivos \"Comma Sepparated Values\" (*.csv)|*.csv*.*";
			this->SaveFile->Title = L"SWCC - Save Log";
			// 
			// connectionToolStripMenuItem1
			// 
			this->connectionToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->portToolStripMenuItem,
					this->baudToolStripMenuItem
			});
			this->connectionToolStripMenuItem1->Name = L"connectionToolStripMenuItem1";
			this->connectionToolStripMenuItem1->Size = System::Drawing::Size(98, 24);
			this->connectionToolStripMenuItem1->Text = L"Connection";
			// 
			// portToolStripMenuItem
			// 
			this->portToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripPort_cbx });
			this->portToolStripMenuItem->Name = L"portToolStripMenuItem";
			this->portToolStripMenuItem->Size = System::Drawing::Size(126, 26);
			this->portToolStripMenuItem->Text = L"Port";
			// 
			// toolStripPort_cbx
			// 
			this->toolStripPort_cbx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->toolStripPort_cbx->Name = L"toolStripPort_cbx";
			this->toolStripPort_cbx->Size = System::Drawing::Size(121, 28);
			this->toolStripPort_cbx->Sorted = true;
			this->toolStripPort_cbx->DropDownClosed += gcnew System::EventHandler(this, &MainForm::toolStripPort_cbx_DropDownClosed);
			// 
			// baudToolStripMenuItem
			// 
			this->baudToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripBaud_cbx });
			this->baudToolStripMenuItem->Name = L"baudToolStripMenuItem";
			this->baudToolStripMenuItem->Size = System::Drawing::Size(126, 26);
			this->baudToolStripMenuItem->Text = L"Baud";
			// 
			// toolStripBaud_cbx
			// 
			this->toolStripBaud_cbx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->toolStripBaud_cbx->Name = L"toolStripBaud_cbx";
			this->toolStripBaud_cbx->Size = System::Drawing::Size(121, 28);
			this->toolStripBaud_cbx->DropDownClosed += gcnew System::EventHandler(this, &MainForm::toolStripBaud_cbx_DropDownClosed);
			// 
			// connectToolStripMenuItem
			// 
			this->connectToolStripMenuItem->Name = L"connectToolStripMenuItem";
			this->connectToolStripMenuItem->Size = System::Drawing::Size(77, 24);
			this->connectToolStripMenuItem->Text = L"Connect";
			this->connectToolStripMenuItem->BackColorChanged += gcnew System::EventHandler(this, &MainForm::connectToolStripMenuItem_BackColorChanged);
			this->connectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::connectToolStripMenuItem_Click);
			// 
			// logToolStripMenuItem
			// 
			this->logToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->pathToolStripMenuItem });
			this->logToolStripMenuItem->Name = L"logToolStripMenuItem";
			this->logToolStripMenuItem->Size = System::Drawing::Size(48, 24);
			this->logToolStripMenuItem->Text = L"Log";
			// 
			// pathToolStripMenuItem
			// 
			this->pathToolStripMenuItem->AccessibleDescription = L"testessss";
			this->pathToolStripMenuItem->Name = L"pathToolStripMenuItem";
			this->pathToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->pathToolStripMenuItem->Text = L"Path";
			this->pathToolStripMenuItem->ToolTipText = L"testessss";
			this->pathToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pathToolStripMenuItem_Click);
			// 
			// TopMenu
			// 
			this->TopMenu->ImageScalingSize = System::Drawing::Size(32, 32);
			this->TopMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->connectionToolStripMenuItem1,
					this->connectToolStripMenuItem, this->logToolStripMenuItem
			});
			this->TopMenu->Location = System::Drawing::Point(0, 0);
			this->TopMenu->Name = L"TopMenu";
			this->TopMenu->Size = System::Drawing::Size(1163, 28);
			this->TopMenu->TabIndex = 3;
			this->TopMenu->Text = L"menuStrip1";
			// 
			// Dbg_Timer
			// 
			this->Dbg_Timer->Interval = 1000;
			this->Dbg_Timer->Tick += gcnew System::EventHandler(this, &MainForm::timer2_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1163, 575);
			this->Controls->Add(this->TopMenu);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MainMenuStrip = this->TopMenu;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SWCC";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Readdings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Parameters))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConvConst_txtb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefZero_txtb))->EndInit();
			this->Cursor_gbx->ResumeLayout(false);
			this->Cursor_gbx->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Interval_txtb))->EndInit();
			this->TopMenu->ResumeLayout(false);
			this->TopMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		int teste = 0;
	#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void connectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void toolStripPort_cbx_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
		if(toolStripPort_cbx->Text != String::Empty)
			Arduinoo->PortName = toolStripPort_cbx->Text;
	}
	private: System::Void toolStripBaud_cbx_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
		if(toolStripBaud_cbx->Text != String::Empty)
			Arduinoo->BaudRate = Convert::ToInt32(toolStripBaud_cbx->Text);
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toggle_timer_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pathToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void enableToolStripMenuItem_CheckStateChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void WriteLog(System::String^);
	private: System::Void connectToolStripMenuItem_BackColorChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Shown(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void RefZero_txtb_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ConvConst_txtb_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SaveParams();
	private: System::Void LoadParams();
	private: System::Void Dbg_Btn_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}
