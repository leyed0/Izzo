#include "SettingsForm.h"

SWCCWatch::SettingsForm::SettingsForm(System::Data::DataTable^ DR)
{
	InitializeComponent();
	InitializeComponents(DR);
	//
	//TODO: Adicione o código do construtor aqui
	//
	UM_txb->Text = UM_txb->Text->Insert(0, "	")->Insert(0, DateTime::Now.ToLongTimeString())->Insert(0, "	")->Insert(0, DateTime::Now.ToShortDateString());
}

SWCCWatch::SettingsForm::~SettingsForm()
{
	if (components)
	{
		delete components;
	}
}

void SWCCWatch::SettingsForm::InitializeComponents(System::Data::DataTable^ DR)
{
	Datatable = DR;
	COMPort_cbx->Items->AddRange(System::IO::Ports::SerialPort::GetPortNames());
	if (System::IO::File::Exists(File)) {
		Datatable->ReadXml(File);
		Datarow = Datatable->Rows[0];

		Zero_txb->Value = (System::Decimal)Datarow["Zero"];
		UM_txb->Text = (System::String^)Datarow["UM"];
		Constant_Txb->Value = (System::Decimal)Datarow["Constant"];
		Interval_txb->Value = (System::Decimal)Datarow["Interval"];
		COMPort_cbx->SelectedItem = Datarow["COM"];
		Datarow["Baud"] = "9600";
		CSV_btn->Text = (System::String^)Datarow["CSVPath"];
	}
	else {
		//Create the row were the system settings are stored
		Datatable->Rows->Add();
		Datarow = Datatable->Rows[0];

		Datarow["Zero"] = Zero_txb->Value;
		Datarow["UM"] = UM_txb->Text;
		Datarow["Constant"] = Constant_Txb->Text;
		Datarow["Interval"] = Interval_txb->Value;
		Datarow["COM"] = COMPort_cbx->SelectedItem;
		Datarow["Baud"] = "9600";
		Datarow["CSVPath"] = CSV_btn->Text;
	}
	// System::IO::Ports::SerialPort::

	Datatable->RowChanged += gcnew System::Data::DataRowChangeEventHandler(this, &SWCCWatch::SettingsForm::OnRowChanged);
}

