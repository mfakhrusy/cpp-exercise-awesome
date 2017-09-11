#include <iostream>

using namespace std;

typedef struct{
	int x;
	int y;
}Point;

int main() {

	Point A;
	A.x = 0;
	A.y = 5;

	if (A.x == 0 || A.y == 0) {
		cout << "Kuadran tidak bisa dihitung." << endl;
	} else {
		if (A.x > 0 && A.y > 0) {
			cout << "Kuadran 1" << endl;
		} else if 
	}

	return 0;
}
