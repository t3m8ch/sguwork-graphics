#pragma once
#include <vector>

namespace Kudyakov {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class Animal { Hare, Lion };

	std::vector<float> hare_lines = {  // ������
		0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���  
		1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
		0.5f,6.f,0.5f, 7.5f, // ����� ��� �����  
		0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
		1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������  
		1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
		2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����  
		1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
		1.5f,4.5f,3.f,4.5f, // �������  
		3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
		3.f,6.f,2.5f,7.5f, // ������ ��� �����  
		2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
		3.f,8.f,3.5f,8.f, // ������ ��� ���� �������� 
		3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
		4.f,7.5f,4.f,6.f, // ������ ��� ������ ����  
		4.f,6.f,3.5f,4.5f, // ������ ��� ������
		3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����  
		4.f,3.f,3.5f,1.5f, // ������ �����
		3.5f,1.5f,2.5f,1.f, // ���������� ������  
		2.5f,1.f,2.f,1.f, // ���������� �����
		2.f,1.f,1.f,1.5f, // ���������� �����  
		1.f,1.5f,0.5f,3.f, // ����� �����
		// ��������  
		4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
		5.5f,3.5f,7.f,3.5f, // ����� ����  
		7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
		7.5f,2.5f,8.f,2.5f, // ����� ������  
		8.f,2.5f,8.f,2.f, // ����� ������
		8.f,2.f,7.5f,2.f, // ����� ��� ������ ������  
		7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
		7.5f,0.5f,6.5f,0.5f, // ������ ���� ���  
		6.5f,0.5f,6.5f,1.f, // ������ ���� �����
		6.5f,1.f,6.f,1.f, // ����� ������ ���  
		6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
		6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���  
		5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
		5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������  
		4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
		4.f,0.5f,3.f,0.5f, // ������ �������� ���� ��� 
		3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
		3.f,1.f,2.5f,1.f, // ����� �������� ���  
		2.5f,1.f,2.5f,0.5f, // �������� ���� ������
		2.5f,0.5f,1.5f,0.5f, // �������� ���� ���  
		1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
		// ����� ����
		1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����  
		1.5f,3.f,2.f,3.f, // ����� ���� ���
		2.f, 3.f,2.f,3.5f, // ����� ���� ������  
		2.f,3.5f,1.5f,3.5f, // ����� ���� ����
		// ������ ����  
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����  
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������  
		// ����� ��������
		1.f,5.5f,1.f,7.f, // ����� ����� ��������  
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
		// ���  
		2.f,2.5f,2.5f,2.5f, // ��� ������
		2.5f,2.5f,2.25f,2.f, // ��� ������  
		2.25f,2.f,2.f,2.5f // ��� �����
	};
	float hare_vx = 8.5f;
	float hare_vy = 8.5f;

