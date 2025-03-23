#include "Number.h"
#include <cstring>
#include <algorithm>
#include <iostream>

#pragma warning(disable : 4996)

Number::Number(const char* value, int base) : base(base), len(strlen(value))
{
    this->value = new char[len + 1];
    strcpy(this->value, value);
}

Number::~Number()
{
    delete[] this->value;
}
Number::Number(int a) : base(10) {
    ConvertFromDecimal(a, 10);
}

Number::Number(const Number& a) : base(a.base), len(a.len)
{
    this->value = new char[len + 1];
    strcpy(this->value, a.value);
}

Number::Number(Number&& a) : base(a.base), value(a.value), len(a.len)
{
    a.value = nullptr;
    a.len = 0;
}

Number& Number::operator=(const Number& a)
{
    if (this != &a) {
        delete[] this->value;
        this->len = a.len;
        this->base = a.base;
        this->value = new char[len + 1];
        strcpy(this->value, a.value);
    }
    return *this;
}

Number& Number::operator=(Number&& a)
{
    if (this != &a) {
        delete[] this->value;
        this->value = a.value;
        this->len = a.len;
        this->base = a.base;
        a.value = nullptr;
        a.len = 0;
    }
    return *this;
}

char Number::operator[](size_t index) const
{
    if (index >= len) throw std::out_of_range("Index out of range");
    return this->value[index];
}

bool Number::operator>(const Number& other) const { return ConvertToDecimal() > other.ConvertToDecimal(); }
bool Number::operator<(const Number& other) const { return ConvertToDecimal() < other.ConvertToDecimal(); }
bool Number::operator>=(const Number& other) const { return ConvertToDecimal() >= other.ConvertToDecimal(); }
bool Number::operator<=(const Number& other) const { return ConvertToDecimal() <= other.ConvertToDecimal(); }
bool Number::operator==(const Number& other) const { return ConvertToDecimal() == other.ConvertToDecimal(); }
bool Number::operator!=(const Number& other) const { return ConvertToDecimal() != other.ConvertToDecimal(); }

Number& Number::operator+=(const Number& other) {
    int sum = ConvertToDecimal() + other.ConvertToDecimal();
    ConvertFromDecimal(sum, base);
    return *this;
}

Number& Number::operator=(int value) {
    ConvertFromDecimal(value, 10);
    base = 10;
    return *this;
}

Number& Number::operator=(const char* str) {
    delete[] value;
    len = strlen(str);
    value = new char[len + 1];
    strcpy(value, str);
    return *this;
}


Number& Number::operator--()
{
    if (len > 1) {
        memmove(value, value + 1, len);
        value[--len] = '\0';
    }
    return *this;
}

Number Number::operator--(int)
{
    Number temp(*this);
    if (len > 1) {
        value[--len] = '\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase)
{
    int nr = ConvertToDecimal();
    ConvertFromDecimal(nr, newBase);
    base = newBase;
}

void Number::Print()
{
    std::cout << this->value << '\n';
}

int Number::GetDigitsCount()
{
    return len;
}

int Number::GetBase()
{
    return base;
}

int Number::ConvertToDecimal() const
{
    int nr = 0;
    for (int i = 0; i < len; ++i) {
        char c = value[i];
        int val = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
        nr = nr * base + val;
    }
    return nr;
}

void Number::ConvertFromDecimal(int nr, int base)
{
    char buffer[100];
    int cnt = 0;
    do {
        int rest = nr % base;
        buffer[cnt++] = (rest < 10) ? rest + '0' : rest - 10 + 'A';
        nr /= base;
    } while (nr > 0);
    buffer[cnt] = '\0';
    std::reverse(buffer, buffer + cnt);

    delete[] value;
    value = new char[cnt + 1];
    strcpy(value, buffer);
    len = cnt;
}

Number operator+(const Number& a, const Number& b)
{
    int bs = std::max(a.base, b.base);
    int sum = a.ConvertToDecimal() + b.ConvertToDecimal();
    Number r("0", bs);
    r.ConvertFromDecimal(sum, bs);
    return r;
}

Number operator-(const Number& a, const Number& b)
{
    int bs = std::max(a.base, b.base);
    int sum = a.ConvertToDecimal() - b.ConvertToDecimal();
    Number r("0", bs);
    r.ConvertFromDecimal(sum, bs);
    return r;
}
