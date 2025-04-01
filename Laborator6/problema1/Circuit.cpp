#include "Circuit.h"
#include <iostream>
#include <memory>
Circuit::Circuit()
{
	cars = nullptr;
	size = 0;
}

Circuit::~Circuit()
{
	delete[] cars;
}

void Circuit::SetLength(int len)
{
	length = len;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* car)
{
    Car** c = new Car * [size + 1];
    if (cars) {
        memcpy(c, cars, sizeof(Car*) * size);
        delete[] cars;
    }
    c[size] = car;
    size++;
    cars = c;
}

void Circuit::Race()
{
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < size - 1; ++i) {
            if (cars[i]->GetSpeed(weather) < cars[i]->GetSpeed(weather)) {
                std::swap(cars[i], cars[i + 1]);
                ok = true;
            }
        }
    }
}

void Circuit::ShowFinalRanks()
{
    int cnt = 1;
    for (int i = 0; i < size; ++i) {
        float x = cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption() * 100.f;
        if (x >= length) {
            std::cout << cnt++ << " " << cars[i]->GetName() << "\n";
        }
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < size; ++i) {
        float x = cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption() * 100.f;
        if (x <= length) {
            std::cout << cars[i]->GetName() << "\n";
        }
    }
}
