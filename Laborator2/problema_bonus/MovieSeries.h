#pragma once
#include "Movie.h"

class MovieSeries
{
private:
	Movie** movies;
	unsigned long long size;
public:
	void init();
	void add(Movie* movie);
	void sort();
	void print();
};

