#pragma once

namespace VorlageWindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(String ^user)
		{
			//Konstruktor

			InitializeComponent();
			txt_user->Text="Hallo "+user+"!"; 
		}

	protected:
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
			System::Windows::Forms::Button^  button1;
			System::Windows::Forms::TextBox^  txt_user;
			System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txt_user = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(289, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Knopf";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// txt_user
			// 
			this->txt_user->Location = System::Drawing::Point(289, 171);
			this->txt_user->Name = L"txt_user";
			this->txt_user->Size = System::Drawing::Size(100, 20);
			this->txt_user->TabIndex = 1;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 762);
			this->Controls->Add(this->txt_user);
			this->Controls->Add(this->button1);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
