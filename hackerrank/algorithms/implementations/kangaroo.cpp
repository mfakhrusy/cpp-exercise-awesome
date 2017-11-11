#include <iostream>

// switch function
void switchValue(int &x1, int &x2);
int main() {

	// input data from user
	int xKangaroo1, vKangaroo1, xKangaroo2, vKangaroo2;
	std::cin >> xKangaroo1 >> vKangaroo1 >> xKangaroo2 >> vKangaroo2;

	// do while loop for check xKangaroo1 == xKangaroo2
	// kangaroo1 have always bigger or equal in x, if not, switch it
	if (xKangaroo1 <= xKangaroo2) {
		switchValue(xKangaroo1, xKangaroo2);
		switchValue(vKangaroo1, vKangaroo2);
	}

	// the while value have a stop condition IF xKangaroo2 > xKangaroo1 because xKangaroo1
	// always initially bigger
	while (xKangaroo2 <= xKangaroo1) {


		if (xKangaroo2 == xKangaroo1) {
			std::cout << "YES" << std::endl;
			break;
		}
		
		xKangaroo1 += vKangaroo1;
		xKangaroo2 += vKangaroo2;

		if (xKangaroo2 > xKangaroo1) {
			std::cout << "NO" << std::endl;
		}

	}
	
	return 0;
}

void switchValue(int &x1, int &x2) {
	
	int temp = x1;
	x1 = x2;
	x2 = temp;
}
