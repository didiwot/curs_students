
#include "Student.h"

Student::Student(std::string name, std::string dob, int year, std::string fac, std::string dept, std::string grp, std::string id, std::string gen)
    : fullName(std::move(name)), dateOfBirth(std::move(dob)), enrollmentYear(year), faculty(std::move(fac)), department(std::move(dept)), group(std::move(grp)), studentID(std::move(id)), gender(std::move(gen)) {}

void Student::addGrades(std::vector<std::pair<std::string, int>> sessionGrades) {
    grades.push_back(sessionGrades);
}

bool Student::is_char(std::string s) {
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z'){ return true; }
        else { return false; }
    }
 
}


void Student::addInfo(int index, std::vector<Student> students)
{
    std::vector<std::pair<std::string, int>> sessionGrades;
    std::string newNameSubjectOfStudy;
    int newGradeSubjectOfStudy;
    int CountSessions;
    int CountSubjectOfStudy;
    std::string tmp;

    std::cout << "enter new full name in format: Name; press ""Enter""; Surname" << std::endl;
    std::cin >> tmp;
    students[index].fullName = tmp;
    std::cin >> tmp;
    students[index].fullName += " " + tmp;
    std::cout << "enter new date of birthday, format dd/mm/yyyy" << std::endl;
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

Student Student::addInfoOneStudent() {
    std::vector<std::pair<std::string, int>> sessionGrades;
    std::string newNameSubjectOfStudy;
    int newGradeSubjectOfStudy;
    int CountSessions;
    int CountSubjectOfStudy;
    Student student;
    std::string tmp;

    std::cout << "enter new full name in format: Name; press ""Enter""; Surname" << std::endl;
    std::cin >> tmp;
    student.fullName = tmp;
    std::cin >> tmp;
	student.fullName += " " + tmp;
    std::cout << "enter new date if birthday, format dd/mm/yyyy" << std::endl;
    std::cin >> student.dateOfBirth;
    std::cout << "enter new enrollment year" << std::endl;
    std::cin >> student.enrollmentYear;
    std::cout << "enter new faculty" << std::endl;
    std::cin >> student.faculty;
    std::cout << "enter new department" << std::endl;
    std::cin >> student.department;
    std::cout << "enter new group" << std::endl;
    std::cin >> student.group;
    std::cout << "enter new studentID" << std::endl;
    std::cin >> student.studentID;
    std::cout << "enter new gender" << std::endl;
    std::cin >> student.gender;
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
    student.addGrades(sessionGrades);

    return student;
}

void Student::editStudents(int index, std::vector<Student> &students) {
    addInfo(index, students);
    std::cout << "Edit Student complete!" << std::endl;

}

void Student::addStudent(std::vector<Student> &students)
{
    students.push_back(addInfoOneStudent());
    std::cout << "add Student complete!" << std::endl;
}

void Student::deleteStudent(int index, std::vector<Student> &students)
{
    students.erase(students.begin() + index);
    std::cout << "Delete Student complete!" << std::endl;
}

void Student::showMenu()
{
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Edit Student" << std::endl;
    std::cout << "2. Add Student" << std::endl;
    std::cout << "3. Delete Student" << std::endl;
    std::cout << "4. Print Students" << std::endl;
    std::cout << "5. Encrypt" << std::endl;
	std::cout << "6. Decrypt" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

void Student::printStudents(std::vector<Student> students)
{
    for (int i = 0; i < students.size(); i++) {
        std::cout << "Name: " << students[i].fullName << std::endl;
        std::cout << "Date of birthday: " << students[i].dateOfBirth << std::endl;
        std::cout << "Enrollment year: " << students[i].enrollmentYear << std::endl;
        std::cout << "Faculty: " << students[i].faculty << std::endl;
        std::cout << "Department: " << students[i].department << std::endl;
        std::cout << "Group: " << students[i].group << std::endl;
        std::cout << "StudentID: " << students[i].studentID << std::endl;
        std::cout << "Gender: " << students[i].gender << std::endl;

        std::cout << "Grades:" << std::endl;
        for (int j = 0; j < students[i].grades.size(); j++)
        {
            for (auto grade : students[i].grades[j])
                std::cout << "Subject name: " << grade.first << "  Grade: " << grade.second << std::endl;

        }
        std::cout << std::endl << "--------------------------" << std::endl;
    }
}

bool Student::dataOutTxt(std::vector<Student> students) {
    std::ofstream file("../../../database/database.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }

    for (int i = 0; i < students.size(); i++) {
        file << students[i].fullName << " ";
        file << students[i].dateOfBirth << " ";
        file << students[i].enrollmentYear << " ";
        file << students[i].faculty << " ";
        file << students[i].department << " ";
        file << students[i].group << " ";
        file << students[i].studentID << " ";
        file << students[i].gender << " ";

        for (int j = 0; j < students[i].grades.size(); j++)
        {
            for (auto grade : students[i].grades[j])
                file << "Subject name: " << grade.first << "  Grade: " << grade.second << " ";
        }
        file << std::endl;
        }

    return true;
}


std::string Student::dataInTxt() {
    std::string text;

    std::ifstream in("../../../database/database.txt");
    

    if (in.is_open())
    {
        in.seekg(0, std::ios::end);
        text.reserve(in.tellg());

        in.seekg(0, std::ios::beg);

        for (std::string str; std::getline(in, str);)
        {
            text += str + "\n";
        }

        return text;
    }
    else
    {
        std::cout << "dataInFile error" << std::endl;
        return "error";
    }

}
