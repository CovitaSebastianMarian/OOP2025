#include "Sort.h"
#include <random>
#include <cstdarg>

Sort::~Sort() {
    delete[] this->v;
}

Sort::Sort(unsigned long long len, int mi, int mx)
{
    this->v = new int[len];
    this->size = len;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(mi, mx);

    for (unsigned long long i = 0; i < len; i++) {
        this->v[i] = dist(gen);
    }
}

Sort::Sort(std::initializer_list<int> li)
{
    this->v = new int[li.size()];
    this->size = li.size();
    int i = 0;
    for (auto val : li) {
        v[i++] = val;
    }
}

Sort::Sort(int* a, int len)
{
    this->v = new int[len];
    this->size = len;
    memcpy(v, a, len * sizeof(int));
}

Sort::Sort(int n, ...)
{
    this->v = new int[n];
    this->size = n;
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; ++i) {
        v[i] = va_arg(va, int);
    }
    va_end(va);
}

Sort::Sort(const char* str)
{
    int len = strlen(str);
    int sze = 1;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ',') sze++;
    }
    this->v = new int[sze];
    this->size = sze;
    int nr = 0;
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ',') {
            this->v[j++] = nr;
            nr = 0;
        }
        else {
            nr = nr * 10 + (str[i] - '0');
        }
    }
    this->v[j++] = nr;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < this->size; ++i) {
        int key = this->v[i];
        int j = i - 1;
        if (ascendent) {
            while (j >= 0 && this->v[j] > key) {
                this->v[j + 1] = this->v[j];
                --j;
            }
        }
        else {
            while (j >= 0 && this->v[j] < key) {
                this->v[j + 1] = this->v[j];
                --j;
            }
        }
        this->v[j + 1] = key;
    }
}

void Sort::QuickSortFunc(int st, int dr, bool ascendent) {
    if (st >= dr) return;

    int m = (st + dr) / 2;

    std::swap(this->v[m], this->v[st]);

    int i = st, j = dr, d = 0;
    while (i < j) {
        if (ascendent) {
            if (this->v[i] > this->v[j]) {
                std::swap(this->v[i], this->v[j]);
                d = 1 - d;
            }
        }
        else {
            if (this->v[i] < this->v[j]) {
                std::swap(this->v[i], this->v[j]);
                d = 1 - d;
            }
        }
        i += d;
        j -= 1 - d;
    }

    QuickSortFunc(st, i - 1, ascendent);
    QuickSortFunc(i + 1, dr, ascendent);
}

void Sort::QuickSort(bool ascendent) {
    QuickSortFunc(0, this->size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < this->size - 1; ++i) {
            if (ascendent) {
                if (this->v[i] > this->v[i + 1]) {
                    std::swap(this->v[i], this->v[i + 1]);
                    ok = true;
                }
            }
            else {
                if (this->v[i] < this->v[i + 1]) {
                    std::swap(this->v[i], this->v[i + 1]);
                    ok = true;
                }
            }
        }
    }
}

void Sort::Print()
{
    for (int i = 0; i < size; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int Sort::GetElementsCount()
{
    return this->size;
}

int Sort::GetElementFromIndex(int index)
{
    return this->v[index];
}
