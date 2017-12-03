#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

int calcPriceActual(std::vector<int>, int);

int main() {

	// input from user
	std::string inputLine;
	std::getline(std::cin, inputLine);
	std::istringstream iss(inputLine);

	int items, k;

	iss >> items >> k;

	// input second line
	std::getline(std::cin, inputLine);
	std::vector<int> cost(items);

	std::string delimiter = " ";
	int count = 0;
	while (count < items) { // NINJA LOOP

		std::size_t delimLocation = inputLine.find(delimiter);
		std::string tempNum = inputLine.substr(0, delimLocation);
		inputLine = inputLine.substr(delimLocation + 1);
		cost[count] = std::stoi(tempNum);
		count++;
			
	}

	// input third line
	std::getline(std::cin, inputLine);
	int bCharged = std::stoi(inputLine);

	// calculate actual price
	int bActual = calcPriceActual(cost, k);

	if (bActual == bCharged) {
		std::cout << "Bon Appetit" << std::endl;
	} else {
		int result = bActual > bCharged ? bActual - bCharged : bCharged - bActual;
		std::cout << result << std::endl;
	}

	return 0;
}

int calcPriceActual(std::vector<int> cost, int k) {

	// size
	int size = cost.size();

	// remove the k-th element from vector
	cost.erase(cost.begin() + k);
	
	// calc sum with STL method
	int init = 0;
	return (std::accumulate(cost.begin(), cost.end(), init) / 2);

}
