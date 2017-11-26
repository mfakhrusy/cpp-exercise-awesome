#include <iostream>
#include <array>

int main() {

	static const int ARRAY_SIZE = 10;
	std::array<int, ARRAY_SIZE> toBeSorted = {400, 1, 99, 8, 5, 2, 102, 8, -5, 29};

	for ( auto i = 0; i < ARRAY_SIZE - 1; i++ ) {
		for ( auto j = 0; j < ARRAY_SIZE - 1; j++ ) {
			if ( toBeSorted[j] > toBeSorted[j + 1] ) {
				int temp = toBeSorted[j + 1];
				toBeSorted[j + 1] = toBeSorted[j];
				toBeSorted[j] = temp;
			}
		}
	}

	std::cout << "After: ";
	for ( auto n : toBeSorted ) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	return 0;
}
