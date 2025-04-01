#pragma once

enum class Weather {
    Rain, Sunny, Snow
};

class Car {
protected:
    float fuelCapacity;
    float fuelConsumption;
    float averageSpeed[3];
public:
    virtual float GetSpeed(Weather weather) const = 0;
    virtual float GetFuelConsumption() const = 0;
    virtual float GetFuelCapacity() const = 0;
    virtual const char* GetName() const = 0;
};