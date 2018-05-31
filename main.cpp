#include <iostream>
#include <chrono>
#include <vector>
#include <string>

#include <cassert>
#include <fstream>

// #include "ReadFile.hpp"
// #include "WriteFile.hpp"
// #include "Meta.hpp"
#include "iodata.hpp"

using namespace std;

int main()
{
    // Start clock
	auto start = chrono::high_resolution_clock::now();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// string filename = "/home/sandu/bmetric/C++ Projects/NoSessions/sessions.csv";
	string filename = "../covtype.data";

	// vector<vector<long int>> Table; // future destination Table
	
	File <vector<vector<long int>>> Table(filename);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Display the first few observations
	Table.head();

	// Display dimensions of the object (could be multidimensional)
	Table.dim();

	//------------------------------------------------------------------------------------------------

	// Write to file
	Table.WriteFile("output.csv");


    // Stop clock 
	auto end = chrono::high_resolution_clock::now();
	cout << "Computation time: " << chrono::duration<double, milli>(end - start).count() << "ms\n";
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return 0;
}