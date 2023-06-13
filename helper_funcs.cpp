#include "main.h"
#include <chrono>
#include <thread>

/**
* calculateCGPA - calculate cgpa for a particular student
* @student: student node for a particular student
* 
* Return: calculated cgpa
*/

double calculateGPA(StudentNode* student)
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

/**
 * waitForEnterKey - just a dummy func to wait for enter key
 *
 * Return: Nothing
 */

void waitForEnterKey()
{
    std::cout << "Press Enter to continue...";
    std::cin.get();    // Wait for a single character input (Enter key)
}

/**
* clearTerminal - clears terminal after a certain operation
*
* Return: nothing
*/

void clearTerminal()
{
//	std::this_thread::sleep_for(std::chrono::seconds(1));
#ifdef _WIN32
        // Use the "cls" command on Windows
        system("cls");
#else
        // Use the "clear" command on Unix-like systems
       system("clear");
#endif
}