	std::vector<float> lion_lines = {  
		// ����� ����
		4.5f, 1.0f, 4.0f, 0.5f,  
		4.0f, 0.5f, 2.0f, 0.5f,
		2.0f, 0.5f, 1.5f, 1.5f,  
		1.5f, 1.5f, 1.5f, 3.5f,
		1.5f, 3.5f, 2.0f, 4.0f,  
		2.0f, 4.0f, 3.5f, 4.0f,
		3.5f, 4.0f, 4.0f, 3.0f,  
		4.0f, 3.0f, 3.5f, 1.0f,

		// �� ����� ���� �� ����� ����
		2.0f, 4.0f, 2.5f, 4.5f,

		// ����� ����� ����
		2.5f, 1.5f, 2.0f, 2.0f,  
		2.0f, 2.0f, 2.0f, 3.0f,
		2.0f, 3.0f, 2.5f, 3.5f,
		2.5f, 3.5f, 3.0f, 3.0f,  
		3.0f, 3.0f, 3.0f, 2.0f,
		3.0f, 2.0f, 2.5f, 1.5f,

		// ������ ����  
		5.5f, 1.0f, 6.0f, 0.5f, 
		6.0f, 0.5f, 8.0f, 0.5f,  
		8.0f, 0.5f, 8.5f, 1.5f,
		8.5f, 1.5f, 8.5f, 3.5f,  
		8.5f, 3.5f, 8.0f, 4.0f,
		8.0f, 4.0f, 6.5f, 4.0f,  
		6.5f, 4.0f, 6.0f, 3.0f,
		6.0f, 3.0f, 6.5f, 1.0f,

		// �� ������ ���� �� ������ ����  
		8.0f, 4.0f, 7.5f, 4.5f,

		// ����� ������ ����
		7.5f, 1.5f, 7.0f, 2.0f,  
		7.0f, 2.0f, 7.0f, 3.0f,
		7.0f, 3.0f, 7.5f, 3.5f,  
		7.5f, 3.5f, 8.0f, 3.0f,
		8.0f, 3.0f, 8.0f, 2.0f,  
		8.0f, 2.0f, 7.5f, 1.5f,

		// ������ �����-�� ���
		4.0f, 1.0f, 6.0f, 1.0f,  
		4.0f, 1.0f, 4.0f - (3.0f / 8.0f), 1.0f + (3.0f / 8.0f),
		6.0f, 1.0f, 6.0f + (3.0f / 8.0f), 1.0f + (3.0f / 8.0f),  
		3.0f, 4.0f, 3.0f, 4.5f,
		7.0f, 4.0f, 7.0f, 4.5f,  
		4.5f, 5.5f, 5.5f, 5.5f,

		// ����� ����
		2.5f, 4.5f, 1.5f, 7.0f,  
		1.5f, 7.0f, 2.5f, 8.0f,
		3.0f, 6.5f, 4.0f, 6.5f,  
		4.0f, 6.5f, 4.5f, 6.0f,
		4.5f, 6.0f, 4.5f, 5.0f,  
		4.5f, 5.0f, 4.0f, 4.5f,
		4.0f, 4.5f, 2.5f, 4.5f,
		3.0f, 6.5f, 2.5f, 5.5f,

		// ������ ����� ����
		4.0f, 5.0f, 4.5f, 5.0f,  
		4.0f, 5.5f, 4.5f, 5.5f,
		4.0f, 6.0f, 4.5f, 6.0f,

		// ������ ����
		5.5f, 5.0f, 6.0f, 4.5f,
		6.0f, 4.5f, 7.5f, 4.5f,
		7.5f, 4.5f, 8.5f, 7.0f,
		8.5f, 7.0f, 7.5f, 8.0f,

		// ������ ������ ����  
		7.5f, 5.5f, 7.0f, 6.5f,
		7.0f, 6.5f, 6.0f, 6.5f,
		6.0f, 6.5f, 5.5f, 6.0f,
		5.5f, 6.0f, 5.5f, 5.0f,
		5.5f, 5.0f, 6.0f, 5.0f,
		5.5f, 5.5f, 6.0f, 5.5f,  
		5.5f, 6.0f, 6.0f, 6.0f,

		// �����-�� ������� �� �����-�� ���
		5.0f, 1.0f, 5.5f, 1.5f,
		5.5f, 1.5f, 5.0f, 2.0f,
		5.0f, 2.0f, 4.5f, 1.5f,
		4.5f, 1.5f, 5.0f, 1.0f,

		4.0f, 2.0f, 4.0f - (3.0f / 16.0f), 2.0f + (3.0f / 16.0f),
		4.0f, 2.0f, 4.5f, 2.5f,
		4.5f, 2.5f, 4.0f, 3.0f,

		6.0f, 3.0f, 5.5f, 3.5f,
		5.5f, 3.5f, 6.0f, 4.0f,
		6.0f, 4.0f, 6.0f + (5.0f / 16.0f), 4.0f - (5.0f / 16.0f),

		4.5f, 3.5f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.5f, 4.5f,
		4.5f, 4.5f, 5.0f, 4.0f,
		5.0f, 4.0f, 4.5f, 3.5f,

		5.5f, 4.5f, 5.0f, 5.0f,
		5.0f, 5.0f, 5.5f, 5.5f,
		5.5f, 4.5f, 5.5f + (4.0f / 16.0f), 4.5f + (4.0f / 16.0f),

		// �����
		1.0f, 7.5f, 1.5, 9.0f,
		1.5f, 9.0f, 0.5f, 9.5f,
		0.5f, 9.5f, 1.5f, 10.5f,
		1.5f, 10.5f, 0.5f, 11.5f,
		0.5f, 11.5f, 2.0f, 12.0f,
		2.0f, 12.0f, 1.5f, 13.5f,
		1.5f, 13.5f, 3.0f, 12.5f,
		3.0f, 12.5f, 3.5f, 13.5f,
		3.5f, 13.5f, 4.5f, 12.5f,
		4.5f, 12.5f, 5.0f, 14.0f,
		5.0f, 14.0f, 5.5f, 12.5f,
		5.5f, 12.5f, 6.5f, 13.5f,
		6.5f, 13.5f, 7.0f, 12.5f,
		7.0f, 12.5f, 8.5f, 13.5f,
		8.5f, 13.5f, 8.0f, 12.0f,
		8.0f, 12.0f, 9.5f, 11.5f,
		9.5f, 11.5f, 8.5f, 10.5f,
		8.5f, 10.5f, 10.0f, 9.5f,
		10.0f, 9.5f, 8.5f, 9.0f,
		8.5f, 9.0f, 9.0f, 7.5f,
		9.0f, 7.5f, 7.5f, 8.0f,
		7.5f, 8.0f, 7.0f, 6.5f,
		7.0f, 6.5f, 6.0f, 7.5f,
		6.0f, 7.5f, 5.5f, 6.0f,
		5.5f, 6.0f, 5.0f, 7.0f,
		5.0f, 7.0f, 4.5f, 6.0f,
		4.5f, 6.0f, 4.0f, 7.5f,
		4.0f, 7.5f, 3.0f, 6.5f,
		3.0f, 6.5f, 2.5f, 8.0f,
		2.5f, 8.0f, 1.0f, 7.5f,

		// �����
		4.0f, 9.0f, 2.0f, 10.0f,
		4.0f, 9.0f, 2.0f, 9.0f,
		4.0f, 9.0f, 2.5f, 8.5f,

		6.0f, 9.0f, 8.5f, 10.0f,
		6.0f, 9.0f, 8.0f, 9.0f,
		6.0f, 9.0f, 7.5f, 8.5f,

		// ������
		5.0f, 7.5f, 3.5f, 8.0f,
		3.5f, 8.0f, 2.5f, 9.5f,
		2.5f, 9.5f, 2.5f, 10.5f,
		2.5f, 10.5f, 3.5f, 10.0f,
		3.5f, 10.0f, 6.5f, 10.0f,
		6.5f, 10.0f, 7.5f, 10.5f,
		7.5f, 10.5f, 7.5f, 9.5f,
		7.5f, 9.5f, 6.5f, 8.0f,
		6.5f, 8.0f, 5.0f, 7.5f,

		// ��� + ������ ����� ������
		3.5f, 8.0f, 5.0f, 9.0f,
		5.0f, 9.0f, 6.5f, 8.0f,
		4.25f, 8.5f, 5.75f, 8.5f,
		4.25f, 8.5f, 5.0f, 8.0f,
		5.0f, 8.0f, 5.75f, 8.5f,

		// �������
		3.5f, 10.0f, 3.5f, 11.5f,
		3.5f, 11.5f, 4.0f, 11.0f,
		4.0f, 11.0f, 4.5f, 12.0f,
		4.5f, 12.0f, 5.0f, 11.0f,
		5.0f, 11.0f, 5.5f, 12.0f,
		5.5f, 12.0f, 6.0f, 11.0f,
		6.0f, 11.0f, 6.5f, 11.5f,
		6.5f, 11.5f, 6.5f, 10.0f,

		// ����� ����
		4.0f, 10.0f, 4.0f, 10.5f,
		4.0f, 10.5f, 4.5f, 11.0f,
		4.5f, 11.0f, 5.0f, 10.5f,

		// ����� ������
		4.25f, 10.0f, 4.25f, 10.5f,
		4.25f, 10.5f, 4.5f, 10.75f,
		4.5f, 10.75f, 4.75f, 10.5f,
		4.75f, 10.5f, 4.75f, 10.0f,

		// ������ ����
		5.0f, 10.0f, 5.0f, 10.5f,
		5.0f, 10.5f, 5.5f, 11.0f,
		5.5f, 11.0f, 6.0f, 10.5f,
		6.0f, 10.5f, 6.0f, 10.0f,

		// ������ ������
		5.25f, 10.0f, 5.25f, 10.5f,
		5.25f, 10.5f, 5.5f, 10.75f,
		5.5f, 10.75f, 5.75f, 10.5f,
		5.75f, 10.5f, 5.75f, 10.0f,

		// ���
		4.5f, 10.0f, 5.0f, 9.0f,
		5.0f, 9.0f, 5.5f, 10.0f,
	};
	float lion_vx = 10.5f; // ������ ������� �� ����������� 
	float lion_vy = 14.5f; // ������ ������� �� ���������

