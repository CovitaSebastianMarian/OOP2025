#include "Math.h"
#include <cstring>
#include <iostream>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c)
{
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...)
{
    int s = 0;
    int* p = &count;
    p++;
    for (int i = 0; i < count; ++i) {
        s += *p;
        p++;
    }
    return s;
}

char* Math::Add(const char* a, const char* b)
{
    if (!a || !b) return nullptr;
    int len = std::max(strlen(a), strlen(b)) + 1;
    char* r = new char(len);
    r[0] = '\0';
    int la = strlen(a);
    int lb = strlen(b);
    int mi = std::min(strlen(a), strlen(b));
    int rest = 0, i = 0;
    for (i = 0; i < mi; ++i) {
        int ca = a[--la] - '0';
        int cb = b[--lb] - '0';
        r[i] = (ca + cb + rest) % 10 + '0';
        rest = (ca + cb + rest) / 10;
    }
    while (i < strlen(a)) {
        int ca = a[--la] - '0';
        r[i++] = (ca + rest) % 10 + '0';
        rest = (ca + rest) / 10;
    }
    while (i < strlen(b)) {
        int cb = b[--lb] - '0';
        r[i++] = (cb + rest) % 10 + '0';
        rest = (cb + rest) / 10;
    }
    r[i] = rest;
	std::reverse(r, r + strlen(r));
    return r;
}