#pragma once
#include "Figure.h"

namespace Forma1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Figure** arr;
		Graphics^ gr;
		int size;
		int dx, dy;
	private: System::Windows::Forms::Button^ button_hide;
		   // HIDE
	private: System::Windows::Forms::TextBox^ textBox_dx;
	private: System::Windows::Forms::TextBox^ textBox_dy;
	private: System::Windows::Forms::Label^ label_dx;
	private: System::Windows::Forms::Label^ label_dy;
	private: System::Windows::Forms::Button^ button_close;
	private: System::Windows::Forms::Button^ button_move;

 // MOVE
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			size = 14;
			arr = new Figure * [size];
			arr[0] = new Line(300, 300, 300, 350); // голова
			arr[1] = new Line(300, 300, 310, 310);
			arr[2] = new Line(310, 310, 350, 310);
			arr[3] = new Line(350, 310, 360, 300);
			arr[4] = new Line(360, 300, 360, 350); // голова
			arr[5] = new Rect(90, 35, 360, 315); // тело
			arr[6] = new Rect(60, 10, 450, 340); // хвост
			arr[7] = new Rect(15, 10, 285, 340); // лапа
			arr[8] = new Rect(15, 10, 360, 340); // лапа
			arr[9] = new Rect(15, 10, 410, 340); // лапа справа
			arr[10] = new Rect(25, 30, 425, 320); // лапа справа больша€ часть
			arr[11] = new Line(310, 330, 315, 330); // глаз
			arr[12] = new Line(345, 330, 350, 330); // глаз
			arr[13] = new Line(300, 350, 360, 350);

			gr = CreateGraphics();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_show;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_show = (gcnew System::Windows::Forms::Button());
			this->button_hide = (gcnew System::Windows::Forms::Button());
			this->button_move = (gcnew System::Windows::Forms::Button());
			this->textBox_dx = (gcnew System::Windows::Forms::TextBox());
			this->textBox_dy = (gcnew System::Windows::Forms::TextBox());
			this->label_dx = (gcnew System::Windows::Forms::Label());
			this->label_dy = (gcnew System::Windows::Forms::Label());
			this->button_close = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_show
			// 
			this->button_show->Location = System::Drawing::Point(39, 513);
			this->button_show->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_show->Name = L"button_show";
			this->button_show->Size = System::Drawing::Size(168, 53);
			this->button_show->TabIndex = 8;
			this->button_show->Text = L"Show";
			this->button_show->UseVisualStyleBackColor = true;
			this->button_show->Click += gcnew System::EventHandler(this, &MyForm::button_show_Click);
			// 
			// button_hide
			// 
			this->button_hide->Location = System::Drawing::Point(39, 573);
			this->button_hide->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_hide->Name = L"button_hide";
			this->button_hide->Size = System::Drawing::Size(168, 53);
			this->button_hide->TabIndex = 9;
			this->button_hide->Text = L"Hide";
			this->button_hide->UseVisualStyleBackColor = true;
			this->button_hide->Click += gcnew System::EventHandler(this, &MyForm::button_hide_Click);
			// 
			// button_move
			// 
			this->button_move->Location = System::Drawing::Point(782, 573);
			this->button_move->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_move->Name = L"button_move";
			this->button_move->Size = System::Drawing::Size(168, 53);
			this->button_move->TabIndex = 10;
			this->button_move->Text = L"Move";
			this->button_move->UseVisualStyleBackColor = true;
			this->button_move->Click += gcnew System::EventHandler(this, &MyForm::button_move_Click);
			// 
			// textBox_dx
			// 
			this->textBox_dx->Location = System::Drawing::Point(850, 513);
			this->textBox_dx->Name = L"textBox_dx";
			this->textBox_dx->Size = System::Drawing::Size(100, 21);
			this->textBox_dx->TabIndex = 11;
			this->textBox_dx->Text = L"0";
			// 
			// textBox_dy
			// 
			this->textBox_dy->Location = System::Drawing::Point(850, 540);
			this->textBox_dy->Name = L"textBox_dy";
			this->textBox_dy->Size = System::Drawing::Size(100, 21);
			this->textBox_dy->TabIndex = 12;
			this->textBox_dy->Text = L"0";
			// 
			// label_dx
			// 
			this->label_dx->AutoSize = true;
			this->label_dx->Location = System::Drawing::Point(771, 516);
			this->label_dx->Name = L"label_dx";
			this->label_dx->Size = System::Drawing::Size(73, 15);
			this->label_dx->TabIndex = 13;
			this->label_dx->Text = L"¬ведите dx";
			// 
			// label_dy
			// 
			this->label_dy->AutoSize = true;
			this->label_dy->Location = System::Drawing::Point(771, 543);
			this->label_dy->Name = L"label_dy";
			this->label_dy->Size = System::Drawing::Size(72, 15);
			this->label_dy->TabIndex = 14;
			this->label_dy->Text = L"¬ведите dy";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->button_close);
			this->Controls->Add(this->label_dy);
			this->Controls->Add(this->label_dx);
			this->Controls->Add(this->textBox_dy);
			this->Controls->Add(this->textBox_dx);
			this->Controls->Add(this->button_move);
			this->Controls->Add(this->button_hide);
			this->Controls->Add(this->button_show);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_show_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++)
		{
			arr[i]->Show(gr);
		}
	}
	private: System::Void button_hide_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++)
		{
			arr[i]->Hide(gr);
		}
	}
	private: System::Void button_move_Click(System::Object^ sender, System::EventArgs^ e) { // MOVE
		int coordx = arr[6]->get_x() + 60;
		int coordy = arr[7]->get_y() + 10;
		int dx, dy;
		dx = Convert::ToInt32(textBox_dx->Text);
		dy = Convert::ToInt32(textBox_dy->Text);

		if (dx >= 0 && dy >= 0)
		{
			coordx = arr[6]->get_x() + 60;
			coordy = arr[7]->get_y() + 10;
			while (coordx < 1000 && coordy < 700)
			{
				for (int i = 0; i < size; i++) {
					arr[i]->Move(gr, dx, dy);
				}
				coordx = arr[6]->get_x() + 60;
				coordy = arr[0]->get_y() + 90;
			}
		}

		if (dx >= 0 && dy <= 0)
		{
			coordx = arr[6]->get_x() + 60;
			coordy = arr[0]->get_y();
			while (coordx < 1000 && coordy > 0)
			{
				for (int i = 0; i < size; i++) {
					arr[i]->Move(gr, dx, dy);
				}
				coordx = arr[6]->get_x() + 60;
				coordy = arr[0]->get_y();
			}
		}

		if (dx <= 0 && dy >= 0)
		{
			coordx = arr[7]->get_x();
			coordy = arr[7]->get_y() + 10;
			while (coordx > 0 && coordy < 700)
			{
				for (int i = 0; i < size; i++) {
					arr[i]->Move(gr, dx, dy);
				}
				coordx = arr[7]->get_x();
				coordy = arr[0]->get_y() + 90;
			}
		}

		if (dx <= 0 && dy <= 0)
		{
			coordx = arr[7]->get_x();
			coordy = arr[0]->get_y();
			while (coordx > 0 && coordy > 0)
			{
				for (int i = 0; i < size; i++) {
					arr[i]->Move(gr, dx, dy);
				}
				coordx = arr[7]->get_x();
				coordy = arr[0]->get_y();
			}
		}
	}
private: System::Void button_close_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
