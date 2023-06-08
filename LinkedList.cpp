#include "main.h"

/**
 * insertNode - insert a new node with collected information for a subject
 * @head: head of the subject linked list
 * @score: score for a particular subject
 * @creditHours: credit hours for a particular subject
 * @gradepoint: grade point calculated based on subject score
 * @subjectName: Name of the subject
 *
 * Return: Nothing
 */

void insertNode(SubjectNode*& head, double score, int creditHours, const std::string& letterGrade, double gradePoint, const std::string& subjectName)
{
	SubjectNode* newNode = new SubjectNode(subjectName, score, creditHours, gradePoint, letterGrade);
	if (newNode == nullptr)
	{
		//cleanupSubjects(newNode);
		return;
	}

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

/**
 * cleanMemory - clean the memory allocated for student Linked list.
 * @head: head of student Linked list
 *
 * Return: nothing
 */

void cleanMemory(StudentNode* head)
{
	while (head != nullptr)
	{
		StudentNode* temp = head;
		head = head->next;
		cleanupSubjects(temp->subjects); // Delete subjects separately
		delete temp;
	}
}

/**
 * cleanupSubjects - free memory allocated for Subjects linked list
 * @head: subjects Linked list head.
 *
 * Return: Nothing
 */

void cleanupSubjects(SubjectNode* head)
{
	SubjectNode* current = head;
	while (current != nullptr)
	{
		SubjectNode* next = current->next;
		delete current;
		current = next;
	}
}
