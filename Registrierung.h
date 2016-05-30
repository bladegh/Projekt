#pragma once

namespace VorlageWindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;



	public ref class Registrierung : public System::Windows::Forms::Form
	{
	public:
		Registrierung(OleDbConnection^ verbindung)
		{
			
			InitializeComponent();

			this->verbindung = verbindung; 

			oeffneDatenbank(); 
			leseDatenbank(); 

		}


	protected:
		~Registrierung()
		{
			if (components)
			{
				delete components;
			}
		}


	private: 
	 System::Windows::Forms::Label^  label_name;
	 System::Windows::Forms::Label^  label_passwort;
	 System::Windows::Forms::Label^  label_passwort_wdh;
	 System::Windows::Forms::TextBox^  txt_name;
	 System::Windows::Forms::TextBox^  txt_passwort_wdh;
	 System::Windows::Forms::TextBox^  txt_passwort;
	 System::Windows::Forms::Button^  button_reg;
	 System::Windows::Forms::Button^  button_abbrechen;
	 System::ComponentModel::Container ^components;

	 OleDbConnection^ verbindung; 
	 DataTable^ userTab;  
	 OleDbDataAdapter^ adapter;
	 OleDbCommand^ getUserTable; 
	 OleDbTransaction ^transaktion; 
	 OleDbCommand ^schreibeUser; 



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->label_passwort = (gcnew System::Windows::Forms::Label());
			this->label_passwort_wdh = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_passwort_wdh = (gcnew System::Windows::Forms::TextBox());
			this->txt_passwort = (gcnew System::Windows::Forms::TextBox());
			this->button_reg = (gcnew System::Windows::Forms::Button());
			this->button_abbrechen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Location = System::Drawing::Point(19, 46);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(75, 13);
			this->label_name->TabIndex = 0;
			this->label_name->Text = L"Benutzername";
			// 
			// label_passwort
			// 
			this->label_passwort->AutoSize = true;
			this->label_passwort->Location = System::Drawing::Point(19, 117);
			this->label_passwort->Name = L"label_passwort";
			this->label_passwort->Size = System::Drawing::Size(50, 13);
			this->label_passwort->TabIndex = 1;
			this->label_passwort->Text = L"Passwort";
			// 
			// label_passwort_wdh
			// 
			this->label_passwort_wdh->AutoSize = true;
			this->label_passwort_wdh->Location = System::Drawing::Point(19, 157);
			this->label_passwort_wdh->Name = L"label_passwort_wdh";
			this->label_passwort_wdh->Size = System::Drawing::Size(110, 13);
			this->label_passwort_wdh->TabIndex = 2;
			this->label_passwort_wdh->Text = L"Passwort wiederholen";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(145, 46);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(111, 20);
			this->txt_name->TabIndex = 3;
			// 
			// txt_passwort_wdh
			// 
			this->txt_passwort_wdh->Location = System::Drawing::Point(145, 150);
			this->txt_passwort_wdh->Name = L"txt_passwort_wdh";
			this->txt_passwort_wdh->PasswordChar = '*';
			this->txt_passwort_wdh->Size = System::Drawing::Size(111, 20);
			this->txt_passwort_wdh->TabIndex = 4;
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(145, 110);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->PasswordChar = '*';
			this->txt_passwort->Size = System::Drawing::Size(111, 20);
			this->txt_passwort->TabIndex = 5;
			// 
			// button_reg
			// 
			this->button_reg->Location = System::Drawing::Point(22, 214);
			this->button_reg->Name = L"button_reg";
			this->button_reg->Size = System::Drawing::Size(88, 23);
			this->button_reg->TabIndex = 6;
			this->button_reg->Text = L"Registrieren ";
			this->button_reg->UseVisualStyleBackColor = true;
			this->button_reg->Click += gcnew System::EventHandler(this, &Registrierung::button_reg_Click);
			// 
			// button_abbrechen
			// 
			this->button_abbrechen->Location = System::Drawing::Point(145, 214);
			this->button_abbrechen->Name = L"button_abbrechen";
			this->button_abbrechen->Size = System::Drawing::Size(88, 23);
			this->button_abbrechen->TabIndex = 7;
			this->button_abbrechen->Text = L"Abbrechen";
			this->button_abbrechen->UseVisualStyleBackColor = true;
			this->button_abbrechen->Click += gcnew System::EventHandler(this, &Registrierung::button_abbrechen_Click);
			// 
			// Registrierung
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button_abbrechen);
			this->Controls->Add(this->button_reg);
			this->Controls->Add(this->txt_passwort);
			this->Controls->Add(this->txt_passwort_wdh);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->label_passwort_wdh);
			this->Controls->Add(this->label_passwort);
			this->Controls->Add(this->label_name);
			this->Name = L"Registrierung";
			this->Text = L"Registrierung";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion






	private:


		void oeffneDatenbank()
			{
			
				//Öffnet Datenbank

				try
				{
					verbindung->Open();			
				}
				catch(Exception^ fehler)
				{
					MessageBox::Show("Fehler beim öffnen: " + fehler->Message);
					
				}
			
			}//end oeffneDatenbanl





			void leseDatenbank()
			{
				//Liest die User-Tabelle ein

				userTab = gcnew DataTable;
				adapter = gcnew OleDbDataAdapter;
				getUserTable = gcnew OleDbCommand; 
				getUserTable->Connection = verbindung;

				getUserTable->CommandText= "SELECT * FROM test";
				adapter->SelectCommand = getUserTable;
				adapter->Fill(userTab);
			
			}




		
		System::Void button_reg_Click(System::Object^  sender, System::EventArgs^  e) 
	    {

			String ^name = txt_name->Text; 
			String ^passwort = txt_passwort->Text; 
			String ^passwort_wdh = txt_passwort_wdh->Text; 
			String ^user; 
			String ^hashVal = passwort->GetHashCode().ToString();

			schreibeUser = gcnew OleDbCommand(); 


			bool possible = true;

			for(int i=0; i<userTab->Rows->Count;i++)
			{
				user = (String^)(userTab->Rows[i]->ItemArray[1]);

				if(user==name)
				{
					MessageBox::Show("Fehler: \nName schon vergeben! ");  
					possible=false; 
				}

			}


			if(possible==true)
			{
				//Username frei! 

				if(passwort==passwort_wdh)
				{
					
					transaktion=verbindung->BeginTransaction(); 
					schreibeUser->Connection = verbindung; 

					

					schreibeUser ->CommandText = "INSERT INTO test(Username,Passwort) VALUES('"+name+"','"+hashVal+"')"; 

					schreibeUser -> Transaction = transaktion; 
					schreibeUser -> ExecuteNonQuery(); 

					transaktion -> Commit(); 

					MessageBox::Show("User angelegt! ");

					verbindung->Close(); 
					this->Close(); 


				}
				else
				{
					MessageBox::Show("Fehler: \nPasswort nicht korrekt wiederholt ");
				}

			
			}



		}

	 System::Void button_abbrechen_Click(System::Object^  sender, System::EventArgs^  e) 
	 {
		 verbindung->Close(); 
		 this->Close(); 
	 }


};//end class

}//end namespace 
