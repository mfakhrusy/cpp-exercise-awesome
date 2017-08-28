#include <iostream>

float floatMachineEps();
double doubleMachineEps();

int main() {

	float fep;
	double dep;

	fep = floatMachineEps();
	dep = doubleMachineEps();

	std::cout << "Machine epsilon for single presision: " << fep << std::endl;
	std::cout << "Machine epsilon for double presision: " << dep << std::endl;

	return 0;
}

float floatMachineEps() {

	float fmachine_e, ftest;
	fmachine_e = 1.0;

	ftest = 1.0 + fmachine_e;
	while (1.0 != ftest) {
		fmachine_e = fmachine_e/2.0;
		ftest = 1.0 + fmachine_e;
	}

	return fmachine_e;
}

double doubleMachineEps() {

	double dmachine_e, dtest;
	dmachine_e = 1.0;

	dtest = 1.0 + dmachine_e;
	while (1.0 != dtest) {
		dmachine_e = dmachine_e/2.0;
		dtest = 1.0 + dmachine_e;
	}

	return dmachine_e;
}

