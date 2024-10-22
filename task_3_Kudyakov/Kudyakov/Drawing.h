#pragma once

#include <vector>
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"

using namespace System;
using namespace System::Drawing;

System::Void drawPic(
	Graphics^ g, 
	Pen^ pen, 
	const std::vector<Path>& figure,
	Mat3& T,
	Mat3& initT,
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

	initT = translate(0.0f, Ty) * scale(Sx, -Sy);
	Mat3 M = T * initT;

	for (int i = 0; i < figure.size(); i++) {
		Path lines = figure[i];
		Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
		pen->Width = lines.thickness;

		Vec2 start = normalize(M * Vec3(lines.vertices[0], 1.0));
		for (int j = 1; j < lines.vertices.size(); j++) {
			Vec2 end = normalize(M * Vec3(lines.vertices[j], 1.0));
			g->DrawLine(pen, start.x, start.y, end.x, end.y);
			start = end;
		}
	}
}
