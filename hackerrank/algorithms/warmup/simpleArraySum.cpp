#include <vector>
#include <iostream>
#include <string>
#include <sstream>

// declare sum function
int sumFunction(std::vector<int>);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sizeArray;
	(std::cin >> sizeArray).get();
    
    // make a vector depending on the size_array
    std::vector<int> arrayNumber(sizeArray);
	 
	// Take the second line output as string to a getline
    std::string arrayNumberString;
	std::getline(std::cin, arrayNumberString);
    
    // use istringstream to cplit the array into chunk of integer
    std::istringstream iss(arrayNumberString);
    int tempNumber = 0;
    
    // export the iss to array_number
    int i = 0;
    while (iss >> tempNumber) {
        arrayNumber[i] = tempNumber;
        i++;
    }
    
    // get arrayNumber summation
    int arrayNumberSum = sumFunction(arrayNumber);
    std::cout << arrayNumberSum;

    return 0;
}

// definition of sum function
int sumFunction(std::vector<int> number) {
    int sum = 0;
    for (auto& n : number) {
        sum += n;
    }
    
    return sum;
};
