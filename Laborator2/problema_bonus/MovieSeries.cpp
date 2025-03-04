#include "MovieSeries.h"
#include <iostream>

void MovieSeries::init()
{
	this->movies = nullptr;
	this->size = 0;
}

void MovieSeries::add(Movie* movie)
{
	Movie** new_movies = new Movie * [this->size + 1];
	for (unsigned long long i = 0; i < this->size; i++)
	{
		new_movies[i] = this->movies[i];
	}
	new_movies[this->size] = movie;
	delete[] this->movies;
	this->movies = new_movies;
	this->size++;
}

void MovieSeries::sort()
{
	bool ok = true;
	while (ok) {
		ok = false;
		for (unsigned long long i = 0; i < this->size - 1; i++)
		{
			if (movie_compare_name(*this->movies[i], *this->movies[i + 1]) > 0)
			{
				Movie* aux = this->movies[i];
				this->movies[i] = this->movies[i + 1];
				this->movies[i + 1] = aux;
				ok = true;
			}
		}
	}
}

void MovieSeries::print()
{
	for (unsigned long long i = 0; i < this->size; i++)
	{
		std::cout << this->movies[i]->get_name() << "\n";
	}
	std::cout << "\n";
}
