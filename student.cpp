#include "main.h"

void insertStudent(StudentNode*& head, const std::string& studentName)
{
	StudentNode* newNode = new StudentNode(studentName);
	if (newNode == nullptr)
		return;
	
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		StudentNode* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		cleanupMemory(newNode);
	}
}

void inputStudentDetails(std::string& studentName)
{
	std::cout << "Enter student name: ";
	std::cin.ignore();
	std::getline(std::cin, studentName);
}

void inputScores(SubjectNode*& head, const std::vector<std::string>& subjectNames, const std::vector<int>& creditHours)
{
	for (int i = 0; i < subjectNames.size(); i++)
	{
		double score;
		std::cout << "Enter score for subject " << subjectNames[i] << ": ";
		std::cin >> score;
		if (std::cin.fail())
		{
			std::cin.clear();
			
			// Ignore the remaining characters in the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please Enter correct input.\n";
			inputScores(head, subjectNames, creditHours);
			return;
		}
		double gradePoint;
		
		if (score >= 85)
		{
			gradePoint = 4.0;
		}
		else if (score >= 80)
		{
			gradePoint = 3.75;
		}
		else if (score >= 75)
		{
			gradePoint = 3.5;
		}
		else if (score >= 70)
		{
			gradePoint = 3.0;
		}
		else if (score >= 65)
		{
			gradePoint = 2.75;
		}
		else if (score >= 60)
		{
			gradePoint = 2.5;
		}
		else if (score >= 50)
		{
			gradePoint = 2.0;
		}
		else if (score >= 45)
		{
			gradePoint = 1.75;
		}
		else if (score >= 40)
		{
			gradePoint = 1.0;
		}
         else
	 {
		 gradePoint = 0.0;
	 }

		
		insertNode(head, score, creditHours[i], gradePoint, subjectNames[i]);
	}
}
