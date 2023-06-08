#include "main.h"
/**
 * displayMenu - main menu of the program
 * @head: head of students Linked list
 *
 * Return: Nothing
 */

void displayMenu(StudentNode* head)
{
	bool exitMenu = false;
	while (!exitMenu)
	{
		std::cout << "\n\n█▄█ █▀▀ ▄▀█ █▄▄   █▀▀ █▀▀ █▀█ ▄▀█\n";
		std::cout << "░█░ ██▄ █▀█ █▄█   █▄▄ █▄█ █▀▀ █▀█\n";
		
		std::cout << "╔════════════════════════════════╗\n";
		std::cout << "║             Menu               ║\n";
		std::cout << "╠════════════════════════════════╣\n";
		std::cout << "║ 1. Add Student                 ║\n";
		std::cout << "║ 2. Delete Student              ║\n";
		std::cout << "║ 3. List all added students     ║\n";
		std::cout << "║ 4. Add Subjects for a student  ║\n";
		std::cout << "║ 5. Display Subjects with Grades║\n";
		std::cout << "║ 6. Save data                   ║\n";
		std::cout << "║ 7. Load Data                   ║\n";
		std::cout << "║ 8. Exit                        ║\n";
		std::cout << "╚════════════════════════════════╝\n";
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
			clearTerminal();
    			std::cout << "Stdudent added successfuly!\n";
			break;
		}
		case 2:
		{
			std::string studentName;
			std::cout << "Enter the name of the student to delete: ";
			std::cin.ignore();
			std::getline(std::cin, studentName);
			head = delStud(head, studentName);
			break;
		}

		case 3:
		{
			listAllStudents(head);
			std::cin.ignore();
			clearTerminal();
			break;
		}

		case 4:
		{
			std::string studentName;
			std::cout << "Enter student name: ";
			std::cin.ignore(); // Ignore any previous newline character
			std::getline(std::cin, studentName);

			StudentNode* currentStudent = findStudent(head, studentName);
			if (currentStudent != nullptr)
			{
				addSubjectInfo(currentStudent);
			}
			else
			{
				clearTerminal();
				std::cout << "Student not found.\n";
			}
			break;
		}
		case 5:
		{
			std::string studentName;
			std::cout << "Enter student name: ";
			std::cin.ignore(); // Ignore any previous newline character
			std::getline(std::cin, studentName);
			StudentNode* current = findStudent(head, studentName);
			if (current != nullptr)
			{
				displaySubjects(current);
			}
			else
			{
				clearTerminal();
				std::cout << "Student not found.\n";
			}
			break;
		}
		case 6:
		{
			std::string filename;
			std::cout << "Enter filename to save data: ";
			std::cin >> filename;
			saveDataToFile(filename, head);
			break;
		}


		case 7:
			loadData(head);
			break;

		case 8:
			cleanMemory(head);
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

/**
 * main - main function where it all starts
 * 
 * Return: 0(success)
 */

int main(void)
{
	StudentNode* head = nullptr;

	// Display menu
	displayMenu(head);
	return (0);
}
