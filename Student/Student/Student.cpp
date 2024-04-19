
#include "Student.h"

Student::Student(std::string name, std::string dob, int year, std::string fac, std::string dept, std::string grp, std::string id, std::string gen)
    : fullName(std::move(name)), dateOfBirth(std::move(dob)), enrollmentYear(year), faculty(std::move(fac)), department(std::move(dept)), group(std::move(grp)), studentID(std::move(id)), gender(std::move(gen)) {}

void Student::addGrades(std::vector<std::pair<std::string, int>> sessionGrades) {
    grades.push_back(sessionGrades);
}


