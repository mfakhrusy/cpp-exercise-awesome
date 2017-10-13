#include <iostream>

using namespace std;

int main() {

	const int n = 7;
	int a[n] = {4,3,99,2,50,8,5};

	cout << "Before: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " "; 
	}
	cout << endl;


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (n - i); j++) {
			if (a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			
			}
		}
	}

	cout << "After : ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " "; 
	}
	cout << endl;

	return 0;
}
