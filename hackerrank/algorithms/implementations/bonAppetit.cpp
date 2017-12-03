#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {

	// input from user
	std::string inputLine;
	std::getline(std::cin, inputLine);
	std::istringstream iss(inputLine);

	int items, k;

	iss >> items >> k;

	// input second line
	std::getline(std::cin, inputLine);
	std::cout << inputLine << std::endl;
	//iss(inputLine);
	std::vector<int> cost(items);
	int tempCount = 0;
/*	while (!inputLine.empty()) {

		iss >> cost[tempCount];
		std::cout << cost[tempCount] << std::endl;
		tempCount++;
			
	}
*/
	return 0;
}
