#include <iostream>
#include <chrono>
#include <vector>
#include <string>

#include <cassert>
#include <fstream>

#include "ReadFile.hpp"
#include "WriteFile.hpp"
#include "Meta.hpp"

using namespace std;

int main()
{
    // Start clock
	auto start = chrono::high_resolution_clock::now();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	string filename = "/home/sandu/bmetric/C++ Projects/NoSessions/sessions.csv";
	// string filename = "../covtype.data";

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

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Display the first few observations
	head(Table);
	

	//------------------------------------------------------------------------------------------------

	WriteFile("output.csv", Table);


    // Stop clock 
	auto end = chrono::high_resolution_clock::now();
	cout << "Computation time: " << chrono::duration<double, milli>(end - start).count() << "ms\n";
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return 0;
}