#pragma once

namespace SWCCWatch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(System::Data::DataTable^ DR);

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~SettingsForm();
	private: System::Windows::Forms::Label^ CSV_lbl;
	private: System::Windows::Forms::Button^ CSV_btn;
	private: System::Windows::Forms::SaveFileDialog^ SaveFile;
	private: System::Windows::Forms::Label^ UM_lbl;
	private: System::Windows::Forms::TextBox^ UM_txb;
	private: System::Windows::Forms::Label^ RefZero_lbl;
	private: System::Windows::Forms::Label^ Constant_lbl;
	private: System::Windows::Forms::Label^ Interval_lbl;
	private: System::Windows::Forms::Label^ COMPort_lbl;
	private: System::Windows::Forms::Button^ Cancel_btn;
	private: System::Windows::Forms::Button^ Save_btn;
	private: System::Windows::Forms::ComboBox^ COMPort_cbx;
	private: System::Windows::Forms::NumericUpDown^ Zero_txb;
	private: System::Windows::Forms::NumericUpDown^ Constant_Txb;
	private: System::Windows::Forms::NumericUpDown^ Interval_txb;



	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Data::DataTable^ Datatable;
	private: System::Data::DataRow^ Datarow;
	private: System::String^ File = "Settings.xml";
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void);
		void InitializeComponents(System::Data::DataTable^ DR);
#pragma endregion
	private: System::Void CSV_btn_Click(System::Object^ sender, System::EventArgs^ e);
		   void OnRowChanged(System::Object^ sender, System::Data::DataRowChangeEventArgs^ e);
	private: System::Void SettingsForm_Deactivate(System::Object^ sender, System::EventArgs^ e);
	};
}
