#include "MainWindow.h"
#include "SettingsForm.h"
using namespace System;
using namespace System::Windows::Forms;


SWCCWatch::MainWindow::MainWindow(void)
{
	InitializeComponent();
	//
	//TODO: Adicione o código do construtor aqui
	//
	InitializeSettings();
	InitializeComponents();
	//this->SettForm->Location = System::Drawing::Point(0, 0);
}

SWCCWatch::MainWindow::~MainWindow()
{
	if (components)
	{
		delete components;
	}
}

void SWCCWatch::MainWindow::InitializeSettings(void) {
}

void SWCCWatch::MainWindow::InitializeComponents(void) {
	this->SettForm = gcnew SettingsForm(DataSet->Tables["Parameters"]);
	//Event Handler for Dataset "Readdings" new row event
	DataSet->Tables["Readdings"]->TableNewRow += gcnew System::Data::DataTableNewRowEventHandler(this, &MainWindow::ReaddingsNewRow);
	//DataSet->Tables["Readdings"]->RowChanged += gcnew System::Data::DataRowChangeEventHandler(this, &MainWindow::NewReadding);


	//DataSet Structure:
	//Readdings:
	//	DateTime
	//	Raw
	//	Treated
	//Parameters :
	//	Zero
	//	UM
	//	Constant
	//	Interval
	//	COM
	//	Baud
	//	CSVPath
}

