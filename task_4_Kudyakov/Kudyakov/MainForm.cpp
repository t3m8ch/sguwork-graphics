#include "MainForm.h"
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kudyakov::MainForm form;
	Application::Run(% form);
}