#pragma warning(disable : 4996)

#include <iostream>
#include "NumberList.h"	

int main() {
	NumberList list;
	list.Init();
	list.Add(5);
	list.Add(3);
	list.Add(7);
	list.Add(2);
	list.Add(8);

	list.Sort();
	list.Print();

	return 0;
}