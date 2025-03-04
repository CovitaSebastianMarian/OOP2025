#include "GlobalFunctions.h"
#include <cstring>

short CompareStudentsName(Student student1, Student student2) {
	int cmp = strcmp(student1.getName(), student2.getName());
	if (cmp == 0)
		return 0;
	else if (cmp > 0)
		return 1;
	else
		return -1;
}

short CompareStudentsMathGrade(Student student1, Student student2) {
	if (student1.getMathGrade() == student2.getMathGrade())
		return 0;
	else if (student1.getMathGrade() > student2.getMathGrade())
		return 1;
	else
		return -1;
}

short CompareStudentsEnglishGrade(Student student1, Student student2) {
	if (student1.getEnglishGrade() == student2.getEnglishGrade())
		return 0;
	else if (student1.getEnglishGrade() > student2.getEnglishGrade())
		return 1;
	else
		return -1;
}

short CompareStudentsHistoryGrade(Student student1, Student student2) {
	if (student1.getHistoryGrade() == student2.getHistoryGrade())
		return 0;
	else if (student1.getHistoryGrade() > student2.getHistoryGrade())
		return 1;
	else
		return -1;
}

short CompareStudentsAverage(Student student1, Student student2) {
	if (student1.getAverage() == student2.getAverage())
		return 0;
	else if (student1.getAverage() > student2.getAverage())
		return 1;
	else
		return -1;
}

