#include <iostream>
#include <vector>

int main() {

	const int MAX_INT = 999;
	const int INIT_INT = 2;

	unsigned int sum = 0;

	for (auto count = INIT_INT; count <= MAX_INT; sum += count, count++) {
	
	}

	std::cout << sum << std::endl;

	return 0;
}
