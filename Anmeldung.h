#pragma once

#include "Registrierung.h"
#include "Dashboard.h"

namespace VorlageWindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std; 
	using namespace System::Data::OleDb; 


	//#include <functional>


	public ref class Anmeldung : public System::Windows::Forms::Form
	{
	public:
		Anmeldung(OleDbConnection^ verbindung)
		{
			
			InitializeComponent();

			this->verbindung = verbindung; 
			

		}

	protected:

		~Anmeldung()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
	 System::Windows::Forms::Label^  label_header;
	 System::Windows::Forms::Label^  label_benutzer;
	 System::Windows::Forms::Label^  label_passwort;
	 System::Windows::Forms::TextBox^  txt_name;
	 System::Windows::Forms::TextBox^  txt_passwort;
	 System::Windows::Forms::Button^  button_registrieren;
	 System::Windows::Forms::Button^  button_anmelden;
	 System::ComponentModel::Container ^components;

	 OleDbConnection^ verbindung; 
	 DataTable^ userTab;  
	 OleDbDataAdapter^ adapter;
	 OleDbCommand^ getUserTable; 
	 		



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label_header = (gcnew System::Windows::Forms::Label());
			this->label_benutzer = (gcnew System::Windows::Forms::Label());
			this->label_passwort = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_passwort = (gcnew System::Windows::Forms::TextBox());
			this->button_registrieren = (gcnew System::Windows::Forms::Button());
			this->button_anmelden = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_header
			// 
			this->label_header->AutoSize = true;
			this->label_header->Location = System::Drawing::Point(36, 18);
			this->label_header->Name = L"label_header";
			this->label_header->Size = System::Drawing::Size(60, 13);
			this->label_header->TabIndex = 0;
			this->label_header->Text = L"Anmeldung";
			// 
			// label_benutzer
			// 
			this->label_benutzer->AutoSize = true;
			this->label_benutzer->Location = System::Drawing::Point(36, 83);
			this->label_benutzer->Name = L"label_benutzer";
			this->label_benutzer->Size = System::Drawing::Size(49, 13);
			this->label_benutzer->TabIndex = 1;
			this->label_benutzer->Text = L"Benutzer";
			// 
			// label_passwort
			// 
			this->label_passwort->AutoSize = true;
			this->label_passwort->Location = System::Drawing::Point(36, 138);
			this->label_passwort->Name = L"label_passwort";
			this->label_passwort->Size = System::Drawing::Size(50, 13);
			this->label_passwort->TabIndex = 2;
			this->label_passwort->Text = L"Passwort";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(105, 83);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(115, 20);
			this->txt_name->TabIndex = 3;
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(105, 135);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->PasswordChar = '*';
			this->txt_passwort->Size = System::Drawing::Size(115, 20);
			this->txt_passwort->TabIndex = 4;
			// 
			// button_registrieren
			// 
			this->button_registrieren->Location = System::Drawing::Point(162, 204);
			this->button_registrieren->Name = L"button_registrieren";
			this->button_registrieren->Size = System::Drawing::Size(100, 22);
			this->button_registrieren->TabIndex = 5;
			this->button_registrieren->Text = L"Benutzer anlegen";
			this->button_registrieren->UseVisualStyleBackColor = true;
			this->button_registrieren->Click += gcnew System::EventHandler(this, &Anmeldung::button_registrieren_Click);
			// 
			// button_anmelden
			// 
			this->button_anmelden->Location = System::Drawing::Point(39, 204);
			this->button_anmelden->Name = L"button_anmelden";
			this->button_anmelden->Size = System::Drawing::Size(100, 23);
			this->button_anmelden->TabIndex = 6;
			this->button_anmelden->Text = L"Anmelden";
			this->button_anmelden->UseVisualStyleBackColor = true;
			this->button_anmelden->Click += gcnew System::EventHandler(this, &Anmeldung::button_anmelden_Click);
			// 
			// Anmeldung
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button_anmelden);
			this->Controls->Add(this->button_registrieren);
			this->Controls->Add(this->txt_passwort);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->label_passwort);
			this->Controls->Add(this->label_benutzer);
			this->Controls->Add(this->label_header);
			this->Name = L"Anmeldung";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

 

#pragma endregion


	private: 
			
			System::Void button_anmelden_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //Der Benutzername und das Passwort werden aus den Textboxen ausgelesen und mit der Datenbank abgeglichen 

				 String ^name = txt_name->Text; 
				 String ^passwort = txt_passwort->Text; 

				

				 //Die Funktion check() liefert true zurück wenn der Benutzer existiert und das Passwort richtig ist.
				 

				 if(check(name,passwort) == true )
				 {
					 Dashboard ^dash = gcnew Dashboard(name);					 
					 dash->Show(); 
					 
				 }

				 
			
			 }//end button_anmelden click





			 System::Void button_registrieren_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				 Registrierung ^reg = gcnew Registrierung(verbindung); 
				 reg->Show(); 

			}




			bool check(String ^name, String ^passwort)
			{	

				oeffneDatenbank(); 
				leseDatenbank(); 

				String ^hashVal = passwort->GetHashCode().ToString(); 

				String ^user; 
				String ^pwd; 

				

				for(int i=0; i<userTab->Rows->Count;i++)
				 {

					 user = (String^)(userTab->Rows[i]->ItemArray[1]); 

					 if(user==name)
					 {
						pwd= Convert::ToString(userTab->Rows[i]->ItemArray[2]);

						if(pwd==hashVal)
						{
							MessageBox::Show("Anmeldung erfolgreich! "); 
							verbindung->Close(); 
							return true; 
						}

						else
						{
							MessageBox::Show("Anmeldung fehlgeschlagen: \nFalsches Passwort");
							verbindung->Close();
							return false; 
						}

					 }

				 }

				
				MessageBox::Show("Anmeldung fehlgeschlagen: \nUsername existiert nicht ");
				verbindung->Close();
				return false; 
			}//end check 





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



}; //end Class

			
}//end Namespace

