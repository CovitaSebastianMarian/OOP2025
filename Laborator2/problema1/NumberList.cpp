#include "NumberList.h"
#include <cstdio>

void NumberList::Init() {
	count = 0;
}
bool NumberList::Add(int x) {
	if (count < 10)
	{
		numbers[count] = x;
		count++;
		return true;
	}
	return false;
}
void NumberList::Sort() {
	bool ok = true;
	while (ok) {
		ok = false;
		for (int i = 0; i < count - 1; ++i) {
			if (numbers[i] > numbers[i + 1]) {
				int aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				ok = true;
			}
		}
	}
}
void NumberList::Print()
{
	for (int i = 0; i < count; ++i) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}


