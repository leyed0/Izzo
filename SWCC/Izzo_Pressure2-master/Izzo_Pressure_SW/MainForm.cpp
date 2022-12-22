#include "MainForm.h"
#include "Parametros.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //WinformCDemo is your project name
    Izzo::MainForm form;
    Application::Run(% form);
}

System::Void Izzo::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadParams();
	toolStripPort_cbx->Items->AddRange(Arduinoo->GetPortNames());
	toolStripBaud_cbx->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
		L"1200", L"2400", L"4800", L"9600", L"19200", L"38400",
			L"57600", L"115200"
	});
	//toolStripPort_cbx->SelectedItem->ToString();
	Arduinoo = gcnew System::IO::Ports::SerialPort();
}

System::Void Izzo::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	try {
		Arduinoo->Write("R");
		if (Arduinoo->BytesToRead > 0) {
			System::String^ readding = Arduinoo->ReadExisting();
			readding = readding->Replace("\r\n", "");
			//System::Int16 value = Convert::ToInt16(readding);
			Debug_lbl->Text = readding;
			//chart1->Series["UM"]->Points->AddY(value);

			System::Data::DataRow^ dt = DataSet->Tables["Readdings"]->NewRow();
			dt["DateTime"] = System::DateTime::Now;
			dt["Read"] = Convert::ToInt32(readding);
			dt["Val"] = Parametros::ColAgua(Convert::ToInt16(readding));

			DataSet->Tables["Readdings"]->Rows->Add(dt);
			//chart1->DataBind();

			//DataSet.xml

			if (enableToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
				//WriteLog(Convert::ToString(value));
				readding = readding->Insert(0, "	")->Insert(0, DateTime::Now.ToLongTimeString())->Insert(0, "	")->Insert(0, DateTime::Now.ToShortDateString());
				if (enableToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) File->WriteLine(readding);
			}
		}
	}
	catch(Exception^ ex) {
		
		timer1_Tick(sender, e);
	}
	chart1->DataBind();
}

System::Void Izzo::MainForm::connectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Arduinoo->IsOpen) {
		Arduinoo->Close();
		connectToolStripMenuItem->BackColor = System::Drawing::Color::Red;
	}
	else
	{
		if (toolStripPort_cbx->Text != "" && toolStripBaud_cbx->Text != "") {
			Arduinoo->Open();
			Arduinoo->ReadTimeout = 500;
			System::String^ write = "A";
			Arduinoo->Write(write);
			
			if (Arduinoo->BytesToRead > 0) {
				System::String^ resp = Arduinoo->ReadExisting();
				if (resp) {
					connectToolStripMenuItem->BackColor = System::Drawing::Color::Green;
				}
				else
				{
					connectToolStripMenuItem->BackColor = System::Drawing::Color::Orange;
				}
			}
			/*else
			{
				connectToolStripMenuItem->BackColor = System::Drawing::Color::Red;
			}*/
		}
		else
		{
		}
	}
}

System::Void Izzo::MainForm::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Interval = Convert::ToInt32(Interval_txtb->Value);
	return System::Void();
}

System::Void Izzo::MainForm::toggle_timer_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (timer1->Enabled) {
		timer1->Stop();
		toggle_timer->Text = "Start";
		if (enableToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) File->Close();
	}
	else
	{
		timer1->Start();
		toggle_timer->Text = "Stop";
		if (enableToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
			File = gcnew System::IO::StreamWriter(pathToolStripMenuItem->ToolTipText + "\\" + DateTime::Now.ToString()->Replace(" ", "_")->Replace("/", "-")->Replace(":", "-") + ".csv", true, System::Text::Encoding::UTF8);
			File->WriteLine("Date	Time	Value");
		}
	}
	return System::Void();
}

System::Void Izzo::MainForm::pathToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	Debug_lbl->Text = SaveFile->ShowDialog().ToString();
	
	/*if (System::IO::File::Exists(SaveFile->FileName)) {
		Debug_lbl->Text = "existe";
	}*/
	
	folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pathToolStripMenuItem->ToolTipText = folderBrowserDialog1->SelectedPath;
		enableToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
	}
	else
		enableToolStripMenuItem->Checked = false;
}

System::Void Izzo::MainForm::enableToolStripMenuItem_CheckStateChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (enableToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) if (!System::IO::Directory::Exists(pathToolStripMenuItem->ToolTipText)) {
		pathToolStripMenuItem_Click(sender, e);
	}
	else {
		//pathToolStripMenuItem->ToolTipText = System::String::Empty;
	}
}

System::Void Izzo::MainForm::WriteLog(System::String ^line)
{
	System::IO::TextWriter^ teste = gcnew System::IO::StreamWriter(pathToolStripMenuItem->ToolTipText, true);

	return System::Void();
}

System::Void Izzo::MainForm::connectToolStripMenuItem_BackColorChanged(System::Object^ sender, System::EventArgs^ e)
{

	if(connectToolStripMenuItem->BackColor == System::Drawing::Color::Green)	toggle_timer->Enabled = true;
	else toggle_timer->Enabled = false;
	return System::Void();
}

