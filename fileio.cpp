#include "main.h"

/**
 * saveDataToFile - saves collected data to a file
 * @filename: name of the file to save to.
 * @head: student node head
 *
 * Return: Nothing
 */

void saveDataToFile(const std::string& filename, StudentNode* head)
{
	clearTerminal();
	std::ofstream outputFile(filename);
	if (!outputFile)
	{
		std::cout << "Error opening file for writing: " << filename << std::endl;
		return;
	}

	// Write each student's data to the file
	StudentNode* currentStudent = head;
	while (currentStudent != nullptr)
	{
		outputFile << currentStudent->studentName << std::endl;

		SubjectNode* currentSubject = currentStudent->subjects;
		while (currentSubject != nullptr)
		{
			outputFile << currentSubject->subjectName << "," << currentSubject->score << "," << currentSubject->creditHours << "," <<currentSubject->letterGrade << std::endl;
			currentSubject = currentSubject->next;
		}

		outputFile << std::endl; // Add empty line between students

		currentStudent = currentStudent->next;
	}

	outputFile.close();
	std::cout << "Data saved to file: " << filename << std::endl;
}

/**
 * loadDataFromFile - load data from a file
 * @filename: the filename to load from 
 * @head: head of the student structure
 *
 * Return: Nothing
 */

void loadDataFromFile(const std::string& filename, StudentNode*& head)
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		clearTerminal();
		std::cout << "Error opening file for reading: " << filename << std::endl;
		return;
	}

	// Clear existing student data
	cleanMemory(head);
	head = nullptr;
	std::string line;
	std::string studentName;
	bool isNewStudent = true;

	while (std::getline(inputFile, line))
	{
		if (line.empty())
		{
			isNewStudent = true;
			continue;
		}

		if (isNewStudent)
		{
			studentName = line;
			insertStudent(head, studentName);
			isNewStudent = false;
		}
		else
		{
			std::istringstream iss(line);
			std::string subjectName;
			double score;
			int creditHours;
			if (std::getline(iss, subjectName, ',') &&
			    (iss >> score) &&
			    (iss.ignore(), iss >> creditHours))
			{
				std::string letterGrade = calcLetterGrade(score);
				double gradePoint = calcGradePt(letterGrade);
				insertSubject(findStudent(head, studentName)->subjects, score, creditHours, gradePoint, subjectName, letterGrade);
			}
		}
	}

	inputFile.close();
	clearTerminal();
	std::cout << "Data loaded from file: " << filename << std::endl;
}

/**
 * loadData - load students data from a file
 * @head: head for student linked list
 * 
 * Return: Nothing
 */

void loadData(StudentNode*& head)
{
	std::string filename;
	std::cout << "Enter filename to load data: ";
	std::cin >> filename;
	loadDataFromFile(filename, head);
}
