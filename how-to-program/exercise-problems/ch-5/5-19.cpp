// this program will calculate \pi
#include <iostream>
#include <cmath>

double calc_pi(unsigned int);

int main() {

	// define number of iteration
	static unsigned int CALC_ITER = 1000000;

	// calculate pi
	double pi_value = calc_pi(CALC_ITER);

	std::cout << "pi value: " << pi_value << " with ";
	std::cout << CALC_ITER << " iteration."<< std::endl;

}

double calc_pi(unsigned int iter) {

	double result_pi = 0;

	for (auto i = 0;
			i < iter;
			i++) {
	
		// alternating power calc
		double temp_pow = pow(-1, i);

		// calc denominator -> odd value
		int temp_denom = (2 * i) + 1;
		
		// nominator
		int temp_nom = 4;

		result_pi += temp_pow * static_cast<double>(temp_nom) / static_cast<double>(temp_denom);

	}

	return result_pi;

}
