// Target Heart Rate Calculator

#include <iostream>
#include "HeartRates.hpp"

int main() {

	// initialize class with constructor parameters: first_name, last_name, day_of_birth, month_of_birth, year_of_birth.
	HeartRates me("Muhamad", "Fakhrusy", 45, 13, 1995);

	// display info
	me.displayInfo();

	return 0;
}
