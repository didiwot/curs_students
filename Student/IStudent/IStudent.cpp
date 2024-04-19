
#include "IStudent.h"



void IStudent::addInfo(int index)
{
    std::vector<std::pair<std::string, int>> sessionGrades;
    std::string newNameSubjectOfStudy;
    int newGradeSubjectOfStudy;
    int CountSessions; 
    int CountSubjectOfStudy;
    std::cout << "enter new full name" << std::endl;
    std::cin >> students[index].fullName;
    std::cout << "enter new date if birthday, format dd/mm/yyyy" << std::endl;
    std::cin >> students[index].dateOfBirth;
    std::cout << "enter new enrollment year" << std::endl;
    std::cin >> students[index].enrollmentYear;
    std::cout << "enter new faculty" << std::endl;
    std::cin >> students[index].faculty;
    std::cout << "enter new department" << std::endl;
    std::cin >> students[index].department;
    std::cout << "enter new group" << std::endl;
    std::cin >> students[index].group;
    std::cout << "enter new studentID" << std::endl;
    std::cin >> students[index].studentID;
    std::cout << "enter new gender" << std::endl;
    std::cin >> students[index].gender;
    std::cout << "enter how many sessions you want to add" << std::endl;
    std::cin >> CountSessions;
    for (int i = 0; i < CountSessions; i++) {
        std::cout << "enter how many subjects you want to add in session # " << i + 1 << std::endl;
        std::cin >> CountSubjectOfStudy;
        for (int i = 0; i < CountSubjectOfStudy; i++)
        {
            std::cout << "enter new subject name" << std::endl;
            std::cin >> newNameSubjectOfStudy;
            std::cout << "enter new grade in this subject" << std::endl;
            std::cin >> newGradeSubjectOfStudy;
            sessionGrades.push_back({ newNameSubjectOfStudy, newGradeSubjectOfStudy });
        }
    }
    students[index].addGrades(sessionGrades);
}

void IStudent::editStudents(int index) {
    addInfo(index);
    std::cout << "Edit Student complete!" << std::endl;

}

void IStudent::addStudent()
{
	students.push_back(Student());
    addInfo(students.size() - 1);
    std::cout << "add Student complete!" << std::endl;
}

void IStudent::deleteStudent(int index)
{
    students.erase(students.begin() + index);
    std::cout << "Delete Student complete!" << std::endl;
}

void IStudent::showMenu()
{
        std::cout << "Menu Options:" << std::endl;
        std::cout << "1. Edit Student" << std::endl;
        std::cout << "2. Add Student" << std::endl;
        std::cout << "3. Delete Student" << std::endl;
        std::cout << "4. Print Students" << std::endl;
        std::cout << "5. Exit" << std::endl;
}

void IStudent::printStudents()
{
    for (int i = 0; i < students.size(); i++) {
        std::cout << "Name: " << students[i].fullName << std::endl;
        std::cout << "Date of birthday: " << students[i].dateOfBirth << std::endl;
        std::cout << "Enrollment year" << students[i].enrollmentYear <<std::endl;
        std::cout << "Faculty" << students[i].faculty <<std::endl;
        std::cout << "Department" << students[i].department << std::endl;
        std::cout << "Group" << students[i].group << std::endl;
        std::cout << "StudentID" << students[i].studentID << std::endl;
        std::cout << "Gender" << students[i].gender << std::endl;

        std::cout << "Grades:" << std::endl;
        for (int j = 0; j < students[i].grades.size(); j++)
        {
            for (auto grade : students[i].grades[j])
            std::cout << "Subject name: " << grade.first << "  Grade: " << grade.second << std::endl;
            
        }
        std::cout << std::endl << "--------------------------" << std::endl;
    }
}