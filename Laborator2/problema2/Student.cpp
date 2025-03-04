#include "Student.h"
#include <cstring>
#pragma warning(disable : 4996)

Student::Student()
{
	this->name[0] = '\0';
	this->math_grade = 0;
	this->english_grade = 0;
	this->history_grade = 0;
}

void Student::setName(const char* name)
{
	strcpy(this->name, name);
}

void Student::setMathGrade(float math_grade)
{
	this->math_grade = math_grade;
}

void Student::setEnglishGrade(float english_grade)
{
	this->english_grade = english_grade;
}

void Student::setHistoryGrade(float history_grade)
{
	this->history_grade = history_grade;
}

char* Student::getName()
{
	return this->name;
}

float Student::getMathGrade()
{
	return this->math_grade;
}

float Student::getEnglishGrade()
{
	return this->english_grade;
}

float Student::getHistoryGrade()
{
	return this->history_grade;
}

float Student::getAverage()
{
	float avg = (this->math_grade + this->english_grade + this->history_grade) / 3.0f;
	return avg;
}

