#pragma once
#include "expression_calculator.h"
#include "queue.h"

namespace graphPlot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		Bitmap^ DrawArea;
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(754, 462);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(786, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(247, 152);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(160, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Построить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Шаг:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(75, 84);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(56, 20);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"0,1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(137, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Xmax";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(178, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(57, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"10";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Xmin";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(75, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(56, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"-10";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Функция:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(160, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"2*x";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 488);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"mainForm";
			this->Text = L"Графопостроитель";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::mainForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainForm_Load(System::Object^  sender, System::EventArgs^  e) {

				
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 double xmin, xmax, step;
			 Double::TryParse(textBox2->Text,xmin);
			 Double::TryParse(textBox3->Text, xmax);
			 Double::TryParse(textBox4->Text, step);

			 char expr[100];
			 String^ data = textBox1->Text;
			 sprintf(expr, "%s", data);

			 QueueChar inq = initQueue<char*>();
			 inq = parseExpression(expr);
			 //QueueChar inp = makeInvPN(inq);

			 QueueVar vars = initQueue<varPair*>();
			 varPair* a = new varPair();
			 a->var = 'x';
			 a->value = 24;
			 push(vars, a);
			 for (double x = xmin; x <= xmax; x += step)
			 {
				 inq = initQueue<char*>();
				 inq = parseExpression(expr);
				 QueueChar inp = makeInvPN(inq);
				 float res = 0;
				 a->value = x;
				 calculate_var(inp, res, vars);
				 Double re = res;
				 MessageBox::Show(re.ToString());
			 }
}
private: System::Void mainForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 DrawArea = gcnew Bitmap(pictureBox1->Size.Width, pictureBox1->Size.Height);
			 pictureBox1->Image = DrawArea;

			 Graphics^ g;
			 g = Graphics::FromImage(DrawArea);

			 SolidBrush^ mybrush = gcnew SolidBrush(Color::White);

			 g->FillRectangle(mybrush, Rectangle(0, 0, pictureBox1->Width, pictureBox1->Height));
			 pictureBox1->Image = DrawArea;
			 delete g;
			// Collections::SortedList
			
}

};
}
