// (Printing) Write a program that prints the numbers 1 to 6 with two numbers
// in one line separated by a tab. Do this several ways:

#include <iostream>

using namespace std;

int main() {

	// a) 1 statement; 1 stream insertion operator
	cout << "1\t2\n3\t4\n5\t6\n\n";
	// b) 1 statement; 6 stream insertion operators
	cout << "1\t" << "2\n" << "3\t" << "4\n" << "5\t" << "6\n\n";
	// c) 6 statements
	cout << "1\t";
	cout << "2\n";
	cout << "3\t";
	cout << "4\n";
	cout << "5\t";
	cout << "6\n\n";
	return 0;
}