void SWCCWatch::MainWindow::InitializeComponent(void)
{
	this->components = (gcnew System::ComponentModel::Container());
	System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
	System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
	this->Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
	this->DataSet = (gcnew System::Data::DataSet());
	this->Readdings = (gcnew System::Data::DataTable());
	this->DateTime = (gcnew System::Data::DataColumn());
	this->Raw = (gcnew System::Data::DataColumn());
	this->Treated = (gcnew System::Data::DataColumn());
	this->Parameters = (gcnew System::Data::DataTable());
	this->Zero = (gcnew System::Data::DataColumn());
	this->UM = (gcnew System::Data::DataColumn());
	this->Constant = (gcnew System::Data::DataColumn());
	this->Interval = (gcnew System::Data::DataColumn());
	this->COM = (gcnew System::Data::DataColumn());
	this->Baud = (gcnew System::Data::DataColumn());
	this->CSVPath = (gcnew System::Data::DataColumn());
	this->Arduino = (gcnew System::IO::Ports::SerialPort(this->components));
	this->StatusBar = (gcnew System::Windows::Forms::ToolStrip());
	this->StatusBarSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->SettingsMenu = (gcnew System::Windows::Forms::ToolStripButton());
	this->YAxVal_lbl = (gcnew System::Windows::Forms::ToolStripLabel());
	this->StatusBarSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->XAxVal_lbl = (gcnew System::Windows::Forms::ToolStripLabel());
	this->StatusBarSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->SampleTimer = (gcnew System::Windows::Forms::Timer(this->components));
	this->DebugTimer = (gcnew System::Windows::Forms::Timer(this->components));
	this->BackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataSet))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Readdings))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Parameters))->BeginInit();
	this->StatusBar->SuspendLayout();
	this->SuspendLayout();
	// 
	// Chart
	// 
	chartArea1->AxisY->Minimum = 0;
	chartArea1->Name = L"ChartArea1";
	this->Chart->ChartAreas->Add(chartArea1);
	this->Chart->DataSource = this->DataSet;
	this->Chart->Dock = System::Windows::Forms::DockStyle::Fill;
	this->Chart->Location = System::Drawing::Point(0, 0);
	this->Chart->Name = L"Chart";
	series1->ChartArea = L"ChartArea1";
	series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
	series1->Name = L"Series1";
	series1->XValueMember = L"DateTime";
	series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
	series1->YValueMembers = L"Treated";
	this->Chart->Series->Add(series1);
	this->Chart->Size = System::Drawing::Size(782, 553);
	this->Chart->TabIndex = 0;
	this->Chart->TabStop = false;
	this->Chart->Text = L"Chart";
	this->Chart->MouseHover += gcnew System::EventHandler(this, &MainWindow::Chart_MouseHover);
	this->Chart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::Chart_MouseMove);
	// 
	// DataSet
	// 
	this->DataSet->DataSetName = L"DataSet";
	this->DataSet->Tables->AddRange(gcnew cli::array< System::Data::DataTable^  >(2) { this->Readdings, this->Parameters });
	// 
	// Readdings
	// 
	this->Readdings->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(3) { this->DateTime, this->Raw, this->Treated });
	this->Readdings->TableName = L"Readdings";
	// 
	// DateTime
	// 
	this->DateTime->ColumnName = L"DateTime";
	this->DateTime->DataType = System::DateTime::typeid;
	// 
	// Raw
	// 
	this->Raw->ColumnName = L"Raw";
	this->Raw->DataType = System::Int32::typeid;
	// 
	// Treated
	// 
	this->Treated->ColumnName = L"Treated";
	this->Treated->DataType = System::Double::typeid;
	// 
	// Parameters
	// 
	this->Parameters->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(7) {
		this->Zero, this->UM, this->Constant,
			this->Interval, this->COM, this->Baud, this->CSVPath
	});
	this->Parameters->MinimumCapacity = 5;
	this->Parameters->TableName = L"Parameters";
	// 
	// Zero
	// 
	this->Zero->ColumnName = L"Zero";
	this->Zero->DataType = System::Decimal::typeid;
	this->Zero->DefaultValue = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	// 
	// UM
	// 
	this->UM->ColumnName = L"UM";
	// 
	// Constant
	// 
	this->Constant->ColumnName = L"Constant";
	this->Constant->DataType = System::Decimal::typeid;
	this->Constant->DefaultValue = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	// 
	// Interval
	// 
	this->Interval->ColumnName = L"Interval";
	this->Interval->DataType = System::Decimal::typeid;
	this->Interval->DefaultValue = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60000, 0, 0, 0 });
	// 
	// COM
	// 
	this->COM->ColumnName = L"COM";
	// 
	// Baud
	// 
	this->Baud->ColumnName = L"Baud";
	this->Baud->DefaultValue = L"9600";
	// 
	// CSVPath
	// 
	this->CSVPath->ColumnName = L"CSVPath";
	// 
	// StatusBar
	// 
	this->StatusBar->Dock = System::Windows::Forms::DockStyle::Bottom;
	this->StatusBar->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
	this->StatusBar->ImageScalingSize = System::Drawing::Size(20, 20);
	this->StatusBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
		this->StatusBarSeparator3,
			this->SettingsMenu, this->YAxVal_lbl, this->StatusBarSeparator1, this->XAxVal_lbl, this->StatusBarSeparator2
	});
	this->StatusBar->Location = System::Drawing::Point(0, 526);
	this->StatusBar->Name = L"StatusBar";
	this->StatusBar->Size = System::Drawing::Size(782, 27);
	this->StatusBar->Stretch = true;
	this->StatusBar->TabIndex = 4;
	this->StatusBar->Text = L"StatusBar";
	// 
	// StatusBarSeparator3
	// 
	this->StatusBarSeparator3->Name = L"StatusBarSeparator3";
	this->StatusBarSeparator3->Size = System::Drawing::Size(6, 27);
	// 
	// SettingsMenu
	// 
	this->SettingsMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->SettingsMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsMenu.Image")));
	this->SettingsMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
	this->SettingsMenu->Name = L"SettingsMenu";
	this->SettingsMenu->Size = System::Drawing::Size(66, 24);
	this->SettingsMenu->Text = L"Settings";
	this->SettingsMenu->Click += gcnew System::EventHandler(this, &MainWindow::SettingsMenu_Click);
	// 
	// YAxVal_lbl
	// 
	this->YAxVal_lbl->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
	this->YAxVal_lbl->Name = L"YAxVal_lbl";
	this->YAxVal_lbl->Size = System::Drawing::Size(59, 24);
	this->YAxVal_lbl->Text = L"Y: 0,000";
	this->YAxVal_lbl->ToolTipText = L"Y Axis Value";
	// 
	// StatusBarSeparator1
	// 
	this->StatusBarSeparator1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
	this->StatusBarSeparator1->Name = L"StatusBarSeparator1";
	this->StatusBarSeparator1->Size = System::Drawing::Size(6, 27);
	// 
	// XAxVal_lbl
	// 
	this->XAxVal_lbl->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
	this->XAxVal_lbl->Name = L"XAxVal_lbl";
	this->XAxVal_lbl->Size = System::Drawing::Size(159, 24);
	this->XAxVal_lbl->Text = L"X: 00/00/0000 00:00:00";
	this->XAxVal_lbl->ToolTipText = L"X Axis Value";
	// 
	// StatusBarSeparator2
	// 
	this->StatusBarSeparator2->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
	this->StatusBarSeparator2->Name = L"StatusBarSeparator2";
	this->StatusBarSeparator2->Size = System::Drawing::Size(6, 27);
	// 
	// DebugTimer
	// 
	this->DebugTimer->Tick += gcnew System::EventHandler(this, &MainWindow::DebugTimer_Tick);
	// 
	// BackgroundWorker
	// 
	this->BackgroundWorker->WorkerReportsProgress = true;
	this->BackgroundWorker->WorkerSupportsCancellation = true;
	// 
	// MainWindow
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(782, 553);
	this->Controls->Add(this->StatusBar);
	this->Controls->Add(this->Chart);
	this->Name = L"MainWindow";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"SWCC Watch";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataSet))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Readdings))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Parameters))->EndInit();
	this->StatusBar->ResumeLayout(false);
	this->StatusBar->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void SWCCWatch::MainWindow::SettingsMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SettForm == nullptr || SettForm->IsDisposed) {
		this->SettForm = gcnew SettingsForm(DataSet->Tables["Parameters"]);
	}
	if (!SettForm->Visible) {
		this->SettForm->SetDesktopLocation(this->DesktopLocation.X + 8, this->Bottom - 35 - this->SettForm->Height);
	}
	SettForm->Visible = !SettForm->Visible;
    return System::Void();
}

