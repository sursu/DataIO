#include <iostream>
#include <chrono>
#include <vector>
#include <string>

#include <cassert>
#include <fstream>

#include "ReadFile.hpp"

using namespace std;

int main()
{
    // Start clock
	auto start = std::chrono::high_resolution_clock::now();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// string filename = "/home/sandu/bmetric/C++ Projects/NoSessions/sessions.csv";
	string filename = "../covtype.data";

	vector<vector<long int>> Table; // future destination Table


	// Read data from filename to Table in an exception safely manner ////////////////////////////
	try {
		ReadFile(filename, Table);
	}
	catch (Exception& error) {
		error.PrintDebug();
		std::cout << "Couldn't open the file\n";
		std::cout << "Give alternative location\n";
		std::cin >> filename;
		ReadFile(filename, Table);
	}

	cout << "Number of rows: " << Table.size() << "\n\nFirst few rows:\n";
	for (auto i = 0; i < 10; ++i) {
		for (auto el : Table[i]) 
			cout << el << '\t';
		cout << endl;
	}

	cout << "Check" << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Iterate over visitors and check how many unique sessions have they had in the past 30 days (2592000s)
	for (auto i = 0; i < Table.size(); ++i) {
		unsigned n = 1;
		long int last = Table[i][2];
		for (auto j = i; (Table[j][0] == Table[i][0]) && (Table[j][1] > Table[i][1] - 2592000) && (j > 0); --j) {
			long int session = Table[j][2];
			if (session != last) {
				n += 1;
				last = session;
			}
		}
		Table[i].push_back(n);
	} 


	cout << "\n\nFirst 100 rows with counted sessions\n" << endl;

	for (auto i = 0; i < 100; ++i) {
		for (auto el : Table[i])
			cout << el << '\t';
		cout << endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	//------------------------------------------------------------------------------------------------

	// Write the table to file .csv (BINARY)
	cout << "Writing the table to file..." << endl;

	ofstream ofile("output.csv", std::ios::binary);
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

    cout << "Operation completed successfully!\n" << endl;
	//------------------------------------------------------------------------------------------------

    // Stop clock 
	auto end = std::chrono::high_resolution_clock::now();
	cout << "Computation time: " << std::chrono::duration<double, milli>(end - start).count() << "ms\n";
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return 0;
}