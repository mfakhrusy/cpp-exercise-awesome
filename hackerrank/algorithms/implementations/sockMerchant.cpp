#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int socketNumber;
	(std::cin >> socketNumber).get();

	// read second line of input
	std::vector<int> sockType(socketNumber);
	for (auto &sock : sockType) {
		
		std::cin >> sock;

	}

	// use std::count from algorithm header to do the main course!
	int matchingSocks = 0;
	std::vector<int> saveSock;
	for (auto sockTarget : sockType) {
		
		// the std::find will point to the saveSock.end() IF the target
		// is not found. Thus the if will goes like the following.
		// It will true if the element sockTarget is not found in saveSock
		// pretty tedious huh.
		if (std::find(saveSock.begin(), saveSock.end(), sockTarget) == saveSock.end()) {
			
			// find occurence of sock in sockType,
			// if sock occurence == odd, increase counter
			// of unmatching socks
			int sockOccurence = std::count(sockType.begin(), sockType.end(), sockTarget);
			if (sockOccurence % 2 == 0) {
			
				matchingSocks += sockOccurence / 2;
	
			} else if (sockOccurence > 2) {
				
				int tempOccurence = sockOccurence - 1; // to get actual pair
				matchingSocks += sockOccurence / 2;

			}
	
		}
		
		// save sock to saveSock to prevent further computation
		saveSock.push_back(sockTarget);

	}

	std::cout << matchingSocks;

	return 0;
}
