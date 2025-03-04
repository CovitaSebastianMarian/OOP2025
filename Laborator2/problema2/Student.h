#pragma once

class Student
{
private:
	char name[100];
	short math_grade;
	short english_grade;
	short history_grade;
public:
	Student();
	void setName(const char* name);
	void setMathGrade(short math_grade);
	void setEnglishGrade(short english_grade);
	void setHistoryGrade(short history_grade);
	char* getName();
	short getMathGrade();
	short getEnglishGrade();
	short getHistoryGrade();
	float getAverage();
};

short CompareStudentsName(Student student1, Student student2);
short CompareStudentsMathGrade(Student student1, Student student2);
short CompareStudentsEnglishGrade(Student student1, Student student2);
short CompareStudentsHistoryGrade(Student student1, Student student2);
short CompareStudentsAverage(Student student1, Student student2);
