#include "main.h"

/**
 * insertSubject - insert subject record for a student.
 * @head: head of subjects list/
 * @score: score for a paricular subject
 * @creditHours: credit hours for a subject.
 * @gradePont: grade point of a subject based on sccore.
 * @subjectName: subject name
 *
 * Return: nothing
 */

void insertSubject(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName, const std::string& letterGrade)
{
	SubjectNode* newNode = new SubjectNode(subjectName, score, creditHours, gradePoint, letterGrade);

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

void addSubjectInfo(StudentNode* currentStudent)
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
		insertSubject(currentStudent->subjects, currentSubject->score, currentSubject->creditHours, currentSubject->gradePoint, currentSubject->subjectName, currentSubject->letterGrade);
		currentSubject = currentSubject->next;
	}

	// Free the memory of the temporary subject list
	cleanupSubjects(head2);
	clearTerminal();
	std::cout << "Subject info added successfully for " << currentStudent->studentName << "!\n";
}


/**
 * dusplaySubjects - display subject records for a student.
 * @student: a node of a particular in students list
 *
 * Return: nothing
 */

void displaySubjects(StudentNode* student)
{
	if (student->subjects == nullptr)
	{
		clearTerminal();
		std::cout << "No subjects found for " << student->studentName << std::endl;
		return;
	}

	clearTerminal();

	std::cout << "                   █▄█ █▀▀ ▄▀█ █▄▄   █▀▀ █▀▀ █▀█ ▄▀█\n";
	std::cout << "                   ░█░ ██▄ █▀█ █▄█   █▄▄ █▄█ █▀▀ █▀█\n";
	std::cout << "\nSubjects and Grades for " << student->studentName << ":\n";

	// Table header
    std::cout << "╔═══════════════════════════╦═════════════════════╦═════════════╗\n";
    std::cout << "║ Subject                   ║ Marks               ║ Grade       ║\n";
    std::cout << "╠═══════════════════════════╬═════════════════════╬═════════════╣\n";

    SubjectNode* current = student->subjects;
    while (current != nullptr)
    {
	    std::cout << "║ " << std::setw(26) << std::left << current->subjectName
		      << "║ " << std::setw(20) << std::left << current->score
		      << "║ " << std::setw(12) << std::left << current->letterGrade << "║\n";
	    current = current->next;
    }

    // Table footer
    std::cout << "╚═══════════════════════════╩═════════════════════╩═════════════╝\n";
    double cgpa = calculateCGPA(student);
    std::cout << "\nCGPA for " << student->studentName << ": " << cgpa << std::endl;
    waitForEnterKey();
    clearTerminal();
}


/**
 * inputSubjectDetails - collect info on subjects for a particular student.
 * @numSubjects: number of subjects for a particular student
 * @subjectNames: a vector of subject names based on number of subjects
 * @creditHours: credit hours for each subject 
 *
 * Return: Nothing
 */

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
	clearTerminal();
	subjectNames.resize(numSubjects);
	creditHours.resize(numSubjects);

	for (int i = 0; i < numSubjects; i++)
	{
		std::cout << "Enter subject name for subject " << i + 1 << ": ";
		std::cin.ignore();
		std::getline(std::cin, subjectNames[i]);

		std::cout << "Enter credit hours for subject " << subjectNames[i] << ": ";
		std::cin >> creditHours[i];
		clearTerminal();


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
