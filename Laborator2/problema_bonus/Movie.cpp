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

