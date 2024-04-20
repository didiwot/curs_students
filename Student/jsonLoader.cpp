

#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "./Student/Student.h"
#include <string>

using json = nlohmann::json;

class jsonLoader : private Student {
private:
	std::string jsonFile = "../../../database/database.json";

public:
	jsonLoader() {};

	void writeStudentDataToJsonFile(const std::vector<Student>& students) {
		json j = students;

		std::ofstream file(jsonFile);
		if (file.is_open())
		{
			file << j.dump(4);
		}
		else
		{
			std::cerr << "Unable to open file for writing." << std::endl;
		}
	}

	std::vector<Student> readStudentDataFromJsonFile() {
		std::vector<Student> students;

		std::ifstream file(jsonFile);
		if (file.is_open()) {
			json j;
			file >> j;
			j.get_to(students);
			
		}
		else {
			std::cerr << "Unable to open file for reading." << std::endl;
		}

		return students;

	}

};

