

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


float operator""_Kelvin(unsigned long long c) {
    return c - 273.15;
}
float operator""_Fahrenheit(unsigned long long c) {
    return (c - 32.0) * 5.0 / 9.0;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << " " << b << "\n";
    return 0;
}