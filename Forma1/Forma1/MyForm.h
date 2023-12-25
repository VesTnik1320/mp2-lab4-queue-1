#pragma once
#include "../../Queue/Queue.h"

namespace Forma1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		int MaxSize, Size;
		double P, Q;
		int PushCount, PopCount;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;
	private: System::Windows::Forms::TextBox^ textBox_maxsize;
	private: System::Windows::Forms::Label^ label_maxsize;

	private: System::Windows::Forms::Button^ button_close;

	private: System::Windows::Forms::Label^ label_size;
	private: System::Windows::Forms::TextBox^ textBox_size;

	private: System::Windows::Forms::Label^ label_p;
	private: System::Windows::Forms::TextBox^ textBox_p;

	private: System::Windows::Forms::Label^ label_q;
	private: System::Windows::Forms::TextBox^ textBox_q;

	private: System::Windows::Forms::Button^ button_stop;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label_PopCount;


	private: System::Windows::Forms::Label^ label_PushCount;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_pushedres;
	private: System::Windows::Forms::Label^ label_poppedres;
	private: System::Windows::Forms::Label^ label_cursizeres;
	private: System::Windows::Forms::Label^ label_err;



	private: System::Windows::Forms::Button^ button_go;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gr = CreateGraphics();
			rnd1 = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			CenterX = 400;
			CenterY = 350;
			Width = Height = 200;

			PopCount = PushCount = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_go = (gcnew System::Windows::Forms::Button());
			this->textBox_maxsize = (gcnew System::Windows::Forms::TextBox());
			this->label_maxsize = (gcnew System::Windows::Forms::Label());
			this->button_close = (gcnew System::Windows::Forms::Button());
			this->label_size = (gcnew System::Windows::Forms::Label());
			this->textBox_size = (gcnew System::Windows::Forms::TextBox());
			this->label_p = (gcnew System::Windows::Forms::Label());
			this->textBox_p = (gcnew System::Windows::Forms::TextBox());
			this->label_q = (gcnew System::Windows::Forms::Label());
			this->textBox_q = (gcnew System::Windows::Forms::TextBox());
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_PopCount = (gcnew System::Windows::Forms::Label());
			this->label_PushCount = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_pushedres = (gcnew System::Windows::Forms::Label());
			this->label_poppedres = (gcnew System::Windows::Forms::Label());
			this->label_cursizeres = (gcnew System::Windows::Forms::Label());
			this->label_err = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_go
			// 
			this->button_go->Location = System::Drawing::Point(591, 68);
			this->button_go->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_go->Name = L"button_go";
			this->button_go->Size = System::Drawing::Size(150, 50);
			this->button_go->TabIndex = 10;
			this->button_go->Text = L"Go";
			this->button_go->UseVisualStyleBackColor = true;
			this->button_go->Click += gcnew System::EventHandler(this, &MyForm::button_go_Click);
			// 
			// textBox_maxsize
			// 
			this->textBox_maxsize->Location = System::Drawing::Point(346, 32);
			this->textBox_maxsize->Name = L"textBox_maxsize";
			this->textBox_maxsize->Size = System::Drawing::Size(100, 21);
			this->textBox_maxsize->TabIndex = 11;
			this->textBox_maxsize->Text = L"0";
			// 
			// label_maxsize
			// 
			this->label_maxsize->AutoSize = true;
			this->label_maxsize->Location = System::Drawing::Point(154, 32);
			this->label_maxsize->Name = L"label_maxsize";
			this->label_maxsize->Size = System::Drawing::Size(127, 15);
			this->label_maxsize->TabIndex = 13;
			this->label_maxsize->Text = L"Max size of the queue";
			// 
			// button_close
			// 
			this->button_close->Location = System::Drawing::Point(897, 12);
			this->button_close->Name = L"button_close";
			this->button_close->Size = System::Drawing::Size(75, 72);
			this->button_close->TabIndex = 15;
			this->button_close->Text = L"Close";
			this->button_close->UseVisualStyleBackColor = true;
			this->button_close->Click += gcnew System::EventHandler(this, &MyForm::button_close_Click);
			// 
			// label_size
			// 
			this->label_size->AutoSize = true;
			this->label_size->Location = System::Drawing::Point(154, 59);
			this->label_size->Name = L"label_size";
			this->label_size->Size = System::Drawing::Size(128, 15);
			this->label_size->TabIndex = 17;
			this->label_size->Text = L"Start size of the queue";
			// 
			// textBox_size
			// 
			this->textBox_size->Location = System::Drawing::Point(346, 59);
			this->textBox_size->Name = L"textBox_size";
			this->textBox_size->Size = System::Drawing::Size(100, 21);
			this->textBox_size->TabIndex = 16;
			this->textBox_size->Text = L"0";
			// 
			// label_p
			// 
			this->label_p->AutoSize = true;
			this->label_p->Location = System::Drawing::Point(154, 86);
			this->label_p->Name = L"label_p";
			this->label_p->Size = System::Drawing::Size(115, 15);
			this->label_p->TabIndex = 19;
			this->label_p->Text = L"Probabilty of push P";
			// 
			// textBox_p
			// 
			this->textBox_p->Location = System::Drawing::Point(346, 86);
			this->textBox_p->Name = L"textBox_p";
			this->textBox_p->Size = System::Drawing::Size(100, 21);
			this->textBox_p->TabIndex = 18;
			this->textBox_p->Text = L"0";
			// 
			// label_q
			// 
			this->label_q->AutoSize = true;
			this->label_q->Location = System::Drawing::Point(154, 113);
			this->label_q->Name = L"label_q";
			this->label_q->Size = System::Drawing::Size(110, 15);
			this->label_q->TabIndex = 21;
			this->label_q->Text = L"Probabilty of pop Q";
			// 
			// textBox_q
			// 
			this->textBox_q->Location = System::Drawing::Point(346, 113);
			this->textBox_q->Name = L"textBox_q";
			this->textBox_q->Size = System::Drawing::Size(100, 21);
			this->textBox_q->TabIndex = 20;
			this->textBox_q->Text = L"0";
			// 
			// button_stop
			// 
			this->button_stop->Location = System::Drawing::Point(591, 127);
			this->button_stop->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(150, 50);
			this->button_stop->TabIndex = 22;
			this->button_stop->Text = L"Stop";
			this->button_stop->UseVisualStyleBackColor = true;
			this->button_stop->Click += gcnew System::EventHandler(this, &MyForm::button_stop_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label_PopCount
			// 
			this->label_PopCount->AutoSize = true;
			this->label_PopCount->Location = System::Drawing::Point(154, 167);
			this->label_PopCount->Name = L"label_PopCount";
			this->label_PopCount->Size = System::Drawing::Size(50, 15);
			this->label_PopCount->TabIndex = 26;
			this->label_PopCount->Text = L"Popped";
			// 
			// label_PushCount
			// 
			this->label_PushCount->AutoSize = true;
			this->label_PushCount->Location = System::Drawing::Point(154, 140);
			this->label_PushCount->Name = L"label_PushCount";
			this->label_PushCount->Size = System::Drawing::Size(49, 15);
			this->label_PushCount->TabIndex = 24;
			this->label_PushCount->Text = L"Pushed";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 194);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 15);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Current size of the queue";
			// 
			// label_pushedres
			// 
			this->label_pushedres->AutoSize = true;
			this->label_pushedres->Location = System::Drawing::Point(368, 140);
			this->label_pushedres->Name = L"label_pushedres";
			this->label_pushedres->Size = System::Drawing::Size(0, 15);
			this->label_pushedres->TabIndex = 29;
			// 
			// label_poppedres
			// 
			this->label_poppedres->AutoSize = true;
			this->label_poppedres->Location = System::Drawing::Point(368, 167);
			this->label_poppedres->Name = L"label_poppedres";
			this->label_poppedres->Size = System::Drawing::Size(0, 15);
			this->label_poppedres->TabIndex = 30;
			// 
			// label_cursizeres
			// 
			this->label_cursizeres->AutoSize = true;
			this->label_cursizeres->Location = System::Drawing::Point(368, 194);
			this->label_cursizeres->Name = L"label_cursizeres";
			this->label_cursizeres->Size = System::Drawing::Size(0, 15);
			this->label_cursizeres->TabIndex = 31;
			// 
			// label_err
			// 
			this->label_err->AutoSize = true;
			this->label_err->Location = System::Drawing::Point(422, 327);
			this->label_err->Name = L"label_err";
			this->label_err->Size = System::Drawing::Size(0, 15);
			this->label_err->TabIndex = 32;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->label_err);
			this->Controls->Add(this->label_cursizeres);
			this->Controls->Add(this->label_poppedres);
			this->Controls->Add(this->label_pushedres);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_PopCount);
			this->Controls->Add(this->label_PushCount);
			this->Controls->Add(this->button_stop);
			this->Controls->Add(this->label_q);
			this->Controls->Add(this->textBox_q);
			this->Controls->Add(this->label_p);
			this->Controls->Add(this->textBox_p);
			this->Controls->Add(this->label_size);
			this->Controls->Add(this->textBox_size);
			this->Controls->Add(this->button_close);
			this->Controls->Add(this->label_maxsize);
			this->Controls->Add(this->textBox_maxsize);
			this->Controls->Add(this->button_go);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Queue Circle Buffer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void Clean() {
			//Вычисляем стартовый угол
			int start = 360 * pQueue->getHead() / pQueue->getMaxSize();
			int finish = 360 * pQueue->getSize() / pQueue->getMaxSize();
			gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
			//gr->FillEllipse(Brushes::White, CenterX, CenterY, Width, Height);
		}

		private: System::Void timer1_Click() {
			//Стереть очередь
			Clean();
			//Обновить состояние очереди
			if (rnd1->NextDouble() < P) {
				if (!pQueue->full()) {
					pQueue->push(1);
					PushCount++;
				}
			}
			if (rnd1->NextDouble() < Q) {
				if (!pQueue->empty()) {
					pQueue->pop();
					PopCount++;
				}
			}
			//Нарисовать очередь
			DrawQueue();
			/*textBox_PushCount->Text = Convert::ToString(PushCount);
			textBox_PopCount->Text = Convert::ToString(PopCount);*/
		}

		private: System::Void button_stop_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
		}

		private: System::Void button_go_Click(System::Object^ sender, System::EventArgs^ e) { // MOVE
			//Чтение параметров с формы
			MaxSize = Convert::ToInt32(textBox_maxsize->Text);
			Size = Convert::ToInt32(textBox_size->Text);
			P = Convert::ToDouble(textBox_p->Text);
			Q = Convert::ToDouble(textBox_q->Text);
			//Создание и заполнение очереди
			pQueue = new TQueue<int>(MaxSize);
			for (int i = 0; i < Size; i++) {
				pQueue->push(1);
			}
			DrawQueue();
			timer1->Enabled = true;
		}
		void DrawQueue() {
			label_err->Text = "";
			//Вычисляем стартовый угол
			int start = 360 * pQueue->getHead() / pQueue->getMaxSize();
			int finish = 360 * pQueue->getSize() / pQueue->getMaxSize();
			//Нарисовать дугу от Tail до Head
			gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		}
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			try
			{
				if (!pQueue->empty()) Clean();
				if (rnd1->NextDouble() < P) {
					pQueue->push(1);
					PushCount++;
				}
				if (rnd1->NextDouble() < Q) {
					pQueue->pop();
					PopCount++;
				}
				DrawQueue();
				label_pushedres->Text = Convert::ToString(PushCount);
				label_poppedres->Text = Convert::ToString(PopCount);
				label_cursizeres->Text = Convert::ToString(pQueue->getSize());

			}
			catch (const char* ex)
			{
				label_err->Text = "Queue is full or empty";
				timer1->Enabled = false;
				Clean();
				delete pQueue;
				PushCount = 0;
				PopCount = 0;
				label_pushedres->Text = Convert::ToString(0);
				label_poppedres->Text = Convert::ToString(0);
				label_cursizeres->Text = Convert::ToString(0);

			}
		}
		private: System::Void button_close_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}