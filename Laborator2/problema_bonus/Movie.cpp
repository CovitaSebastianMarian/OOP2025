#include "Movie.h"
#pragma warning(disable : 4996)
#include <cstring>

Movie::Movie()
{
	this->name[0] = '\0';
	this->year = 0;
	this->score = 0;
	this->length = 0;
}

void Movie::set_name(const char* name)
{
	strcpy(this->name, name);
}

void Movie::set_year(int year)
{
	this->year = year;
}

void Movie::set_score(short score)
{
	this->score = score;
}

void Movie::set_length(short lenght)
{
	this->length = lenght;
}

const char* Movie::get_name()
{
	return this->name;
}

short Movie::get_year()
{
	return this->year;
}

short Movie::get_score()
{
	return this->score;
}

short Movie::get_length()
{
	return this->length;
}

short Movie::get_passed_years()
{
	const char* sy = __DATE__ + 7;
	short current_year = (sy[0] - '0') * 1000 + (sy[1] - '0') * 100 + (sy[2] - '0') * 10 + (sy[3] - '0');
	return current_year - this->year;
}

short movie_compare_name(Movie m1, Movie m2)
{
	return strcmp(m1.get_name(), m2.get_name());
}

short movie_compare_year(Movie m1, Movie m2)
{
	if (m1.get_year() == m2.get_year())
		return 0;
	else if (m1.get_year() < m2.get_year())
		return -1;
	else
		return 1;
}

short movie_compare_score(Movie m1, Movie m2)
{
	if (m1.get_score() == m2.get_score())
		return 0;
	else if (m1.get_score() < m2.get_score())
		return -1;
	else
		return 1;
}

short movie_compare_length(Movie m1, Movie m2)
{
	if (m1.get_length() == m2.get_length())
		return 0;
	else if (m1.get_length() < m2.get_length())
		return -1;
	else
		return 1;
}

short movie_compare_passed_years(Movie m1, Movie m2)
{
	if (m1.get_passed_years() == m2.get_passed_years())
		return 0;
	else if (m1.get_passed_years() < m2.get_passed_years())
		return -1;
	else
		return 1;
}


