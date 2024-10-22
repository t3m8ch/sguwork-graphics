#pragma once

class Vec2 {
public:
	float x, y;
	Vec2() : x(0.0f), y(0.0f) {}
	Vec2(float x, float y) : x(x), y(y) {}
};

class Vec3 {
public:
	float x, y, z;
	Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3(Vec2 v, float z) : Vec3(v.x, v.y, z) {}

	Vec3& operator *= (const Vec3& v) {
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	const Vec3 operator * (const Vec3& v) {
		return Vec3(*this) *= v;
	}

	float& operator[] (int i) {
		return ((float*)this)[i];
	}
};

float dot(Vec3 v1, Vec3 v2) {
	Vec3 tmp = v1 * v2;
	return tmp.x + tmp.y + tmp.z;
}

class Mat3 {
public:
	Vec3 row1, row2, row3;
	Mat3() {}
	Mat3(Vec3 row1, Vec3 row2, Vec3 row3) : row1(row1), row2(row2), row3(row3) {}
	Mat3(float a) {
		row1 = Vec3(a, 0.0f, 0.0f);
		row2 = Vec3(0.0f, a, 0.0f);
		row3 = Vec3(0.0f, 0.0f, a);
	}

	Vec3& operator[](int i) {
		return ((Vec3*)this)[i];
	}

	Mat3 transpose() {
		Mat3 tmp(*this);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				(*this)[i][j] = tmp[j][i];
			}
		}

		return *this;
	}

	const Vec3 operator * (const Vec3& v) {
		Vec3 res;
		for (int i = 0; i < 3; i++) {
			res[i] = dot((*this)[i], v);
		}
		return res;
	}

	Mat3 operator *= (const Mat3& m) {
		Mat3 A(*this), B(m);
		B.transpose();
		for (int i = 0; i < 3; i++) {
			(*this)[i] = A * B[i];
		}

		return (*this).transpose();
	}

	const Mat3 operator * (const Mat3& m) {
		return Mat3(*this) *= m;
	}
};

Vec2 normalize(Vec3 v) {
	return Vec2(v.x / v.z, v.y / v.z);
}
