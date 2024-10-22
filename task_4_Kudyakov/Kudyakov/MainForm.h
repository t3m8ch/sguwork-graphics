#pragma once
#include <vector>
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include "Clip.h"
#include <fstream>
#include <sstream>

namespace Kudyakov {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::vector<Model> models;

	float Vx = 1;
	float Vy = 1;
	float aspectRect = Vx / Vy;

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
	private: 
		float left = 30, right = 100, top = 20, bottom = 50;
		float minX = left, maxX;
		float minY = top, maxY;
		float Wcx = left, Wcy;
		float Wx, Wy;

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right;
		maxY = ClientRectangle.Height - bottom;
		Wcy = maxY;
		Wx = maxX - left;
		Wy = maxY - top;
	}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {		
		rectCalc();
	}

	private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		for (int k = 0; k < models.size(); k++) {
			auto figure = models[k].figure;
			Mat3 TM = T * models[k].modelM;

			for (int i = 0; i < figure.size(); i++) {
				Path lines = figure[i];
				Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
				pen->Width = lines.thickness;

				Vec2 start = normalize(TM * Vec3(lines.vertices[0], 1.0));
				for (int j = 1; j < lines.vertices.size(); j++) {
					Vec2 end = normalize(TM * Vec3(lines.vertices[j], 1.0));
					Vec2 tmpEnd = end;
					if (clip(start, end, minX, maxX, minY, maxY)) {
						g->DrawLine(pen, start.x, start.y, end.x, end.y);
					}
					start = tmpEnd;
				}
			}
		}
	}

	private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f;
		float Wcy = ClientRectangle.Height / 2.f;

		switch (e->KeyCode) {
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
			T = initT;
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

			std::ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				models.clear();

				Mat3 M = Mat3(1.f);
				Mat3 initM;
				std::vector<Mat3> transforms;
				std::vector<Path> figure;

				float thickness = 2;
				float r, g, b;
				r = g = b = 0;

				std::string str;
				getline(in, str);

				while (in) {
					if ((str.find_first_not_of(" \t\r\n") != std::string::npos) && (str[0] != '#')) {
						std::stringstream s(str);
						std::string cmd;
						s >> cmd;

						if (cmd == "frame") {
							s >> Vx >> Vy;

							aspectRect = Wx / Wy;
							float aspectFig = Vx / Vy;

							Mat3 T1 = translate(-Vx / 2, -Vy / 2);
							float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;
							Mat3 S1 = scale(S, -S);

							Mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							initT = T2 * (S1 * T1);
							T = initT;
						}
						else if (cmd == "color") {
							s >> r >> g >> b;
						}
						else if (cmd == "thickness") {
							s >> thickness;
						}
						else if (cmd == "path") {
							std::vector<Vec2> vertices;
							int N;
							s >> N;

							std::string str1;
							while (N > 0) {
								getline(in, str1);

								if ((str1.find_first_not_of(" \t\r\n") != std::string::npos) && (str1[0] != '#')) {
									float x, y;
									std::stringstream s1(str1);
									s1 >> x >> y;
									vertices.push_back(Vec2(x, y));
									N--;
								}
							}

							figure.push_back(Path(vertices, Vec3(r, g, b), thickness));
						}
						else if (cmd == "model") {
							float mVcx, mVcy, mVx, mVy;
							s >> mVcx >> mVcy >> mVx >> mVy;
							float S = mVx / mVy < 1 ? 2.f : 2.f / mVx;
							initM = scale(S) * translate(-mVcx, -mVcy);
							figure.clear();
						}
						else if (cmd == "figure") {
							models.push_back(Model(figure, M * initM));
						}
						else if (cmd == "translate") {
							float Tx, Ty;
							s >> Tx >> Ty;
							M = translate(Tx, Ty) * M;
						}
						else if (cmd == "scale") {
							float S;
							s >> S;
							M = scale(S) * M;
						}
						else if (cmd == "rotate") {
							float theta;
							s >> theta;
							M = rotate(-theta / 180.0f * Math::PI) * M;
						}
						else if (cmd == "pushTransform") {
							transforms.push_back(M);
						}
						else if (cmd == "popTransform") {
							M = transforms.back();
							transforms.pop_back();
						}
					}

					getline(in, str);
				}
			}
			Refresh();
		}
	}
};
}
