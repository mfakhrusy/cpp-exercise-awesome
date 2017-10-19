// implementation of HeartRates class
#include "HeartRates.hpp"
#include <iostream>

// constructor
HeartRates::HeartRates( std::string first_name, 
		std::string last_name,
		unsigned int birth_day,
		unsigned int birth_month,
		unsigned int birth_year) {

	// setting the private variables
	setFirstName( first_name );
	setLastName( last_name );
	setBirthYear( birth_year );
	setBirthMonth( birth_month );
	setBirthDay( birth_day );

}

// set functions implementation
void HeartRates::setFirstName( std::string name ) {

	first_name = name;
}

void HeartRates::setLastName( std::string name ) {

	last_name = name;
}

void HeartRates::setBirthDay( unsigned int day ) {

	// check whether day is true for the month
	switch ( getBirthMonth() ) {
		// in month 1, 3, 5, 7, 8, 10, 12 the valid input is 1 - 31
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if ( day >= 1 && day <= 31) {
				birth_day = day;
			} else {
					std::cout << "your date of " << day << " is not appropriate for year of " << getBirthYear() << " and month of " << getBirthMonth() << ", please input another one: ";
					std::cin >> day;

					// recursive checking until make sense
					setBirthDay( day );
			}
			break;
		// in month 4, 6, 9, 11 the valid input is 1 - 30
		case 4:
		case 6:
		case 9:
		case 11:
			if ( day >= 1 && day <= 31) {
				birth_day = day;
			} else {
					std::cout << "your date of " << day << " is not appropriate for year of " << getBirthYear() << " and month of " << getBirthMonth() << ", please input another one: ";
					std::cin >> day;

					// recursive checking until make sense
					setBirthDay( day );
			}
			break;
		// in month 2, the day is 28 or 29
		case 2:
			if ( getBirthYear() % 4 == 0 ) {
				if ( day >= 1 && day <= 29 ) {
					birth_day = day;
				} else {
					std::cout << "your date of " << day << " is not appropriate for year of " << getBirthYear() << " and month of " << getBirthMonth() << ", please input another one: ";
					std::cin >> day;

					// recursive checking until make sense
					setBirthDay( day );
				}
			} else { // it is not divisable by 4, so the max day is 28
				if ( day >= 1 && day <= 28) {
					birth_day = day;
				} else {
					std::cout << "your date of " << day << " is not appropriate for year of " << getBirthYear() << " and month of " << getBirthMonth() << ", please input another one: ";
					std::cin >> day;

					// recursive checking until make sense
					setBirthDay( day );
				}
			}
			break;
		default:
			std::cout << "your month input is not defined properly, please input another reasonable one (1 - 12): ";
			int month;
			std::cin >> month;
			setBirthMonth( month );
	}

}

void HeartRates::setBirthMonth( unsigned int month ) {

	// check whether it is within 1 - 12 (jan until dec)
	if ( month >= 1 && month <= 12 ) {
		birth_month = month;
	} else {
		std::cout << "your birth month doesn't exist? please input another valid one (1 - 12): ";
		std::cin >> month;

		// recursive checking until birth month makes sense
		setBirthMonth( month );
	}

}

void HeartRates::setBirthYear( unsigned int year ) {

	// check whether it is within 1900 - 2017 (the year of writing this code)
	if ( year >= 1900 && year <= 2017 ) {
		birth_year = year;
	} else {
		std::cout << "your birth year is not imaginable, please input another one: ";
		std::cin >> year;

		// do recursive checking for birth year until it makes sense
		setBirthYear( year );
	}

}

// get functions implementation
std::string HeartRates::getFirstName() const {

	return first_name;
}

std::string HeartRates::getLastName() const {

	return last_name;
}

int HeartRates::getBirthYear() const {

	return birth_year;
}

int HeartRates::getBirthMonth() const {

	return birth_month;
}

int HeartRates::getBirthDay() const {
	
	return birth_day;
}

// getAge() -> calculate age of user
unsigned int HeartRates::getAge(unsigned int current_day,
		unsigned int current_month,
		unsigned int current_year) const {

	// to get the user's age, we need to convert the difference in time
	// to just its days. After that, convert it back to age
	
	// set up local var for birth day, month, and year
	unsigned int temp_birth_day = getBirthDay();
	unsigned int temp_birth_month = getBirthMonth();
	unsigned int temp_birth_year = getBirthYear();

	// convert temp birth day, month, and day to just day

}

// display the information
void HeartRates::displayInfo() const {

	std::cout << getFirstName() << " ";
	std::cout << getLastName() << ", ";
	std::cout << getBirthDay() << "/";
	std::cout << getBirthMonth() << "/";
	std::cout << getBirthYear() << std::endl;
}


// functions etc etc for easiness
unsigned int HeartRates::calc_day( unsigned int day,
		unsigned int month,
		unsigned int year) {
	
	// year value -> start from 1900!
	unsigned int temp_year = year - 1900;
	// check number of year it is divisible by 4:
	unsigned int year_div_by_4 = static_cast<int>(temp_year / 4); // integer division -> floor
	// check number of year it is not divisible by 4:
	unsigned int year_not_div_by_4 = temp_year - year_div_by_4;

	// calc total_day_year;
	int total_day_year = year_div_by_4 * 366 + year_not_div_by_4 * 365;
	
	// month_value
	unsigned int total_day_month = 0;

	// day value
	unsigned int total_day_day = day;

	return total_day_year + total_day_month + total_day_day;
}