System::Void Izzo::MainForm::MainForm_Shown(System::Object^ sender, System::EventArgs^ e)
{
	//chart1->Series["UM"]->Points->AddY(1211.97);

	return System::Void();
}

System::Void Izzo::MainForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	//chart1->Series.
	chart1->Series->FindByName("UM")->LegendText = UM_txb->Text;
	chart1->ChartAreas->FindByName("Main")->AxisY->Title = UM_txb->Text;
	//chart1->ChartAreas->FindByName("Main")->CursorX.
	return System::Void();
}

System::Void Izzo::MainForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{ 
	System::Data::DataRow ^dt = DataSet->Tables["Readdings"]->NewRow();
	int val = Random().Next() % 500;
	dt["DateTime"] = System::DateTime::Now;
	dt["Read"] = val;
	dt["Val"] = (double)val/1000;

	DataSet->Tables["Readdings"]->Rows->Add(dt);
	//chart1.datab
	chart1->DataBind();
	return System::Void();
}

System::Void Izzo::MainForm::chart1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	System::Drawing::PointF mousePoint(e->X, e->Y);
	chart1->ChartAreas[0]->CursorX->Interval = 0;
	chart1->ChartAreas[0]->CursorY->Interval = 0;
	chart1->ChartAreas[0]->CursorX->SetCursorPixelPosition(mousePoint, true);
	chart1->ChartAreas[0]->CursorY->SetCursorPixelPosition(mousePoint, true);
	System::Windows::Forms::DataVisualization::Charting::HitTestResult^ result = chart1->HitTest(e->X, e->Y);
	
	if (result->PointIndex > -1 && result->ChartArea != nullptr) {
		YVal_lbl->Text = result->Series->Points[result->PointIndex]->YValues[0].ToString();
		XVal_lbl->Text = DateTime::FromOADate(result->Series->Points[result->PointIndex]->XValue).ToString();
	}

	return System::Void();
}

System::Void Izzo::MainForm::RefZero_txtb_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Parametros::zero = Convert::ToInt64(RefZero_txtb->Text);
	return System::Void();
}


System::Void Izzo::MainForm::ConvConst_txtb_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Parametros::constante = Convert::ToDouble(ConvConst_txtb->Text);
	return System::Void();
}

System::Void Izzo::MainForm::SaveParams()
{
	DataRow^ dt = DataSet->Tables["Parameters"]->NewRow();

	dt = DataSet->Tables["Parameters"]->NewRow();

	dt["Zero"] = RefZero_txtb->Value;
	dt["UM"] = UM_txb->Text;
	dt["Constant"] = ConvConst_txtb->Value;
	dt["Interval"] = Interval_txtb->Value;
	dt["COM"] = toolStripPort_cbx->Text;
	dt["Baud"] = toolStripBaud_cbx->Text;
	dt["CSVPath"] = pathToolStripMenuItem->ToolTipText;

	//DataSet->Tables["Parameters"]->Rows[0]
	//DataSet->Tables["Parameters"]->Rows[0]["Zero"] = 0;

	if (DataSet->Tables["Parameters"]->Rows->Count != 0)
	{
		DataSet->Tables["Parameters"]->Rows->Clear();
	}
	DataSet->Tables["Parameters"]->Rows->Add(dt);

	DataSet->Tables["Parameters"]->WriteXml("Parameters.xml");
	/*try {
		System::IO::File::SetAttributes("Parameters.xml", System::IO::FileAttributes::Hidden);
	}
	catch (System::Exception^ e) {
		return System::Void();
	}*/
	return System::Void();
}

System::Void Izzo::MainForm::LoadParams()
{
	try {
		if (System::IO::File::Exists("Parameters.xml")) {
			DataSet->Tables["Parameters"]->ReadXml("Parameters.xml");
			DataRow^ dt = DataSet->Tables["Parameters"]->Rows[0];

			RefZero_txtb->Value = (System::Decimal)dt["Zero"];
			UM_txb->Text = (System::String^)dt["UM"];
			ConvConst_txtb->Value = (System::Decimal)dt["Constant"];
			Interval_txtb->Value = (System::Decimal)dt["Interval"];
			toolStripPort_cbx->Text = (System::String^)dt["COM"];
			toolStripBaud_cbx->Text = (System::String^)dt["Baud"];
			pathToolStripMenuItem->ToolTipText = (System::String^)dt["CSVPath"];


			//RefZero_txtb->Value = (System::Decimal)DataSet->Tables["Parameters"]->Rows[0]->ItemArray[0];
		}
		else
		{
			
		}
	}
	catch (System::Exception ^e) {
		return System::Void();
	}
	return System::Void();
}

System::Void Izzo::MainForm::Dbg_Btn_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	SaveParams();
	//chart1->Refresh();
	//chart1->DataBind();
	//LoadParams();
	return System::Void();
}
