#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "ReadFile.hpp"

void ReadFile(const std::string& fileName, std::vector<std::vector<long int>> &Table) {
	
	// Prepare to read file
	std::ifstream file(fileName.c_str());

	if (file.is_open() == false) {
		throw (Exception("FILE", "File can't be opened"));
	}

	size_t size = 0; // Length of the row - to be computed below
	std::string str;
	getline(file, str, '\n'); 
	size = std::count(str.begin(), str.end(), ',') + 1;
	
	// Declare vector num to collect the numeric and categoric data
	std::vector<long int> row(size);

	// Place first line in the tuple
	std::stringstream ss(str);
	for (int i = 0; i < size; ++i) {
		getline(ss, str, ',');
		row[i] = stoi(str);
	}

	Table.push_back(row); // add first tuple to the Table

	// Actual reading
	while (true) {
		if (!getline(file, str, ',')) break;
			row[0] = stoi(str);
		for (int i = 1; i < size-1; ++i) {
			getline(file, str, ',');
			row[i] = stoi(str);
		}
		getline(file, str, '\n');
		row.back() = stoi(str);

		Table.push_back(row);
	}

	file.close();
	std::cout << "File read successfully\n";
}