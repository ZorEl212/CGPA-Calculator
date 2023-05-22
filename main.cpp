#include "main.h"

void displayMenu(StudentNode* head)
{
	bool exitMenu = false;
	while (!exitMenu)
	{
		std::cout << "\nMenu:\n";
		std::cout << "1. Add Student\n";
		std::cout << "2. Add Subjects for a student\n";
		std::cout << "3. Calculate CGPA\n";
		std::cout << "4. Display Subjects with Grades\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice: ";
		
		int choice;
		std::cin >> choice;
		
		switch (choice)
		{
		case 1:
		{
			std::string student1;
			inputStudentDetails(student1);
			insertStudent(head, student1);
			break;
		}
		
		case 2:
		{
			std::string studentName;
			std::cout << "Enter student name: ";
			std::cin.ignore(); // Ignore any previous newline character
			std::getline(std::cin, studentName);
			
			StudentNode* currentStudent = head;
			while (currentStudent != nullptr)
			{
				if (currentStudent->studentName == studentName)
				{
					int numSubjects;
					std::vector<std::string> subjectNames;
					std::vector<int> creditHours;
					
					inputSubjectDetails(numSubjects, subjectNames, creditHours);
					
					SubjectNode* head2 = nullptr;
					inputScores(head2, subjectNames, creditHours);
					
					// Insert subjects into the linked list of subjects for the current student
					SubjectNode* currentSubject = head2;
					while (currentSubject != nullptr)
					{
						insertSubject(currentStudent->subjects, currentSubject->score, currentSubject->creditHours, currentSubject->gradePoint, currentSubject->subjectName);
						currentSubject = currentSubject->next;
					}
					
					// Free the memory of the temporary subject list
					freeSubject(head2);
					
					break;
				}
				
				currentStudent = currentStudent->next;
			}
			
			if (currentStudent == nullptr)
			{
				std::cout << "Student not found.\n";
			}
			break;
		}
		
   		
		case 3:
		{
			std::string studentName;
			std::cout << "Enter student name: ";
			std::cin.ignore(); // Ignore any previous newline character
			std::getline(std::cin, studentName);
			
			StudentNode* current = head;
			while (current != nullptr)
			{
				if (current->studentName == studentName)
				{
					double cgpa = calculateCGPA(current);
					printCGPA(studentName, cgpa);
					break;
				}
				current = current->next;
			}
			
			if (current == nullptr)
			{
				std::cout << "Student not found.\n";
			}
			break;
		}
		case 4:
		{
			std::string studentName;
			std::cout << "Enter student name: ";
			std::cin.ignore(); // Ignore any previous newline character
			std::getline(std::cin, studentName);
			
			StudentNode* current = head;
			while (current != nullptr)
			{
				if (current->studentName == studentName)
				{
					displaySubjects(current);
					break;
				}
				current = current->next;
			}
			
			if (current == nullptr)
			{
				std::cout << "Student not found.\n";
			}
			break;
		}
		case 5:
			exitMenu = true;
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			std::cin.clear(); // Clear the error state of the input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input
			break;
		}
	}
}

int main(void)
{
	StudentNode* head = nullptr;
	
	
	// Display menu
	displayMenu(head);
	
	// Clean up memory
	cleanupMemory(head);
	
	return (0);
}

