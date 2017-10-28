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
					std::cout << "your birth date of " << day << " is not appropriate for year of " << getBirthYear() << " and month of " << getBirthMonth() << ", please input another one: ";
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
		unsigned int current_year) {

	// to get the user's age, we need to convert the difference in time
	// to just its days. After that, convert it back to age
	
	// set up local var for birth day, month, and year
	unsigned int birth_day = getBirthDay();
	unsigned int birth_month = getBirthMonth();
	unsigned int birth_year = getBirthYear();

	// simple algorithm for calculating age
	int age = current_year - birth_year;

	// check if current_month < birth_month
	if ( current_month < birth_month ) {
		return ( age - 1 );
	} else if ( current_month > birth_month ) {
		return ( age );
	} else { // current_month == birth_month
		return ( current_day > birth_day ) ? age : age - 1;
		}
}

// getMaximumHeartRate function defined here
unsigned int HeartRates::getMaximumHeartRate(unsigned int age) const {
	return CONST_MAX_HEART_RATE - age;
}

unsigned int HeartRates::getTargetHeartRate(unsigned int maxHeartRate) const {
	return 0.65 * maxHeartRate;
}

// display the information
void HeartRates::displayInfo() {

	// needed for getAge()
	unsigned int current_day;
	unsigned int current_month;
	unsigned int current_year;
	std::cout << "Input current time with date, month, and year with space delimiter: ";
	std::cin >> current_day >> current_month >> current_year;

	// display information
	std::cout << getFirstName() << " ";
	std::cout << getLastName() << ", ";
	std::cout << getBirthDay() << "/";
	std::cout << getBirthMonth() << "/";
	std::cout << getBirthYear() << std::endl;
	unsigned int age = getAge(current_day, current_month, current_year);
	std::cout << getFirstName() << " " << getLastName() << " age is: " << age << std::endl;
	std::cout << getFirstName() << " " << getLastName() << " max heart rate is: " << getMaximumHeartRate(age) << std::endl;
	std::cout << getFirstName() << " " << getLastName() << " average heart rate is: " << getTargetHeartRate(getMaximumHeartRate(age)) << std::endl;
}
