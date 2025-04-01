#pragma once
#include "Car.h"
class Seat : public Car {
public:
    Seat();
    float GetSpeed(Weather weather) const override;
    float GetFuelConsumption() const override;
    float GetFuelCapacity() const override;
    const char* GetName() const override;
};

