#include <iostream>
#include <string>

int main() {

	// input from user
	std::string time12H;
	std::getline(std::cin, time12H);

	// get the hour, minute, seconds, and pm/ar by substring the time12H
	std::string getHour12H = time12H.substr(0,2);
	std::string getMin12H = time12H.substr(3,2);
	std::string getSec12H = time12H.substr(6,2);
	std::string getPMAM = time12H.substr(8,2);

	// std::cout << getHour12H << ":" << getMin12H << ":" << getSec12H << getPMAM << std::endl;
	
	if (getPMAM == "PM") {
		
		//convert to int, add by 12, convert again to string

		int intHour12H = std::stoi(getHour12H); // 12 is the conversion

		if (intHour12H < 12) {
			intHour12H += 12;
		}
		
		getHour12H = std::to_string(intHour12H);
		std::cout << getHour12H << ":" << getMin12H << ":" << getSec12H << std::endl;

	} else if (getPMAM == "AM") {

		if (getHour12H == "12") {
			getHour12H = "00";
		}
		std::cout << getHour12H << ":" << getMin12H << ":" << getSec12H << std::endl;

	} else {
		std::cout << "Input is wrong.";
	}

	return 0;
}
