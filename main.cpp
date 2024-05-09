// curs_students.cpp : Defines the entry point for the application.
//

#include "./Student/Student/Student.h"
#include "./Student/jsonLoader.cpp"
#include "./Student/Crypto/Crypto.h"

using namespace std;

int main()
{
	Student student1("John Doe", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS101", "123456", "Male");
	std::vector<std::pair<std::string, int>> session1 = { {"Math", 90}, {"Physics", 85}, {"English", 88} };
	Student student2("Peggy Nelson", "05/10/1999", 2020, "Information Security", "Software Engineering", "IS191", "152132", "Male");
	std::vector<std::pair<std::string, int>> session2 = { {"Math", 94}, {"Physics", 46}, {"English", 79} };
	Student student3("Paula Washington", "05/05/1998", 2020, "Information Security", "Software Engineering", "IS202", "533456", "Female");
	std::vector<std::pair<std::string, int>> session3 = { {"Math", 78}, {"Physics", 97}, {"English", 55} };
	Student student4("Rita Thomas", "06/10/2000", 2020, "Computer Science", "Software Engineering", "CS101", "295738", "Male");
	std::vector<std::pair<std::string, int>> session4 = { {"Math", 59}, {"Physics", 80}, {"English", 88} };
	Student student5("Kathy Baker", "28/05/2001", 2020, "Computer Science", "Software Engineering", "CS101", "877589", "Male");
	std::vector<std::pair<std::string, int>> session5 = { {"Math", 72}, {"Physics", 40}, {"English", 74} };
	Student student6("John Doe", "01/01/2000", 2020, "Computer Science", "Software Engineering", "CS202", "123456", "Male");
	std::vector<std::pair<std::string, int>> session6 = { {"Math", 92}, {"Physics", 84}, {"English", 94} };
	Student student7("Peggy Nelson", "05/10/1999", 2020, "Computer Science", "Software Engineering", "CS101", "152132", "Male");
	std::vector<std::pair<std::string, int>> session7 = { {"Math", 77}, {"Physics", 40}, {"English", 56} };

	student1.addGrades(session1);
	student2.addGrades(session2);
	student3.addGrades(session3);
	student4.addGrades(session4);
	student5.addGrades(session5);
	student6.addGrades(session6);
	student7.addGrades(session7);

	vector<Student> students;
	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);
	students.push_back(student4);
	students.push_back(student5);
	students.push_back(student6);
	students.push_back(student7);



	//vector<Student> students; //создание векторов студентов
	std::string textToEncrypt; //текст для шифрования



	jsonLoader loader; //создание объекта jsonLoader который будет использоваться для работы с файлом json (нашей database)
	
	loader.writeStudentDataToJsonFile(students); //записать в файл

	students = loader.readStudentDataFromJsonFile(); //читать из файла

	

	Student* interfaceStudents = new Student();  //создание интерфейсного объекта

	Crypto* ICrypto = new Crypto(); //создание интерфейсного объекта

	//std::cout << interfaceStudents->dataOutTxt(students); //work
	//interfaceStudents->dataInTxt(); //work

	int choice = 0;
	do 
	{
		interfaceStudents->showMenu(); //вывести меню
		std::cin >> choice; //ввод выбора
		switch (choice) 
		{

		case 1: //edit work
			int index;
			std::cout << "Enter the index of the student to edit: ";
			std::cin >> index;
			if (index < 0 || index >= students.size()) { //проверка на валидность индекса
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
				break;
			}
			else
			{
				interfaceStudents->editStudents(index, students); //вызов функции редактирования
				loader.writeStudentDataToJsonFile(students); //запись в файл
				break;
			}

		case 2: //add work
			interfaceStudents->addStudent(students); //вызов функции добавления
			loader.writeStudentDataToJsonFile(students); //запись в файл
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

		case 5://encrypt work 
			interfaceStudents->dataOutTxt(students);
			ICrypto->Encrypt(interfaceStudents->dataInTxt()); //вызов функции шифрования
			break;

		case 6://decrypt work 
			ICrypto->Decrypt(); //вызов функции дешифрования
			break;


		case 7:
			std::cout << "Exiting the program. Goodbye!" << std::endl;
			return 0;
			break;


		default:
			std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
			break;
		}

	} while (choice != 7);

	delete interfaceStudents;
	delete ICrypto;

	return 0;

}
