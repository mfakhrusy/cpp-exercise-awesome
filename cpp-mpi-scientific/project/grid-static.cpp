#include <iostream>

int main(int argc, char * argv[]) {
	
	double x[100];
	double dx = 1.0/99.0;

	for (int i = 0; i < 100; i++) {
		x[i] = i*dx;
	}

	for (int i = 0; i < 100; i++) {
		std::cout << "x[" << i << "] = " << x[i] << std::endl;
	}
}
