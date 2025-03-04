#pragma once
class Movie
{
private:
	char name[256];
	short year;
	short score;
	short length;
public:
	Movie();
	void set_name(const char* name);
	void set_year(int year);
	void set_score(short score);
	void set_length(short lenght);
	const char* get_name();
	short get_year();
	short get_score();
	short get_length();
	short get_passed_years();
};

