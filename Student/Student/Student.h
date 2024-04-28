
#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

class Student{
    friend class jsonLoader;

    bool is_char(std::string);

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
    
    Student addInfoOneStudent();
    void addInfo(int index, std::vector<Student> students);
    void editStudents(int index, std::vector<Student> &students);
    void addStudent(std::vector<Student> &students);
    void deleteStudent(int index, std::vector<Student> &students);
    void showMenu();
    void printStudents(std::vector<Student> students);
    
    void addGrades(std::vector<std::pair<std::string, int>> sessionGrades);

    bool dataInTxt(std::vector<Student> students);
    std::string dataOutTxt();
    

    
};