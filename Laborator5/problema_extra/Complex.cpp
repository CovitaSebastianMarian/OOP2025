#include "Complex.h"

#include "Complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex Complex::operator-() const
{
    return { -real_data, -imag_data };
}

Complex& Complex::operator++()
{
    real_data++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex& Complex::operator--()
{
    real_data--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex temp = *this;
    --(*this);
    return temp;
}

Complex operator+(const Complex& l, const Complex& r)
{
    return { l.real_data + r.real_data, l.imag_data + r.imag_data };
}

Complex operator+(const Complex& l, double r)
{
    return { l.real_data + r, l.imag_data};
}

Complex operator+(double l, const Complex& r)
{
    return { l + r.real_data, r.imag_data };
}

Complex operator-(const Complex& l, const Complex& r)
{
    return { l.real_data - r.real_data, l.imag_data - r.imag_data };
}

Complex operator-(const Complex& l, double r)
{
    return { l.real_data - r, l.imag_data };
}

Complex operator-(double l, const Complex& r)
{
    return { r.real_data - l, r.imag_data };
}

Complex operator*(const Complex& l, const Complex& r)
{
    return { l.real_data * r.real_data - l.imag_data * r.imag_data,
             l.real_data * r.imag_data + l.imag_data * r.real_data };
}

Complex operator*(const Complex& l, double r)
{
    return { l.real_data * r, l.imag_data * r };
}

Complex operator*(double l, const Complex& r)
{
    return { l * r.real_data, l * r.imag_data };
}

bool operator==(const Complex& l, const Complex& r)
{
    return l.real_data == r.real_data && l.imag_data == r.imag_data;
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << "(" << complex.real_data << " + " << complex.imag_data << "i)";
    return out;
}
