#include <iostream>
#define DIAMOND_WIDTH 13 // have to be ODD

int main() {

	int diamond_portion = (DIAMOND_WIDTH - 1) / 2;
	
	// upper
	for (auto i = 0;
			i < diamond_portion;
			i++) {
		
		// upper left
		// print space
		for (auto j = 0;
				j < diamond_portion - i;
				j++) {
			
			std::cout << " ";
		
		}
		// asterisk
		for (auto j = diamond_portion - i;
				j < diamond_portion;
				j++) {
		
			std::cout << "*";
		}

		// middle upper section
		std::cout << "*";

		// upper right
		// print space
		for (auto j = 0;
				j < i;
				j++) {
		
			std::cout << "*";
		}

		// asterisk
		for (auto j = i;
				j < diamond_portion;
				j++) {
		
			std::cout << " ";
		}

		std::cout << std::endl;
	
	}

	// middle (between upper and lower)
	for (auto j = 0;
			j < DIAMOND_WIDTH;
			j++) {

		std::cout << "*";
	
	}

	std::cout << std::endl;

	// lower
	for (auto i = 0;
			i < diamond_portion;
			i++) {

		// lower left
		// print space
		for (auto j = 0;
				j < i + 1;
				j++) {
		
			std::cout << " ";
		}
		
		// asterisk
		for (auto j = i;
				j < diamond_portion - 1;
				j++) {
		
			std::cout << "*";
		}

		// print middle section
		std::cout << "*";

		// lower right
		// asterisk
		for (auto j = 0;
				j < diamond_portion - i - 1;
				j++) {
			
			std::cout << "*";
		}
		// space
		for (auto j = diamond_portion - i;
				j < diamond_portion;
				j++) {
			
			std::cout << " ";	

		}

		// print endl
		std::cout << std::endl;
	
	}
	

}
