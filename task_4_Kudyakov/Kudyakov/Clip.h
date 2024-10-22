#pragma once

#include "Matrix.h"
#include <algorithm>

unsigned codeKS(Vec2 P, float minX, float minY, float maxX, float maxY) {
	unsigned code = 0;

	if (P.x < minX) {
		code += 1;
	}

	if (P.x > maxX) {
		code += 2;
	}

	if (P.y < minY) {
		code += 4;
	}

	if (P.y > maxY) {
		code += 8;
	}

	return code;
}

bool clip(Vec2& a, Vec2& b, float minX, float maxX, float minY, float maxY) {
	unsigned codeA = codeKS(a, minX, minY, maxX, maxY);
	unsigned codeB = codeKS(b, minX, minY, maxX, maxY);

	while (codeA | codeB) {
		if (codeA & codeB) {
			return false;
		}

		if (codeA == 0) {
			std::swap(a, b);
			std::swap(codeA, codeB);
		}

		if (codeA & 1) {
			a.y = a.y + (b.y - a.y) * (minX - a.x) / (b.x - a.x);
			a.x = minX;
		}
		else if (codeA & 2) {
			a.y = a.y + (b.y - a.y) * (maxX - a.x) / (b.x - a.x);
			a.x = maxX;
		}
		else if (codeA & 4) {
			a.x = a.x + (b.x - a.x) * (minY - a.y) / (b.y - a.y);
			a.y = minY;
		}
		else {
			a.x = a.x + (b.x - a.x) * (maxY - a.y) / (b.y - a.y);
			a.y = maxY;
		}

		codeA = codeKS(a, minX, minY, maxX, maxY);
	}

	return true;
}
