#pragma once
#include "SettingsForm.h"

namespace SWCCWatch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void);

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MainWindow();
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ Chart;
	private: System::ComponentModel::IContainer^ components;
	private: System::Data::DataSet^ DataSet;
	private: System::Data::DataTable^ ChartData;
	private: System::Data::DataTable^ Readdings;
	private: System::Data::DataColumn^ DateTime;
	private: System::Data::DataColumn^ Raw;
	private: System::Data::DataColumn^ Treated;
	private: System::Data::DataTable^ Parameters;
	private: System::Data::DataColumn^ Zero;
	private: System::Data::DataColumn^ UM;
	private: System::Data::DataColumn^ Constant;
	private: System::Data::DataColumn^ Interval;
	private: System::Data::DataColumn^ COM;
	private: System::Data::DataColumn^ Baud;
	private: System::Data::DataColumn^ CSVPath;
	private: System::IO::Ports::SerialPort^ Arduino;
	private: System::Windows::Forms::ToolStrip^ StatusBar;
	private: System::Windows::Forms::ToolStripButton^ SettingsMenu;
	private: System::Windows::Forms::ToolStripLabel^ YAxVal_lbl;
	private: System::Windows::Forms::ToolStripSeparator^ StatusBarSeparator1;

	private: System::Windows::Forms::ToolStripLabel^ XAxVal_lbl;
	private: System::Windows::Forms::ToolStripSeparator^ StatusBarSeparator2;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^ StatusBarSeparator3;
	private: System::Windows::Forms::Timer^ SampleTimer;
	private: System::Windows::Forms::Timer^ DebugTimer;


		   //Custom Form created for setting the system settings - stored at Dataset "Parameters" only Row
	private: SettingsForm^ SettForm;
	private: System::ComponentModel::BackgroundWorker^ BackgroundWorker;
	private: System::String^ ParametersFile = "Parameters.xml";
		   /// <summary>
		   /// Variável de designer necessária.
		   /// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		   void InitializeComponent(void);
		   /// <summary>
		   /// Mesma finalidade do metodo InitializeComponent() editavel em codigo
		   /// </summary>
		   void InitializeComponents(void);
		   void InitializeSettings(void);
#pragma endregion
	private: System::Void SettingsMenu_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void DebugTimer_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Chart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void Chart_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ReaddingsNewRow(System::Object^ sender, System::Data::DataTableNewRowEventArgs^ e);
	//private: System::Void BackgroundWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
	};
}
