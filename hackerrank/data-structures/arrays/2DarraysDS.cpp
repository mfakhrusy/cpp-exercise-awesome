#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <numeric>
#define MAX_ROW 6
#define MAX_COL 6

std::array<int, MAX_ROW> strToArray(std::string);

int main() {

	// input
	std::array<std::array<int, MAX_ROW>, MAX_COL> arr2D;

	for (auto i = 0; i < MAX_ROW; i++) {
		std::string stringRowInt;
		std::getline(std::cin, stringRowInt);
		arr2D[i] = strToArray(stringRowInt);
	}

	// the process
	int maxHourGlassSum = -9999;
	for (auto i = 0; i < MAX_ROW - 2; i++) { // - 2 because hourglass is like 3x3 grid
		for (auto j = 0; j < MAX_COL - 2; j++) {

			// calculate hour glass
			int tempHourGlassSum = 0;

			for (auto glassHeight = i; glassHeight < i + 3; glassHeight++) {
				if (glassHeight == i + 1) {
					tempHourGlassSum += arr2D[i + 1][j + 1];
				} else {
					tempHourGlassSum += std::accumulate(arr2D[glassHeight].begin() + j, 
							arr2D[glassHeight].begin() + j + 3, 0);
				}
			}

			if (tempHourGlassSum > maxHourGlassSum) {
				maxHourGlassSum = tempHourGlassSum;
			}
		}
	}

	std::cout << maxHourGlassSum << std::endl;

	return 0;
}

std::array<int, MAX_ROW> strToArray(std::string stringValue) {

	std::array<int, MAX_ROW> result;
	
	std::istringstream iss(stringValue);
	int tempNumber;
	int i = 0;
	while (iss >> tempNumber) {
	
		result[i] = tempNumber;
		i++;
	}

	return result;

}


