#pragma warning(disable : 4996)

#include <iostream>
#include "Student.h"





int main() {
	Student s;
	s.setName("Covita Sebastian-Marian");
	s.setMathGrade(10);
	s.setEnglishGrade(9);
	s.setHistoryGrade(8);

	Student s2;
	s2.setName("Popescu Ion");
	s2.setMathGrade(5);
	s2.setEnglishGrade(6);
	s2.setHistoryGrade(7);

	std::cout << CompareStudentsAverage(s, s2)<<"\n";
	std::cout << CompareStudentsEnglishGrade(s, s2) << "\n";
	std::cout << CompareStudentsHistoryGrade(s, s2) << "\n";
	std::cout << CompareStudentsMathGrade(s, s2) << "\n";
	std::cout << CompareStudentsName(s, s2) << "\n";

	return 0;
}