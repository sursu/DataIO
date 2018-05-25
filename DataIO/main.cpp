#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	auto start = chrono::high_resolution_clock::now();

	cout << "Let's get started!" << endl;

	auto end = chrono::high_resolution_clock::now();
	cout << chrono::duration<double, milli>(end - start).count() << " ms"<< endl;

	system("pause");
	return 0;
}