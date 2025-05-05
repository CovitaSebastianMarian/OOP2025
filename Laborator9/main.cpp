#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

#include "Map.h"



int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

	m.Delete(20);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m.Clear();
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m.Set(20, "test");
	m.Set(30, "test");
	m.Set(40, "test");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}


    return 0;
}