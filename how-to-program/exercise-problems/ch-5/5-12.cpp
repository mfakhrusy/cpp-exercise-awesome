#include <iostream>
#define MAX_PATTERN_COUNT 10
#define SPACE_BETWEEN_PATTERN 1

// main method
void printPatternOne();
void printPatternTwo();
void printPatternThree();
void printPatternFour();
void printPatternAll();

// auxillary method
void printSpace(unsigned int space_number);

int main() {
	
	printPatternAll();

}

void printPatternOne() {

	// i -> row
	// j -> column
	
	for (auto i = 0; i < MAX_PATTERN_COUNT; i++) {
		for (auto j = 0; j <= i; j++) {

			std::cout << "*";	
			
		}

		// print the remaining space
		for (auto j = i + 1; j < MAX_PATTERN_COUNT; j++) {
		
			std::cout << " ";
		}

		std::cout << std::endl;
	}

}

void printPatternTwo() {

	// i -> row
	// j -> column
	
	for (auto i = 0; i < MAX_PATTERN_COUNT; i++) {
		for (auto j = 0; j < MAX_PATTERN_COUNT - i; j++) {

			std::cout << "*";
		
		}

		// print remaining space
		for (auto j = MAX_PATTERN_COUNT - i;
				j < MAX_PATTERN_COUNT; 
				j++) {
			std::cout << " ";
		}

		std::cout << std::endl;
	}
}

void printPatternThree() {

	// i -> row
	// j -> column
	
	for (auto i = 0;
		   i < MAX_PATTERN_COUNT;
		   i++) {
	
		for (auto j = 0; j < i; j++) {
			
			std::cout << " ";
		}

		for (auto j = i; j < MAX_PATTERN_COUNT; j++) {
			
			std::cout << "*";
		}
		
		std::cout << std::endl;
	
	}
}

void printPatternFour() {

	// i -> row
	// j -> column
	
	for (auto i = 0;
		   i < MAX_PATTERN_COUNT;
		   i++) {
	
		for (auto j = 0; j < MAX_PATTERN_COUNT - 1 - i; j++) {
			
			std::cout << " ";
		}

		for (auto j = MAX_PATTERN_COUNT - 1 - i; j < MAX_PATTERN_COUNT; j++) {
			
			std::cout << "*";
		}
		
		std::cout << std::endl;
	
	}
}

void printPatternAll() {

	for (auto row = 0;
			row < MAX_PATTERN_COUNT;
			row++) {

		// first pattern
		for (auto j = 0;
			   j <= row;
			   j++) {

			std::cout << "*";	
			
		}

		for (auto j = row + 1;
			   j < MAX_PATTERN_COUNT;
			  j++) {
		
			std::cout << " ";
		}

		// print space between pattern
		printSpace(SPACE_BETWEEN_PATTERN);

		// second pattern
		for (auto j = 0; j < MAX_PATTERN_COUNT - row; j++) {

			std::cout << "*";
		
		}

		for (auto j = MAX_PATTERN_COUNT - row;
				j < MAX_PATTERN_COUNT; 
				j++) {
			std::cout << " ";
		}

		// print space between pattern
		printSpace(SPACE_BETWEEN_PATTERN);

		// third pattern
		for (auto j = 0; j < row; j++) {
			
			std::cout << " ";
		}

		for (auto j = row; j < MAX_PATTERN_COUNT; j++) {
			
			std::cout << "*";
		}
	
		// print space between pattern
		printSpace(SPACE_BETWEEN_PATTERN);

		// fourth pattern
	
		for (auto j = 0;
				j < MAX_PATTERN_COUNT - 1 - row;
				j++) {
			
			std::cout << " ";
		}

		for (auto j = MAX_PATTERN_COUNT - 1 - row;
				j < MAX_PATTERN_COUNT;
				j++) {
			
			std::cout << "*";
		}
		
		// final, print endline
		std::cout << std::endl;

	}

}

// auxiliary method definition
void printSpace(unsigned int space_number) {

	for (auto i = 0;
			i < space_number;
			i++) {

		std::cout << " ";

	}

}
