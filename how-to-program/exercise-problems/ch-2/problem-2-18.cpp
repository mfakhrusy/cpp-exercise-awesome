// (Comparing Integers) Write a program that asks the user to enter two integers,
// obtains the numbers from the user, then prints the smaller number followed
// by the words "is smaller." If the numbers are equal, it prints the message
// "These numbers are equal."

#include <iostream>

using namespace std;

int main() {

	int num1, num2;

	cout << "Insert number 1: ";
	cin >> num1;
	cout << "Insert number 2: ";
	cin >> num2;

	if (num1 == num2) {
		cout << "These numbers are equal.";
	} else if (num1 > num2) {
		cout << num2 << " is smaller.";
	} else {
		cout << num1 << " is smaller.";
	}

	cout << endl;

	return 0;
}
