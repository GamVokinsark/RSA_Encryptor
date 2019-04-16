// Form1.h: файл формы окна.
#pragma once

char *convert(System::String^ string) 
{
	return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string);
}

namespace RSA2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  TxtP;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  TxtQ;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  TxtN;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  TxtKa;
	private: System::Windows::Forms::TextBox^  TxtKb;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  TxtNums;
	private: System::Windows::Forms::TextBox^  TxtText;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ChiphNums;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  DecodNums;
	private: System::Windows::Forms::TextBox^  DecodText;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TxtP = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TxtQ = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TxtN = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TxtKa = (gcnew System::Windows::Forms::TextBox());
			this->TxtKb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TxtNums = (gcnew System::Windows::Forms::TextBox());
			this->TxtText = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ChiphNums = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->DecodNums = (gcnew System::Windows::Forms::TextBox());
			this->DecodText = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(256, 223);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Зашифровать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// TxtP
			// 
			this->TxtP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtP->Location = System::Drawing::Point(37, 6);
			this->TxtP->Name = L"TxtP";
			this->TxtP->ReadOnly = true;
			this->TxtP->Size = System::Drawing::Size(429, 24);
			this->TxtP->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"P";
			// 
			// TxtQ
			// 
			this->TxtQ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtQ->Location = System::Drawing::Point(37, 36);
			this->TxtQ->Name = L"TxtQ";
			this->TxtQ->ReadOnly = true;
			this->TxtQ->Size = System::Drawing::Size(429, 24);
			this->TxtQ->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label2->Location = System::Drawing::Point(12, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Q";
			// 
			// TxtN
			// 
			this->TxtN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtN->Location = System::Drawing::Point(37, 64);
			this->TxtN->Name = L"TxtN";
			this->TxtN->ReadOnly = true;
			this->TxtN->Size = System::Drawing::Size(429, 24);
			this->TxtN->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->Location = System::Drawing::Point(12, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"N";
			// 
			// TxtKa
			// 
			this->TxtKa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtKa->Location = System::Drawing::Point(37, 90);
			this->TxtKa->Name = L"TxtKa";
			this->TxtKa->ReadOnly = true;
			this->TxtKa->Size = System::Drawing::Size(429, 24);
			this->TxtKa->TabIndex = 1;
			// 
			// TxtKb
			// 
			this->TxtKb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtKb->Location = System::Drawing::Point(37, 118);
			this->TxtKb->Name = L"TxtKb";
			this->TxtKb->ReadOnly = true;
			this->TxtKb->Size = System::Drawing::Size(429, 24);
			this->TxtKb->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label4->Location = System::Drawing::Point(12, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 18);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Ka";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label5->Location = System::Drawing::Point(243, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(114, 18);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Текст в блоках";
			// 
			// TxtNums
			// 
			this->TxtNums->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtNums->Location = System::Drawing::Point(246, 169);
			this->TxtNums->Multiline = true;
			this->TxtNums->Name = L"TxtNums";
			this->TxtNums->ReadOnly = true;
			this->TxtNums->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TxtNums->Size = System::Drawing::Size(229, 48);
			this->TxtNums->TabIndex = 1;
			// 
			// TxtText
			// 
			this->TxtText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->TxtText->Location = System::Drawing::Point(11, 169);
			this->TxtText->Multiline = true;
			this->TxtText->Name = L"TxtText";
			this->TxtText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TxtText->Size = System::Drawing::Size(229, 48);
			this->TxtText->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label6->Location = System::Drawing::Point(8, 148);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(108, 18);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Введите текст";
			// 
			// ChiphNums
			// 
			this->ChiphNums->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->ChiphNums->Location = System::Drawing::Point(11, 244);
			this->ChiphNums->Multiline = true;
			this->ChiphNums->Name = L"ChiphNums";
			this->ChiphNums->ReadOnly = true;
			this->ChiphNums->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ChiphNums->Size = System::Drawing::Size(229, 48);
			this->ChiphNums->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label7->Location = System::Drawing::Point(8, 223);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 18);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Блоки шифра";
			// 
			// DecodNums
			// 
			this->DecodNums->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->DecodNums->Location = System::Drawing::Point(246, 319);
			this->DecodNums->Multiline = true;
			this->DecodNums->Name = L"DecodNums";
			this->DecodNums->ReadOnly = true;
			this->DecodNums->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DecodNums->Size = System::Drawing::Size(229, 48);
			this->DecodNums->TabIndex = 1;
			// 
			// DecodText
			// 
			this->DecodText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->DecodText->Location = System::Drawing::Point(11, 319);
			this->DecodText->Multiline = true;
			this->DecodText->Name = L"DecodText";
			this->DecodText->ReadOnly = true;
			this->DecodText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DecodText->Size = System::Drawing::Size(229, 48);
			this->DecodText->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label8->Location = System::Drawing::Point(243, 298);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(114, 18);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Текст в блоках";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label9->Location = System::Drawing::Point(8, 298);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(168, 18);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Расшифрованый текст";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label10->Location = System::Drawing::Point(12, 121);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(26, 18);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Kb";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button2->Location = System::Drawing::Point(256, 256);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Расшифровать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 391);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ChiphNums);
			this->Controls->Add(this->DecodText);
			this->Controls->Add(this->TxtText);
			this->Controls->Add(this->DecodNums);
			this->Controls->Add(this->TxtNums);
			this->Controls->Add(this->TxtKb);
			this->Controls->Add(this->TxtKa);
			this->Controls->Add(this->TxtN);
			this->Controls->Add(this->TxtQ);
			this->Controls->Add(this->TxtP);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"RSA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 input=convert(this->TxtText->Text); // Считывание текста
				 rsaEncrypt(); // Шифрование
				 String^ str1 = gcnew String(bigUnsignedToString(P).c_str());
				 TxtP->Text=str1; // Тут и ниже вывод информации
				 String^ str2 = gcnew String(bigUnsignedToString(Q).c_str());
				 TxtQ->Text=str2;
				 String^ str3 = gcnew String(bigUnsignedToString(Nr).c_str());
				 TxtN->Text=str3;
				 String^ str4 = gcnew String(bigUnsignedToString(Ka).c_str());
				 TxtKa->Text=str4;
				 String^ str5 = gcnew String(bigUnsignedToString(Kb).c_str());
				 TxtKb->Text=str5;
				 string temp;
				 for(int i=0; i<nBlocks; i++)
				 {
					 temp+=bigUnsignedToString(blockNums[i]);
					 temp+=' ';
				 }
				 String^ str6 = gcnew String(temp.c_str());
				 TxtNums->Text=str6;
				 temp;
				 for(int i=0; i<nBlocks; i++)
				 {
					 temp+=bigUnsignedToString(blockChif[i]);
					 temp+=' ';
				 }
				 String^ str7 = gcnew String(temp.c_str());
				 ChiphNums->Text=str7;
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 rsaDecrypt(); //Расшифрование
			 string temp;
			 for(int i=0; i<nBlocks; i++)
			 {
				 temp+=bigUnsignedToString(blockNums[i]);
				 temp+=' ';
			 }
			 String^ str1 = gcnew String(output.c_str());
			 DecodText->Text=str1; // Тут и ниже вывод информации
			 String^ str2 = gcnew String(temp.c_str());
			 DecodNums->Text=str2;

		 }
};
}

