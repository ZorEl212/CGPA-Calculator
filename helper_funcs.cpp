#include "main.h"

double calculateCGPA(StudentNode* student)
{
	double totalGradePoints = 0.0;
	int totalCreditHours = 0;
	
	SubjectNode* current = student->subjects;
	while (current != nullptr)
	{
		totalGradePoints += current->gradePoint * current->creditHours;
		totalCreditHours += current->creditHours;
		current = current->next;
	}
	
	if (totalCreditHours == 0)
	{
		return 0.0;
	}
	
	return totalGradePoints / totalCreditHours;
}

void printCGPA(const std::string& studentName, double cgpa)
{
	std::cout << "CGPA for " << studentName << ": " << cgpa << std::endl;
}

void clearTerminal()
{
#ifdef _WIN32
        // Use the "cls" command on Windows
        system("cls");
#else
        // Use the "clear" command on Unix-like systems
        system("clear");
#endif
}
