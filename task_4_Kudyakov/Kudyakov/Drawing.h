#pragma once

#include <vector>
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include "Clip.h"

using namespace System;
using namespace System::Drawing;

System::Void drawPic(
	Graphics^ g,
	const std::vector<Path>& figure,
	Mat3& T,
	Mat3& initT,
	float vx,
	float vy,
	int wx,
	int wy,
	int left,
	int right,
	int top, 
	int bottom
) {
	Pen^ rectPen = gcnew Pen(Color::Black, 2);
	g->DrawRectangle(rectPen, left, top, wx - left - right, wy - top - bottom);

	float minX = left, maxX = wx - right;
	float minY = top, maxY = wy - bottom;

	wx = wx - left - right;
	wy = wy - top - bottom;

	float aspectRect = float(wx) / wy;
	
	float aspectFig = vx / vy;
	float S = aspectFig < aspectRect ? wy / vy : wx / vx;

	float Tx = left;
	float Ty = S * vy + top;

	initT = translate(Tx, Ty) * scale(S, -S);

	Mat3 M = T * initT;

	for (int i = 0; i < figure.size(); i++) {
		Path lines = figure[i];
		Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
		pen->Width = lines.thickness;

		Vec2 start = normalize(M * Vec3(lines.vertices[0], 1.0));
		for (int j = 1; j < lines.vertices.size(); j++) {
			Vec2 end = normalize(M * Vec3(lines.vertices[j], 1.0));
			Vec2 tmpEnd = end;
			if (clip(start, end, minX, maxX, minY, maxY)) {
				g->DrawLine(pen, start.x, start.y, end.x, end.y);
			}
			start = tmpEnd;
		}
	}
}
