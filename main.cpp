#include <iostream>
#include <chrono>
#include <vector>

#include "ReadFile.hpp"

using namespace std;

int main()
{
    // Start clock
	auto start = std::chrono::high_resolution_clock::now();

    cout << "Let's get started!!" << endl;

    // Stop clock 
	auto end = std::chrono::high_resolution_clock::now();
	cout << "Computation time: " << std::chrono::duration<double, milli>(end - start).count() << "ms\n";

    // system("pause");
    return 0;
}