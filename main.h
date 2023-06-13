#ifndef MAIN_H
#define MAIN_H

/******** Library Inclusions ************/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

/**
 * SubjectNode - linked list struct for subjects
 * @score: score for a subject
 * @creditHours: credit hours for a subject
 * @gradePoint: grade point for a subject
 * @subjectName: name of the subject
 * @next: address for the next subject node
 */

struct SubjectNode
{
	double score;
	int creditHours;
	double gradePoint;
	std::string subjectName;
	std::string letterGrade;
	SubjectNode* next;

	SubjectNode(const std::string& name, double s, int ch, double gp, const std::string& lg) : subjectName(name), score(s), creditHours(ch), gradePoint(gp), letterGrade(lg), next(nullptr) {}
};

/**
 * StudentNode - linked list struct for Students
 * @studentName: Name of the student
 * @subjects: subjects for the student
 * @next: address for the next student
 */

struct StudentNode
{
	std::string studentName;
	SubjectNode* subjects;
	StudentNode* next;

	StudentNode(const std::string& _studentName)
		: studentName(_studentName), subjects(nullptr), next(nullptr) {}
};

/************ Function Prototypes ******************/

void insertStudent(StudentNode*& head, const std::string& studentName);
StudentNode* delStud(StudentNode* head, const std::string& studentName);
void listAllStudents(StudentNode* head);
void inputStudentDetails(std::string& studentName);
void insertNode(SubjectNode*& head, double score, int creditHours, const std::string& letterGrade, double gradePoint, const std::string& subjectName);
void inputScores(SubjectNode*& head, const std::vector<std::string>& subjectNames, const std::vector<int>& creditHours);
void insertSubject(SubjectNode*& head, double score, int creditHours, double gradePoint, const std::string& subjectName, const std::string& letterGrade);
void displaySubjects(StudentNode* student);
void inputSubjectDetails(int& numSubjects, std::vector<std::string>& subjectNames, std::vector<int>& creditHours);
void cleanMemory(StudentNode* head);
double calculateGPA(StudentNode* student);
void cleanupSubjects(SubjectNode* head);
void clearTerminal();
StudentNode* findStudent(StudentNode* head, const std::string& studentName);
void saveDataToFile(const std::string& filename, StudentNode* head);
void loadDataFromFile(const std::string& filename, StudentNode*& head);
void clearStudents(StudentNode*& head);
void loadData(StudentNode*& head);
double calcGradePt(const std::string& letterGrade);
std::string calcLetterGrade(double score);
void addSubjectInfo(StudentNode* currentStudent);
void waitForEnterKey();

#endif
