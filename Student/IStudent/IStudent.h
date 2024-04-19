
#pragma once

#include "../Student/Student.h"

class IStudent {
protected:
	virtual ~IStudent() = default;

public:
	virtual Student addInfoOneStudent() = 0;
	virtual void addInfo(int index, std::vector<Student> students) = 0;
	virtual void editStudents(int index, std::vector<Student> students) = 0;
	virtual void addStudent(std::vector<Student> students) = 0;
	virtual void deleteStudent(int index, std::vector<Student> students) = 0;
	virtual void showMenu() = 0;
	virtual void printStudents(std::vector<Student> students) = 0;

	IStudent& operator=(const IStudent&) = delete;

};