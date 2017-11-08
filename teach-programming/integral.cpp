#include <iostream>
#include <vector>

//class declaration
class IntegralCalculation {
	
	public:
		// constructor
		IntegralCalculation( int,
			   std::vector<double>, std::vector<double> );
		double calcIntegralLeftRiemann();
		double calcIntegralRightRiemann();
		double calcIntegralTrapezoid();

	private:
		int max_grid_point;
		std::vector<double> x;
		std::vector<double> y;
};

// standalone function
double f_1( double x );
int main() {

	// general parameters
	double x_initial = 0;
	double x_final = 1;
	// max_grid = max_grid_point - 1
	int max_grid_point = 111;
	std::vector<double> x(max_grid_point);
	std::vector<double> y(max_grid_point);
	
	// calc x -> equally spaced
	for (auto i = 0; i < max_grid_point; i++) {
		x[i] = (x_final - x_initial)*((i)/(static_cast<double>(max_grid_point) - 1));
	}
	
	// calc y for f_1
	for (auto i = 0; i < max_grid_point; i++) {
		y[i] = f_1(x[i]);
	}

	// declare class
	IntegralCalculation integral_f_1(max_grid_point, x, y);

	// calc_integral
	double resultLeftRiemann = integral_f_1.calcIntegralLeftRiemann();
	double resultRightRiemann = integral_f_1.calcIntegralRightRiemann();
	std::cout << "Left Riemann of f_1:\t" << resultLeftRiemann << std::endl;
	std::cout << "Right Riemann of f_1:\t" << resultRightRiemann << std::endl;

	return 0;
}

// standalone function definition
// 1. x^2 + x + 2
double f_1( double x ) {
	return x*x + x + 2;
}

// class IntegralCalculation definition
// 1. constructor
IntegralCalculation::IntegralCalculation( int input_max_grid_point,
		std::vector<double> input_x, 
		std::vector<double> input_y ) {
		
		max_grid_point = input_max_grid_point;
		x = input_x;
		y = input_y;
}

// 2. left riemann
double IntegralCalculation::calcIntegralLeftRiemann() {
	double result = 0;
	int max_grid = max_grid_point - 1;
	for (auto i = 0; i < max_grid; i++) {
		// calc delta_x
		double delta_x = x[i + 1] - x[i];

		// calc riemann partition
		double integralPartition = y[i] * delta_x;

		// sum the result
		result += integralPartition;
	}

	return result;
}

// 2. right riemann
double IntegralCalculation::calcIntegralRightRiemann() {
	double result = 0;
	int max_grid = max_grid_point - 1;
	for (auto i = 0; i < max_grid; i++) {
		// calc delta_x
		double delta_x = x[i + 1] - x[i];

		// calc riemann partition
		double integralPartition = y[i + 1] * delta_x;

		// sum the result
		result += integralPartition;
	}

	return result;
}

// 2. trapezoidal integration
double IntegralCalculation::calcIntegralTrapezoid() {
	double result = 0;
	int max_grid = max_grid_point - 1;

	// append first and last y to result
	result += (y[0] * (x[1] - x[0]);
	result += y[max_grid_point - 1] * ();

	// append the rest
	for (auto i = 0; i < max_grid; i++) {
		// calc delta_x
		double delta_x = x[i + 1] - x[i];

		// calc riemann partition
		double integralPartition = y[i + 1] * delta_x;

		// sum the result
		result += integralPartition;
	}

	return result;
}
