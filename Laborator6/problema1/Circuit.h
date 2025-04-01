#pragma once

#include "Car.h"
class Circuit
{
private:
	int length;
	Weather weather;
	Car** cars;
	unsigned long long size;
public:
	Circuit();
	~Circuit();
	void SetLength(int);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