	System::Void drawPic(
		Graphics^ g, 
		Pen^ pen, 
		const std::vector<float>& lines, 
		float vx, 
		float vy, 
		float wx, 
		float wy, 
		bool keepAspectRatio
	) {
		float aspectForm = wx / wy;
		float aspectFig = vx / vy;
		float Sx, Sy;

		if (keepAspectRatio) 
		{
			Sx = Sy = aspectFig < aspectForm ? wy / vy : wx / vx;
		}
		else 
		{
			Sx = wx / vx;
			Sy = wy / vy;
		}

		float Ty = Sy * vy;

		for (int i = 0; i < lines.size(); i += 4) {
			g->DrawLine(
				pen,
				Sx * lines[i],
				Ty - Sy * lines[i + 1],
				Sx * lines[i + 2],
				Ty - Sy * lines[i + 3]
			);
		}
	}

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 743);
			this->DoubleBuffered = true;
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
	private: Animal animal;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true;
		animal = Animal::Lion;
	}

	private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width;
		float Wy = ClientRectangle.Height;

		switch (animal) {
		case Animal::Lion:
			drawPic(g, blackPen, lion_lines, lion_vx, lion_vy, Wx, Wy, keepAspectRatio);
			break;
		case Animal::Hare:
			drawPic(g, blackPen, hare_lines, hare_vx, hare_vy, Wx, Wy, keepAspectRatio);
			break;
		}
	}

	private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			animal = static_cast<Animal>((static_cast<short>(animal) + 1) % 2);
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
