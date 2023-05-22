#include "main.h"

void insertNode(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName)
{
	SubjectNode* newNode = new SubjectNode(subjectName, score, creditHours, gradePoint);
	if (newNode == nullptr)
	{
		freeSubject(newNode);
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

void cleanupMemory(StudentNode* head)
{
	StudentNode* currentStudent = head;
	while (currentStudent != nullptr)
	{
		SubjectNode* currentSubject = currentStudent->subjects;
		while (currentSubject != nullptr)
		{
			SubjectNode* nextSubject = currentSubject->next;
			delete currentSubject;
			currentSubject = nextSubject;
		}
		StudentNode* nextStudent = currentStudent->next;
		delete currentStudent;
		currentStudent = nextStudent;
	}
}

void freeSubject(SubjectNode* head)
{
	while (head != nullptr)
            {
                SubjectNode* temp = head;
                head = head->next;
                delete temp;
            }
}
