

#pragma once

#include "../Student/Student.h"
#include <vector>
#include <iostream>

class IStudent {
private:
	std::vector<Student> students;

public:
	IStudent(const std::vector<Student>& students) : students(students) {}

	void addInfo(int index);
	void editStudents(int index);
	void addStudent();
	void deleteStudent(int index);
	void showMenu();
	void printStudents();

};