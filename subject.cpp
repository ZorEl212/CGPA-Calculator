#include "main.h"

void insertSubject(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName)
{
	SubjectNode* newNode = new SubjectNode(subjectName, score, creditHours, gradePoint);
	
	
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		SubjectNode* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void displaySubjects(StudentNode* student)
{
	if (student->subjects == nullptr)
	{
		std::cout << "No subjects found for " << student->studentName << std::endl;
		return;
	}
	
	std::cout << "Subjects with Grades for " << student->studentName << ":\n";
	SubjectNode* current = student->subjects;
	while (current != nullptr)
	{
		std::cout << "Subject: " << current->subjectName << "\n";
		std::cout << "Grade: " << current->score << "\n\n";
		current = current->next;
	}
}

void inputSubjectDetails(int& numSubjects, std::vector<std::string>& subjectNames, std::vector<int>& creditHours)
{
	std::cout << "Enter the number of subjects: ";
	std::cin >> numSubjects;
	if (std::cin.fail())
	{
		// Clear the fail state of std::cin
		std::cin.clear();
		
		// Ignore the remaining characters in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Please enter number only.\n";
		inputSubjectDetails(numSubjects, subjectNames, creditHours);
		return;
		
	}
	
	subjectNames.resize(numSubjects);
	creditHours.resize(numSubjects);
	
	for (int i = 0; i < numSubjects; i++)
	{
		std::cout << "Enter subject name for subject " << i + 1 << ": ";
		std::cin.ignore();
		std::getline(std::cin, subjectNames[i]);
		
		std::cout << "Enter credit hours for subject " << subjectNames[i] << ": ";
		std::cin >> creditHours[i];
		
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Please enter a number only.\n";
			std::cout << "Enter credit hours for subject " << subjectNames[i] << ": ";
			std::cin >> creditHours[i];
		}
	}
}

