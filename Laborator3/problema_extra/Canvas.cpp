#include "Canvas.h"
#include <iostream>
#include <cstdarg>
Canvas::Canvas(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;
	mat = new char* [lines];
	for (int i = 0; i < lines; i++)
	{
		mat[i] = new char[columns];
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] = ' ';
		}
	}
}

void Canvas::set_pixel(int x, int y, char value)
{
	if (x >= 0 && x < lines && y >= 0 && y < columns)
	this->mat[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = va_arg(args, char);
		set_pixel(x, y, value);
	}
}

void Canvas::clear()
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] = ' ';
		}
	}
}

void Canvas::print() const
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}