System::Void SWCCWatch::MainWindow::Chart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{	
	System::Drawing::PointF mousePoint(e->X, e->Y);
	Chart->ChartAreas[0]->CursorX->Interval = 0;
	Chart->ChartAreas[0]->CursorY->Interval = 0;
	Chart->ChartAreas[0]->CursorX->SetCursorPixelPosition(mousePoint, true);
	Chart->ChartAreas[0]->CursorY->SetCursorPixelPosition(mousePoint, true);
	System::Windows::Forms::DataVisualization::Charting::HitTestResult^ result = Chart->HitTest(e->X, e->Y);

	if (result->PointIndex > -1 && result->ChartArea != nullptr) {
		XAxVal_lbl->Text = "X: " + DateTime::FromOADate(result->Series->Points[result->PointIndex]->XValue).ToString();
		YAxVal_lbl->Text = "Y: "+result->Series->Points[result->PointIndex]->YValues[0].ToString();
	}
}

System::Void SWCCWatch::MainWindow::Chart_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void SWCCWatch::MainWindow::DebugTimer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	//System::Data::DataRow^ dt = DataSet->Tables["Readdings"]->NewRow();
	System::Data::DataRow^ dt = DataSet->Tables["Readdings"]->Rows[DataSet->Tables["Readdings"]->Rows->Count-1];
	int val = (int)dt["Raw"] + Random().Next() % 10;
	dt = DataSet->Tables["Readdings"]->NewRow();
	//int val = Random().Next() % 500;
	dt["DateTime"] = System::DateTime::Now;
	dt["Raw"] = val;
	dt["Treated"] = (double)val / 1000;

	DataSet->Tables["Readdings"]->Rows->Add(dt);
	return System::Void();
}

System::Void SWCCWatch::MainWindow::ReaddingsNewRow(System::Object^ sender, System::Data::DataTableNewRowEventArgs^ e) {
	Chart->DataBind();
	return;
}