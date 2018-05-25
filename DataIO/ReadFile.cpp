#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "ReadFile.hpp"

void ReadFile(const std::string& fileName, const size_t sizeNum, std::vector<Tuple> &Table) {
	
	// Prepare to read file
	std::ifstream file(fileName.c_str());

	if (file.is_open() == false) {
		throw (Exception("FILE", "File can't be opened"));
	}

	size_t size = 0; // Length of the tuple - to be computed below
	std::string str;
	getline(file, str, '\n'); 
	size = std::count(str.begin(), str.end(), ',')+1;
	
	size_t sizeCat = size - sizeNum;

	// Declare vectors num & cat to collect the numeric and categoric data
	std::vector<double> num(sizeNum);
	std::vector<int> cat(sizeCat);

	// Place first line in the tuple
	std::stringstream ss(str);
	for (int i = 0; i < sizeNum; ++i) {
		getline(ss, str, ',');
		num[i] = stod(str);
	}
	for (int i = 0; i < sizeCat - 1; ++i) {
		getline(ss, str, ',');
		cat[i] = stoi(str);
	}
	getline(ss, str, '\n'); // collect the last element
	cat.back() = stoi(str);

	Table.push_back(Tuple(num, cat)); // add first tuple to the Table

	// Actual reading
	while (true) {
		if (!getline(file, str, ',')) break;
			num[0] = stod(str);
		for (int i = 1; i < sizeNum; ++i) {
			getline(file, str, ',');
			num[i] = stod(str);
		}
		for (int i = 0; i < sizeCat-1; ++i) {
			getline(file, str, ',');
			cat[i] = stoi(str);
		}
		getline(file, str, '\n');
		cat.back() = stoi(str);

		Table.push_back(Tuple(num, cat));
	}

	file.close();
	std::cout << "File read successfully\n";
}