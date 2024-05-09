
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

    //макрос для рабоы с json
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, fullName, dateOfBirth, enrollmentYear, faculty, department, group, studentID, gender, grades) 
    
    Student() = default;
    Student(std::string fullName, std::string dateOfBirth, int enrollmentYear, std::string faculty, std::string department, std::string group, std::string studentID, std::string gender);
    
    Student addInfoOneStudent(); //добавить информацию о студенте
    void addInfo(int index, std::vector<Student> students); //добавить информацию о студенте
    void editStudents(int index, std::vector<Student> &students); //изменить студента
    void addStudent(std::vector<Student>& students); //добавить студента
    void deleteStudent(int index, std::vector<Student> &students); //удалить студента
    void showMenu(); //показать меню
    void printStudents(std::vector<Student> students); //распечатать студента
    
    void addGrades(std::vector<std::pair<std::string, int>> sessionGrades); //добавить оценки

    bool dataOutTxt(std::vector<Student> students);
    std::string dataInTxt(); // можно добавить что-то типо path = "../../../database/" а потом просто path+currentPath
    

    
};