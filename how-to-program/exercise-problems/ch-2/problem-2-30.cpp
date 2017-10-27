// (Body MAss Index Calculator) We introduced the body mass index (BMI) 
// calculator in Exercise 1.9. The formulas for calculating BMI are
// BMI = (weightInPounds x 703)/(heightInInches x heightInInches)
// or
// BMI = (weightInKilograms)/(heightInMeters x heightInMeters)
//
// Create a BMI calculator application that read user's weight in pounds
// and height in inches (or kg and meter if preferred), then calculates and
// displays the user's body mass index. Also, the application should display 
// the following information from the Departement of Health and Human
// Services/National Institutes of Health so the user can evaluate his/her
// BMI

#include <iostream>

int main() {

	double weight, height;
	
	// input user data
	std::cout << "Input your weight in kilograms: ";
	std::cin >> weight;
	std::cout << "Input your height in meters: ";
	std::cin >> height;

	std::cout << "BMI VALUES" << std::endl;
	std::cout << "Underweight:\tless than 18.5" << std::endl;
	std::cout << "Normal:\t\tbetween 18.5 and 24.9" << std::endl;
	std::cout << "Overweight:\tbetween 25 and 29.9" << std::endl;
	std::cout << "Obese:\t\t30 or greater" << std::endl;
	std::cout << std::endl;

	// calculate BMI
	double bmi = weight/(height*height);
	std::cout << "Your BMI is: " << bmi << " which is ";
	if ( bmi < 18.5 ) {
		std::cout << "UNDERWEIGHT." << std::endl;
	} else if ( bmi >= 18.5 && bmi < 25 ) {
		std::cout << "NORMAL." << std::endl;
	} else if ( bmi >= 25 && bmi < 30) {
		std::cout << "OVERWEIGHT." << std::endl;
	} else {
		std::cout << "OBESE." << std::endl;
	}

	return 0;
}
