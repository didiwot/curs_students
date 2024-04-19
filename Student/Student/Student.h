
#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>
#include "../IStudent/IStudent.h"

class Student : public IStudent{
    friend class jsonLoader;

public:

    std::string fullName;
    std::string dateOfBirth;
    int enrollmentYear;
    std::string faculty;
    std::string department;
    std::string group;
    std::string studentID;
    std::string gender;
    std::vector<std::vector<std::pair<std::string, int>>> grades;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, fullName, dateOfBirth, enrollmentYear, faculty, department, group, studentID, gender, grades)
    
    Student() = default;
    Student(std::string fullName, std::string dateOfBirth, int enrollmentYear, std::string faculty, std::string department, std::string group, std::string studentID, std::string gender);
    
    Student addInfoOneStudent() override;
    void addInfo(int index, std::vector<Student> students) override;
    void editStudents(int index, std::vector<Student> students) override;
    void addStudent(std::vector<Student> students) override;
    void deleteStudent(int index, std::vector<Student> students) override;
    void showMenu() override;
    void printStudents(std::vector<Student> students) override;
    
    void addGrades(std::vector<std::pair<std::string, int>> sessionGrades);
    

    
};