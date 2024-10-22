#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"

void loadFigureFromFile(
	wchar_t fileName[1024], 
	std::vector<Path>& figure, 
	float& Vx, 
	float& Vy, 
	float Wx, 
	float Wy, 
	float left,
	float top,
	float& aspectRect,
	Mat3& T
) {
	std::ifstream in;
	in.open(fileName);
	if (in.is_open()) {
		figure.clear();
		float thickness = 2;
		float r, g, b;
		r = g = b = 0;

		std::string str;
		getline(in, str);

		while (in) {
			if ((str.find_first_not_of(" \t\r\n") != std::string::npos) && (str[0] != '#')) {
				std::stringstream s(str);
				std::string cmd;
				s >> cmd;

				if (cmd == "frame") {
					s >> Vx >> Vy;

					aspectRect = Wx / Wy;
					float aspectFig = Vx / Vy;
					float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;

					float Tx = left;
					float Ty = S * Vy + top;

					T = translate(Tx, Ty) * scale(S, -S);
				}
				else if (cmd == "color") {
					s >> r >> g >> b;
				}
				else if (cmd == "thickness") {
					s >> thickness;
				}
				else if (cmd == "path") {
					std::vector<Vec2> vertices;
					int N;
					s >> N;

					std::string str1;
					while (N > 0) {
						getline(in, str1);

						if ((str1.find_first_not_of(" \t\r\n") != std::string::npos) && (str1[0] != '#')) {
							float x, y;
							std::stringstream s1(str1);
							s1 >> x >> y;
							vertices.push_back(Vec2(x, y));
							N--;
						}
					}

					figure.push_back(Path(vertices, Vec3(r, g, b), thickness));
				}
			}

			getline(in, str);
		}
	}
}
