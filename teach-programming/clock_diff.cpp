#include <iostream>

using namespace std;

struct data_waktu{

	int jam;
	int menit;
	int detik;
	int total;

};
int main(){

	data_waktu A;
	data_waktu B;

	A.jam = 3;
	A.menit = 40;
	A.detik = 50;

	B.jam = 10;
	B.menit = 1;
	B.detik = 50;


	cout << A.jam << " Jam, " << A.menit << " Menit, " << A.detik << " Detik." << endl;

	int a;
	return 0;
}
