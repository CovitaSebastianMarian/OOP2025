#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {
	
	Canvas canvas(20, 20);
	canvas.DrawCircle(10, 10, 5, '*');
	canvas.Print();
	canvas.Clear();
	canvas.FillCircle(10, 10, 5, '*');
	canvas.Print();
	canvas.Clear();
	canvas.DrawRect(5, 5, 15, 15, '*');
	canvas.Print();
	canvas.Clear();
	canvas.FillRect(5, 5, 15, 15, '*');
	canvas.Print();
	canvas.Clear();
	canvas.SetPoint(10, 10, '*');
	canvas.Print();
	canvas.Clear();
	canvas.DrawLine(0, 20, 20, 0, '*');
	canvas.Print();
	canvas.Clear();





	return 0;
}