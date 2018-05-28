#include <iostream>
#include <vector>

#include "Meta.hpp"

void head(std::vector<std::vector<long int>> &Table)
{
    std::cout << "Number of rows: " << Table.size() << "\n\nFirst few rows:\n";
	for (auto i = 0; i < 10; ++i) {
		for (auto el : Table[i]) 
			std::cout << el << '\t';
		std::cout << std::endl;
	}
}