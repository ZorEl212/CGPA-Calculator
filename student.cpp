#include "main.h"

/**
 * insertStudents - Insert a new student to the list
 * @head: head of the student linked list.
 * @studentName: Student name to insert
 *
 * Return: Nothing
 */

void insertStudent(StudentNode*& head, const std::string& studentName)
{
	// Check if student with the same name already exists
	if (findStudent(head, studentName) != nullptr)
	{
		clearTerminal();
		std::cout << "Student '" << studentName << "' already exists!\n";
		return;
	}
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
	}
}

StudentNode* findStudent(StudentNode* head, const std::string& studentName)
{
	StudentNode* current = head;
	while (current != nullptr)
	{
		if (current->studentName == studentName)
		{
			return (current);
		}
		current = current->next;
	}
	return (nullptr); // Student not found
}

/**
 * inputStudentDetails - take student name
 * @studentName: Name of the student
 *
 * Return: nothing
 */

void inputStudentDetails(std::string& studentName)
{
	std::cout << "Enter student name: ";
	std::cin.ignore();
	std::getline(std::cin, studentName);
}

/**
 * inputScore - collect score information for a subject
 * @head: head head for subject linked list
 * @subjectNames: subjects vector for subjects.
 * @creditHours: credit hour vector for subject's cr.
 *
 * Return: nothing
 */

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

		std::string letterGrade = calcLetterGrade(score);
		gradePoint = calcGradePt(letterGrade);
		insertNode(head, score, creditHours[i], letterGrade, gradePoint, subjectNames[i]);
	}
}


/**
 * deleteStudent - delete existing student from the linked list
 * @head: head of student list
 * @studentName: name of the student to delete.
 *
 * Return: modified head of student head
 */

StudentNode* delStud(StudentNode* head, const std::string& studentName)
{
	if (head == nullptr)
	{
		clearTerminal();
		std::cout << "No students found.\n";
		return (nullptr);
	}

	if (head->studentName == studentName)
	{
		StudentNode* temp = head;
		head = head->next;
		cleanupSubjects(temp->subjects); // Delete subjects separately
		delete temp;
		clearTerminal();
		std::cout << "Student '" << studentName << "' deleted.\n";
		return (head);
    }

	StudentNode* current = head->next;
	StudentNode* prev = head;

	while (current != nullptr)
	{
		if (current->studentName == studentName)
		{
			prev->next = current->next;
			cleanupSubjects(current->subjects); // Delete subjects separately
			delete current;
			std::cout << "Student '" << studentName << "' deleted.\n";
			return (head);
        }
		prev = current;
		current = current->next;
	}

	clearTerminal();
	std::cout << "Student '" << studentName << "' not found.\n";
	return (head);
}

/**
 * calcLetterGrade - calculate grade in letters according to a given score.
 * @score: recorded score for a given subject.
 *
 * Return: calculated Grade value A- F
 */

std::string calcLetterGrade(double score)
{
	const double scoreThresholds[] = {85, 80, 75, 70, 65, 60, 50, 45, 40};
	const std::string letterGrades[] = {"A", "A-", "B+", "B", "B-", "C+", "C-", "D+", "F"};
	const int numGrades = sizeof(scoreThresholds) / sizeof(scoreThresholds[0]);

	for (int i = 0; i < numGrades; ++i)
	{
		if (score >= scoreThresholds[i])
			return letterGrades[i];
	}

	return "F";
}

/**
 * calcGradePt - calculate grade point according to evaluated grade.
 * @letterGrade: evaluated grade for a subject
 *
 * Return: calculated grade point
 */

double calcGradePt(const std::string& letterGrade)
{
	const std::string letterGrades[] = {
		"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    const double gradePoints[] = {
	    4.0, 3.75, 3.5, 3.0, 2.75, 2.5, 2.0, 1.75, 1.0, 0.0
    };

    for (int i = 0; i < sizeof(letterGrades) / sizeof(letterGrades[0]); ++i)
    {
	    if (letterGrade == letterGrades[i])
        {
		return gradePoints[i];
        }
    }

    return 0.0;
}

void listAllStudents(StudentNode* head)
{
	clearTerminal();

	if (head == nullptr)
    {
	    std::cout << "No students found." << std::endl;
	    return;
    }

	std::cout << "Available Students:" << std::endl;
	StudentNode* current = head;
	while (current != nullptr)
	{
        std::cout << " - " << current->studentName << "\n" << std::endl;
        current = current->next;
	}

	waitForEnterKey();
}
