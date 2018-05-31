#ifndef DATAIODEF
#define DATAIODEF

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Exception.hpp"

template <typename T>
class File
{
private:
    T mData;
    int mRows;
    int mCols;
public:
    // File(const File<T>& otherFile);

    File(const std::string& fileName);

	void WriteFile(const std::string& fileName);

    // make a decorator for it to be verbose

    void dim();
    // void len();

    void head(size_t H=5);
    // void tail(size_t i);

    // void nth(size_t i);
    // void last(size_t i);

    // overload selection operator
    // select column
    // specify categories (enum)

    

};

// Overwritten copy constructor
// Allocate memory for new matrix, and copy entries into this matrix
// template <typename T>
// File<T>::File(const File<T>& otherFile) {
// 	mData = otherFile.mData;
// 	mRows = otherFile.mRows;
// 	mCols = otherFile.mCols;

// 	// for (int i=0; i<mNumRows*mNumCols; i++) {
// 	//    mData.push_back(otherMatrix.mData[i]);
// 	// }
// }

// Constructor for File from a given filepath
// Allocates memory, and initialises entries to zero
template <typename T>
File<T>::File(const std::string& fileName) {

	// Read data from filename to Table in an exception safely manner ////////////////////////////
	// try {
	// 	ReadFile(filename, Table);
	// }
	// catch (Exception& error) {
	// 	error.PrintDebug();
	// 	std::cout << "Couldn't open the file\n";
	// 	std::cout << "Give alternative location\n";
	// 	std::cin >> filename;
	// 	ReadFile(filename, Table);
	// }


    // Prepare to read file
	std::ifstream file(fileName.c_str());

	if (file.is_open() == false) {
		throw (Exception("FILE", "File can't be opened"));
	}

	size_t size = 0; // Length of the row - to be computed below
	std::string str;
	getline(file, str, '\n'); 
	size = std::count(str.begin(), str.end(), ',') + 1;

	// Add to private
	mRows = size;

	// Declare vector num to collect the numeric and categoric data
	std::vector<long int> row(size);

	// Place first line in the tuple
	std::stringstream ss(str);
	for (int i = 0; i < size; ++i) {
		getline(ss, str, ',');
		row[i] = stoi(str);
	}

	mData.push_back(row); // add first tuple to the mData

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

		mData.push_back(row);
	}

	file.close();
	std::cout << "File read successfully\n";
}

// Method to write to file
template <typename T>
void File<T>::WriteFile(const std::string& fileName) {
	// Write the mData to file .csv (BINARY)
	std::cout << "Writing the mData to file..." << std::endl;

	std::ofstream ofile("output.csv", std::ios::binary);
	assert(ofile.is_open());

	size_t nCols = mData[0].size();

	// write numeric bitmap
	for (int n = 0; n < mData.size(); ++n) {
		for (auto i = 0; i < nCols - 1; ++i) {
			ofile.write(reinterpret_cast<char*>(&mData[n][i]), sizeof(long int));
		}
		ofile.write(reinterpret_cast<char*>(&mData[n][nCols - 1]), sizeof(long int));
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

// Method to get dimensions of the object
template <typename T>
void File<T>::dim() {
    std::cout << "Dimensions: " << mRows << "\t" << mData.size() << std::endl;;
}

// Method to get number of rows of matrix
template <typename T>
void File<T>::head(size_t H) {
    std::cout << "First " << H << " rows:" << std::endl;
	for (auto i = 0; i < H; ++i) {
		for (auto el : mData[i]) 
			std::cout << el << '\t';
		std::cout << std::endl;
	}
}



#endif //DATAIODEF