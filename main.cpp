// curs_students.cpp : Defines the entry point for the application.
//

#include "./Student/Student/Student.h"
#include "./Student/jsonLoader.cpp"
#include "./Student/Crypto/Crypto.h"

using namespace std;

int main()
{
	/*Student student1("John Doe", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session1 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	Student student2("Peggy Nelson", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session2 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	Student student3("Paula Washington", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session3 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	Student student4("Rita Thomas", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session4 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	Student student5("Kathy Baker", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session5 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	student1.addGrades(session1);
	student2.addGrades(session2);
	student3.addGrades(session3);
	student4.addGrades(session4);
	student5.addGrades(session5);

	vector<Student> students;
	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);
	students.push_back(student4);
	students.push_back(student5);*/

	vector<Student> students;
	jsonLoader loader;
	std::string textToEncrypt;


	//loader.writeStudentDataToJsonFile(students); //записать в файл

	// тут должна быть расшифровка (создается объект типо crupto, он вызывает rsa туда желательно передать строку )

	students = loader.readStudentDataFromJsonFile(); //читать из файла
	

	Student* interfaceStudents = new Student();

	Crypto* ICrypto = new Crypto();

	//std::cout << interfaceStudents->dataOutTxt(students); //work
	//interfaceStudents->dataInTxt(); //work

	int choice = 0;
	do 
	{
		interfaceStudents->showMenu();
		std::cin >> choice;
		switch (choice)
		{

		case 1: //edit 
			int index;
			std::cout << "Enter the index of the student to edit: ";
			std::cin >> index;
			if (index < 0 || index >= students.size()) {
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
				break;
			}
			else
			{
				interfaceStudents->editStudents(index, students);
				loader.writeStudentDataToJsonFile(students);
				break;
			}

		case 2: //add work
			interfaceStudents->addStudent(students);
			loader.writeStudentDataToJsonFile(students);
			break;

		case 3: //delete work
			std::cout << "Enter the index of the student to delete: ";
			std::cin >> index;
			if (index < 0 || index >= students.size()) {
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
				break;
			} 
			else
			{
				interfaceStudents->deleteStudent(index, students);
				loader.writeStudentDataToJsonFile(students);
				break;
			}

		case 4: //print work
			interfaceStudents->printStudents(students);
			break;

		case 5://encrypt work ???
			interfaceStudents->dataOutTxt(students);
			ICrypto->Encrypt(interfaceStudents->dataInTxt());
			break;

		case 6://decrypt not work
			//ICrypto->Decrypt();
			break;

		case 7:
			std::cout << "Exiting the program. Goodbye!" << std::endl;
			break;


		default:
			std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
			break;
		}

	} while (choice != 7);

	delete interfaceStudents;

	return 0;

}
