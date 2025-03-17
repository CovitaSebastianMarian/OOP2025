#pragma once
#include <iostream>
class Sort
{
    // add data members
    int* v;
    unsigned long long size;
    void QuickSortFunc(int, int, bool);
public:
    // add constuctors
    Sort(unsigned long long, int, int);
    Sort(std::initializer_list<int>);
    Sort(int*, int);
    Sort(int, ...);
    Sort(const char*);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};