void SWCCWatch::SettingsForm::InitializeComponent(void)
{
	this->CSV_lbl = (gcnew System::Windows::Forms::Label());
	this->CSV_btn = (gcnew System::Windows::Forms::Button());
	this->SaveFile = (gcnew System::Windows::Forms::SaveFileDialog());
	this->UM_lbl = (gcnew System::Windows::Forms::Label());
	this->UM_txb = (gcnew System::Windows::Forms::TextBox());
	this->RefZero_lbl = (gcnew System::Windows::Forms::Label());
	this->Constant_lbl = (gcnew System::Windows::Forms::Label());
	this->Interval_lbl = (gcnew System::Windows::Forms::Label());
	this->COMPort_lbl = (gcnew System::Windows::Forms::Label());
	this->Cancel_btn = (gcnew System::Windows::Forms::Button());
	this->Save_btn = (gcnew System::Windows::Forms::Button());
	this->COMPort_cbx = (gcnew System::Windows::Forms::ComboBox());
	this->Zero_txb = (gcnew System::Windows::Forms::NumericUpDown());
	this->Constant_Txb = (gcnew System::Windows::Forms::NumericUpDown());
	this->Interval_txb = (gcnew System::Windows::Forms::NumericUpDown());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Zero_txb))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Constant_Txb))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Interval_txb))->BeginInit();
	this->SuspendLayout();
	// 
	// CSV_lbl
	// 
	this->CSV_lbl->AutoSize = true;
	this->CSV_lbl->Location = System::Drawing::Point(2, 16);
	this->CSV_lbl->Name = L"CSV_lbl";
	this->CSV_lbl->Size = System::Drawing::Size(34, 16);
	this->CSV_lbl->TabIndex = 0;
	this->CSV_lbl->Text = L"CSV";
	// 
	// CSV_btn
	// 
	this->CSV_btn->Location = System::Drawing::Point(42, 13);
	this->CSV_btn->Name = L"CSV_btn";
	this->CSV_btn->Size = System::Drawing::Size(246, 23);
	this->CSV_btn->TabIndex = 1;
	this->CSV_btn->Text = L"Path";
	this->CSV_btn->UseVisualStyleBackColor = true;
	this->CSV_btn->Click += gcnew System::EventHandler(this, &SettingsForm::CSV_btn_Click);
	// 
	// UM_lbl
	// 
	this->UM_lbl->AutoSize = true;
	this->UM_lbl->Location = System::Drawing::Point(2, 45);
	this->UM_lbl->Name = L"UM_lbl";
	this->UM_lbl->Size = System::Drawing::Size(86, 16);
	this->UM_lbl->TabIndex = 2;
	this->UM_lbl->Text = L"Measure Unit";
	// 
	// UM_txb
	// 
	this->UM_txb->Location = System::Drawing::Point(145, 42);
	this->UM_txb->Name = L"UM_txb";
	this->UM_txb->Size = System::Drawing::Size(143, 22);
	this->UM_txb->TabIndex = 3;
	// 
	// RefZero_lbl
	// 
	this->RefZero_lbl->AutoSize = true;
	this->RefZero_lbl->Location = System::Drawing::Point(2, 73);
	this->RefZero_lbl->Name = L"RefZero_lbl";
	this->RefZero_lbl->Size = System::Drawing::Size(102, 16);
	this->RefZero_lbl->TabIndex = 2;
	this->RefZero_lbl->Text = L"Zero Ref (RAW)";
	// 
	// Constant_lbl
	// 
	this->Constant_lbl->AutoSize = true;
	this->Constant_lbl->Location = System::Drawing::Point(2, 101);
	this->Constant_lbl->Name = L"Constant_lbl";
	this->Constant_lbl->Size = System::Drawing::Size(59, 16);
	this->Constant_lbl->TabIndex = 2;
	this->Constant_lbl->Text = L"Constant";
	// 
	// Interval_lbl
	// 
	this->Interval_lbl->AutoSize = true;
	this->Interval_lbl->Location = System::Drawing::Point(2, 129);
	this->Interval_lbl->Name = L"Interval_lbl";
	this->Interval_lbl->Size = System::Drawing::Size(115, 16);
	this->Interval_lbl->TabIndex = 2;
	this->Interval_lbl->Text = L"Sample Rate (ms)";
	// 
	// COMPort_lbl
	// 
	this->COMPort_lbl->AutoSize = true;
	this->COMPort_lbl->Location = System::Drawing::Point(2, 157);
	this->COMPort_lbl->Name = L"COMPort_lbl";
	this->COMPort_lbl->Size = System::Drawing::Size(62, 16);
	this->COMPort_lbl->TabIndex = 2;
	this->COMPort_lbl->Text = L"Com Port";
	// 
	// Cancel_btn
	// 
	this->Cancel_btn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->Cancel_btn->Location = System::Drawing::Point(5, 182);
	this->Cancel_btn->Name = L"Cancel_btn";
	this->Cancel_btn->Size = System::Drawing::Size(134, 23);
	this->Cancel_btn->TabIndex = 4;
	this->Cancel_btn->Text = L"Cancel";
	this->Cancel_btn->UseVisualStyleBackColor = true;
	// 
	// Save_btn
	// 
	this->Save_btn->Location = System::Drawing::Point(154, 182);
	this->Save_btn->Name = L"Save_btn";
	this->Save_btn->Size = System::Drawing::Size(134, 23);
	this->Save_btn->TabIndex = 4;
	this->Save_btn->Text = L"Save";
	this->Save_btn->UseVisualStyleBackColor = true;
	// 
	// COMPort_cbx
	// 
	this->COMPort_cbx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->COMPort_cbx->FormattingEnabled = true;
	this->COMPort_cbx->Location = System::Drawing::Point(145, 153);
	this->COMPort_cbx->Name = L"COMPort_cbx";
	this->COMPort_cbx->Size = System::Drawing::Size(143, 24);
	this->COMPort_cbx->TabIndex = 5;
	// 
	// Zero_txb
	// 
	this->Zero_txb->Location = System::Drawing::Point(145, 70);
	this->Zero_txb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999999, 0, 0, 0 });
	this->Zero_txb->Name = L"Zero_txb";
	this->Zero_txb->Size = System::Drawing::Size(143, 22);
	this->Zero_txb->TabIndex = 6;
	// 
	// Constant_Txb
	// 
	this->Constant_Txb->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
	this->Constant_Txb->Location = System::Drawing::Point(145, 98);
	this->Constant_Txb->Name = L"Constant_Txb";
	this->Constant_Txb->Size = System::Drawing::Size(143, 22);
	this->Constant_Txb->TabIndex = 7;
	// 
	// Interval_txb
	// 
	this->Interval_txb->Location = System::Drawing::Point(145, 126);
	this->Interval_txb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600000000, 0, 0, 0 });
	this->Interval_txb->Name = L"Interval_txb";
	this->Interval_txb->Size = System::Drawing::Size(143, 22);
	this->Interval_txb->TabIndex = 8;
	// 
	// SettingsForm
	// 
	this->AcceptButton = this->Save_btn;
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoSize = true;
	this->CancelButton = this->Cancel_btn;
	this->ClientSize = System::Drawing::Size(300, 214);
	this->ControlBox = false;
	this->Controls->Add(this->Interval_txb);
	this->Controls->Add(this->Constant_Txb);
	this->Controls->Add(this->Zero_txb);
	this->Controls->Add(this->COMPort_cbx);
	this->Controls->Add(this->Save_btn);
	this->Controls->Add(this->Cancel_btn);
	this->Controls->Add(this->COMPort_lbl);
	this->Controls->Add(this->Interval_lbl);
	this->Controls->Add(this->Constant_lbl);
	this->Controls->Add(this->RefZero_lbl);
	this->Controls->Add(this->UM_txb);
	this->Controls->Add(this->UM_lbl);
	this->Controls->Add(this->CSV_btn);
	this->Controls->Add(this->CSV_lbl);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"SettingsForm";
	this->ShowInTaskbar = false;
	this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = L"Settings";
	this->TopMost = true;
	this->Deactivate += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Deactivate);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Zero_txb))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Constant_Txb))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Interval_txb))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void SWCCWatch::SettingsForm::CSV_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SaveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

	}
	CSV_btn->Text = "teste";
	return System::Void();
}


void SWCCWatch::SettingsForm::OnRowChanged(System::Object^ sender, System::Data::DataRowChangeEventArgs^ e)
{
	Datatable->WriteXml(File);
	System::IO::File::SetAttributes(File, System::IO::FileAttributes::Hidden);//
}

System::Void SWCCWatch::SettingsForm::SettingsForm_Deactivate(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
