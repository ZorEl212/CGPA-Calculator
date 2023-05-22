#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>


struct SubjectNode
{
	double score;
	int creditHours;
	double gradePoint;
	std::string subjectName;
	SubjectNode* next;

	SubjectNode(const std::string& name, double s, int ch, double gp) : subjectName(name), score(s), creditHours(ch), gradePoint(gp), next(nullptr) {}
};

struct StudentNode
{
	std::string studentName;
	SubjectNode* subjects;
	StudentNode* next;
	
	StudentNode(const std::string& _studentName)
		: studentName(_studentName), subjects(nullptr), next(nullptr) {}
};




void insertStudent(StudentNode*& head, const std::string& studentName);
void inputStudentDetails(std::string& studentName);
void insertNode(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName);
void inputScores(SubjectNode*& head, const std::vector<std::string>& subjectNames, const std::vector<int>& creditHours);
void insertSubject(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName);
void displaySubjects(StudentNode* student);
void inputSubjectDetails(int& numSubjects, std::vector<std::string>& subjectNames, std::vector<int>& creditHours);
void cleanupMemory(StudentNode* head);
double calculateCGPA(StudentNode* student);
void printCGPA(const std::string& studentName, double cgpa);
void freeSubject(SubjectNode* head);


#endif
