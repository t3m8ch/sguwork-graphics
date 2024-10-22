#pragma once

#include "Matrix.h"
#include <vector>

class Path {
public:
	std::vector<Vec2> vertices;
	Vec3 color;
	float thickness;

	Path(std::vector<Vec2> vertices, Vec3 color, float thickness) {
		this->vertices = vertices;
		this->color = color;
		this->thickness = thickness;
	}
};
