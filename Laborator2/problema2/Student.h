#pragma once

class Student
{
private:
	char name[100];
	float math_grade;
	float english_grade;
	float history_grade;
public:
	Student();
	void setName(const char* name);
	void setMathGrade(float math_grade);
	void setEnglishGrade(float english_grade);
	void setHistoryGrade(float history_grade);
	char* getName();
	float getMathGrade();
	float getEnglishGrade();
	float getHistoryGrade();
	float getAverage();
};

short CompareStudentsName(Student student1, Student student2);
short CompareStudentsMathGrade(Student student1, Student student2);
short CompareStudentsEnglishGrade(Student student1, Student student2);
short CompareStudentsHistoryGrade(Student student1, Student student2);
short CompareStudentsAverage(Student student1, Student student2);
