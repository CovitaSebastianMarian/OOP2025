#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i < 360; ++i) {
		int x1 = x + ray * cos(i);
		int y1 = y + ray * sin(i);
		if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
			map[y1][x1] = ch;
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i < 360; ++i) {
		for (int j = 0; j <= ray; ++j) {
			int x1 = x + j * cos(i);
			int y1 = y + j * sin(i);
			if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
				map[y1][x1] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i) {
		for (int j = left; j <= right; ++j) {
			if (j >= 0 && j < width && i >= 0 && i < height) {
				if (i == top || i == bottom || j == left || j == right)
					map[i][j] = ch;
			}
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i) {
		for (int j = left; j <= right; ++j) {
			if (j >= 0 && j < width && i >= 0 && i < height) {
				map[i][j] = ch;
			}
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height) {
		map[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (dx == 0) {
		for (int i = y1; i <= y2; ++i) {
			if (i >= 0 && i < height && x1 >= 0 && x1 < width) {
				map[i][x1] = ch;
			}
		}
	}
	else {
		float m = dy / dx;
		float n = y1 - m * x1;
		for (int i = x1; i <= x2; ++i) {
			int y = m * i + n;
			if (y >= 0 && y < height && i >= 0 && i < width) {
				map[y][i] = ch;
			}
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i][j] = ' ';
		}
	}
}
