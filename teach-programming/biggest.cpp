#include <iostream>

using namespace std;

int main() {

	int a = 1;
	int b = 2;
	int c = 9;

	//biggest
	if (a > b) {
		if (a > c) {
			cout << "Biggest is: " << a << endl;
			if (b > c) {
				cout << "Urutan terbesar ke terkecil: " << a << "," << b << "," << c << endl;
			} else {
				cout << "Urutan terbesar ke terkecil: " << a << "," << c << "," << b << endl;
			}
		} else {
			cout << "Biggest is: " << c << endl;
			if (b > a) {
				cout << "Urutan terbesar ke terkecil: " << c << "," << b << "," << a << endl;
			} else {
				cout << "Urutan terbesar ke terkecil: " << c << "," << a << "," << b << endl;
			}
		}
	} else {
		if (b > c) {
			cout << "Biggest is: " << b << endl;
			if (c > a) {
				cout << "Urutan terbesar ke terkecil: " << b << "," << c << "," << a << endl;
			} else {
				cout << "Urutan terbesar ke terkecil: " << b << "," << a << "," << c << endl;
			}
		} else {
			cout << "Biggest is: " << c << endl;
			if (c > b) {
				cout << "Urutan terbesar ke terkecil: " << a << "," << c << "," << b << endl;
			} else {
				cout << "Urutan terbesar ke terkecil: " << a << "," << b << "," << c << endl;
			}
		}
	}
}
