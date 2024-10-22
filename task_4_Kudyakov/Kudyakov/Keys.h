#pragma once

#include "Matrix.h"
#include "Transform.h"

using namespace System::Windows::Forms;

void handleKeyDown(Keys key, bool^& keepAspectRatio, Mat3& T, float Wcx, float Wcy) {
	switch (key) {
	case Keys::M:
		keepAspectRatio = !keepAspectRatio;
		break;
	case Keys::Q:
		T = translate(-Wcx, -Wcy) * T;
		T = rotate(0.01f) * T;
		T = translate(Wcx, Wcy) * T;
		break;
	case Keys::W:
		T = translate(0.f, -1.f) * T;
		break;
	case Keys::Escape:
		T = Mat3(1.f);
		break;
	default:
		break;
	}
}
