#pragma once
#include <vector>
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include "Drawing.h"
#include "Files.h"
#include <fstream>
#include <sstream>

namespace Kudyakov {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::vector<Path> figure;

	float Vx = 8.5;
	float Vy = 8.5;
	float aspectFig = Vx / Vy;

	Mat3 T = Mat3(1.0f);
	Mat3 initT;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:
	private: System::Windows::Forms::Button^ btnOpen;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L" (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->Location = System::Drawing::Point(546, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MainForm::btnOpen_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 743);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true;
		
		float thickness;
		Vec3 color;
		std::vector<Vec2> vertices;
		// голова
		thickness = 2; // толщиналинии 2
		color = Vec3(255, 0, 0); // цвет красный
		// точки
		vertices.push_back(Vec2(0.5f, 3.f));
		vertices.push_back(Vec2(1.f, 4.5f));
		vertices.push_back(Vec2(0.5f, 6.f));
		vertices.push_back(Vec2(0.5f, 7.5f));
		vertices.push_back(Vec2(1.f, 8.f));
		vertices.push_back(Vec2(1.5f, 8.f));
		vertices.push_back(Vec2(2.f, 7.5f));
		vertices.push_back(Vec2(1.5f, 6.f));
		vertices.push_back(Vec2(1.5f, 4.5f));
		vertices.push_back(Vec2(3.f, 4.5f));
		vertices.push_back(Vec2(3.f, 6.f));
		vertices.push_back(Vec2(2.5f, 7.5f));
		vertices.push_back(Vec2(3.f, 8.f));
		vertices.push_back(Vec2(3.5f, 8.f));
		vertices.push_back(Vec2(4.f, 7.5f));
		vertices.push_back(Vec2(4.f, 6.f));
		vertices.push_back(Vec2(3.5f, 4.5f));
		vertices.push_back(Vec2(4.f, 3.f));
		vertices.push_back(Vec2(3.5f, 1.5f));
		vertices.push_back(Vec2(2.5f, 1.f));
		vertices.push_back(Vec2(2.f, 1.f));
		vertices.push_back(Vec2(1.f, 1.5f));
		vertices.push_back(Vec2(0.5f, 3.f));
		figure.push_back(Path(vertices, color, thickness));
		// левый глаз
		thickness = 4; // толщиналинии 4
		color = Vec3(0, 255, 0); // цвет зеленый
		// точки
		vertices.clear();
		vertices.push_back(Vec2(1.5f, 3.5f));
		vertices.push_back(Vec2(1.5f, 3.f));
		vertices.push_back(Vec2(2.f, 3.f));
		vertices.push_back(Vec2(2.f, 3.5f));
		vertices.push_back(Vec2(1.5f, 3.5f));
		figure.push_back(Path(vertices, color, thickness));
		// правый глаз
		// цвет итолщина те же
		vertices.clear();
		vertices.push_back(Vec2(2.5f, 3.5f));
		vertices.push_back(Vec2(2.5f, 3.f));
		vertices.push_back(Vec2(3.f, 3.f));
		vertices.push_back(Vec2(3.f, 3.5f));
		vertices.push_back(Vec2(2.5f, 3.5f));
		figure.push_back(Path(vertices, color, thickness));
	}

	private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width;
		float Wy = ClientRectangle.Height;

		drawPic(g, blackPen, figure, T, initT, Vx, Vy, Wx, Wy, keepAspectRatio);
	}

	private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f;
		float Wcy = ClientRectangle.Height / 2.f;

		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T;
			T = rotate(0.01f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::E:
			T = translate(-Wcx, -Wcy) * T;
			T = rotate(-0.01f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::R:
			T = translate(-Wcx, -Wcy) * T;
			T = rotate(-0.05f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::Y:
			T = translate(-Wcx, -Wcy) * T;
			T = rotate(0.05f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::Z:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(1.1f, 1.1f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::X:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(0.9f, 0.9f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::U:
			T = translate(-Wcx, -Wcy) * T;
			T = mirrorX() * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::J:
			T = translate(-Wcx, -Wcy) * T;
			T = mirrorY() * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::I:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(1.1f, 1.0f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::K:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(0.9f, 1.0f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::O:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(1.0f, 1.1f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::L:
			T = translate(-Wcx, -Wcy) * T;
			T = scale(1.0f, 0.9f) * T;
			T = translate(Wcx, Wcy) * T;
			break;
		case Keys::W:
			T = translate(0.f, -1.f) * T;
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T;
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T;
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T;
			break;
		case Keys::T:
			T = translate(0.f, -10.f) * T;
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T;
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T;
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T;
			break;
		case Keys::Escape:
			T = Mat3(1.f);
			break;
		default:
			break;
		}
		Refresh();
	}
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			wchar_t fileName[1024];
			for (int i = 0; i < openFileDialog->FileName->Length; i++) {
				fileName[i] = openFileDialog->FileName[i];
			}
			fileName[openFileDialog->FileName->Length] = '\0';

			loadFigureFromFile(fileName, figure, Vx, Vy, aspectFig);
			Refresh();
		}
	}
};
}
