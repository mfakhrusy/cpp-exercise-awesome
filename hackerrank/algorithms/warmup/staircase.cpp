#include <iostream>

int main() {

	// input staircase size
	int staircaseSize;
	std::cin >> staircaseSize;

	// draw the staircase
	for (auto i = 0; i < staircaseSize; i++) {
		for (auto j = 0; j < staircaseSize - 1 - i; j++) {
			std::cout << " ";
		}
		for (auto j = 0; j < i + 1; j++) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}

	return 0;
}
