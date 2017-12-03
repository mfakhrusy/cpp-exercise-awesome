#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

void printFunction(int);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	// input from cin
	std::string inputFirstLine;
	std::getline(std::cin, inputFirstLine);
	
	// parse to var
	std::string stringN; // number of sequence
	std::string stringCountQ; // number of queries

	int N, countQ;

	std::istringstream issFirstLine(inputFirstLine);
	issFirstLine >> N >> countQ;

	std::vector<std::vector<int>> seqList(N);
	int lastAnswer = 0;
	
	bool EXIT = false;
	unsigned int count = 0;
	while (!EXIT) {

		// read line by line of input
		std::string stringInput;
		std::getline(std::cin, stringInput);
		std::istringstream iss(stringInput);
		int query, x, y;

		iss >> query >> x >> y;

		// conditional statement depending on query value
		if (query == 1) {

			// find the sequence of vectors
			int index = ((x ^ lastAnswer) % N);
			
			// append to corrent vector
			seqList[index].push_back(y);

		} else if (query == 2) { // query == 2 

			// find the sequence of vectors
			int index = ((x ^ lastAnswer) % N);

			// calculate lastAnswer
			int indexSeq = y % seqList[index].size();

			lastAnswer = seqList[index][indexSeq];

			std::cout << lastAnswer << std::endl;
			
		
		} else {
			EXIT = true;
		}


		// exit loop
		// TODO refactor this
		count++;
		if (count == countQ) {
			EXIT = true;
		}

	}

    return 0;
}

void printFunction(int i) {

	std::cout << i << " ";
}
