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

class Model {
public:
	std::vector<Path> figure;
	Mat3 modelM;

	Model(std::vector<Path> figure, Mat3 modelM) {
		this->figure = figure;
		this->modelM = modelM;
	}
};
