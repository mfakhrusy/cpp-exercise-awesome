#include <iostream>
#include <iomanip>

int main(int argc, char ** argv) {

	int i, xn;
	int initial_guess = 100;

	xn = initial_guess;
	i = 0;

	while (true) {
	
		std::cout << i << " " << xn << std::endl;

		if (xn == 1) {
			break;
		}
		if (xn%2 == 0) {
			xn = xn/2;
		} else if (xn%2 != 0){
			xn = 3*xn + 1;
		}
		i = i+1;
	}
}
