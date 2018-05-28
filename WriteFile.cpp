#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>

#include "WriteFile.hpp"

void WriteFile(const std::string& fileName, std::vector<std::vector<long int>> &Table)
{
    // Write the table to file .csv (BINARY)
	std::cout << "Writing the table to file..." << std::endl;

	std::ofstream ofile("output.csv", std::ios::binary);
	assert(ofile.is_open());

	size_t nCols = Table[0].size();

	// write numeric bitmap
	for (int n = 0; n < Table.size(); ++n) {
		for (auto i = 0; i < nCols - 1; ++i) {
			ofile.write(reinterpret_cast<char*>(&Table[n][i]), sizeof(long int));
		}
		ofile.write(reinterpret_cast<char*>(&Table[n][nCols - 1]), sizeof(long int));
	}

	ofile.flush();
	ofile.close();

    std::cout << "Operation completed successfully!\n" << std::endl;


	//------------------------------------------------------------------------------------------------
	//// Write the table to file .csv
	//cout << "Writing the table to file...\n";

	//ofstream ofile("sessions_numbered.csv");
	////assert(ofile.is_open());

	//size_t nCols = Table[0].size();

	//// write numeric bitmap
	//for (int n = 0; n < Table.size(); ++n) {
	//	for (auto i = 0; i < nCols-1; ++i) {
	//		ofile << Table[n][i] << ",";
	//	}
	//	ofile << Table[n][nCols-1] << "\n";
	//}

	//ofile.flush();
	//ofile.close();
}