#include <iostream>

int main(int argc, char ** argv) {

	int a, b, c;

	a = 0;
	b = 5;

	c = a && b;

	std::cout << "The value of c = " << c << std::endl;

	return 0;
}
