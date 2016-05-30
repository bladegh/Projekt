#pragma once

namespace VorlageWindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb; 

	/// <summary>
	/// Zusammenfassung für MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			verbindung = "Provider = Microsoft.ACE.OLEDB.12.0; Data Source = H:\\Projekt\\WG_neu.accdb";
			dbVerbindung = gcnew OleDbConnection(verbindung); 
			befehl = gcnew OleDbCommand;
		}



		void open()
		{
		
			try{
			
				dbVerbindung->Open(); 
				MessageBox::Show("Verbunden");
			
			
			}
			catch(Exception ^fehler)
			{
			
				MessageBox::Show("Konnte nicht geöffnet werden"); 
			
			}
		
		
		
		}


		void read(void)
		{
			
			DataTable ^tab = gcnew DataTable;
			OleDbDataAdapter ^adapter = gcnew OleDbDataAdapter; 
			befehl->Connection = dbVerbindung; 
			befehl->CommandText = "SELECT * FROM User('UserName')";
			adapter->SelectCommand = befehl;

			adapter->Fill(tab); 

		
		}



	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

		String ^verbindung; 
		OleDbConnection ^dbVerbindung; 
	private: System::Windows::Forms::Button^  button1;
			 OleDbCommand ^befehl; 
	



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(108, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion








	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				 open(); 
				 read(); 


			 }
};
}
