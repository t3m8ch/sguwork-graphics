#pragma once

#include "Matrix.h"
#include <math.h>

Mat3 translate(float Tx, float Ty) {
	Mat3 res = Mat3(1.f);
	res[0][2] = Tx;
	res[1][2] = Ty;
	return res;
}

Mat3 scale(float Sx, float Sy) {
	Mat3 res = Mat3(1.f);
	res[0][0] = Sx;
	res[1][1] = Sy;
	return res;
}

Mat3 rotate(float theta) {
	Mat3 res = Mat3(1.0f);
	res[0][0] = res[1][1] = (float)cos(theta);
	res[0][1] = (float)sin(theta);
	res[1][0] = -res[0][1];
	return res;
}

Mat3 mirrorX() {
	return Mat3(
		Vec3(-1.f, 0.f, 0.f),
		Vec3(0.f, 1.f, 0.f),
		Vec3(0.f, 0.f, 1)
	);
}

Mat3 mirrorY() {
	return Mat3(
		Vec3(1.f, 0.f, 0.f),
		Vec3(0.f, -1.f, 0.f),
		Vec3(0.f, 0.f, 1)
	);
}
