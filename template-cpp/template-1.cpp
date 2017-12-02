#include <iostream>
#include <typeinfo>

template<class TYPE>
void printTwice(TYPE data) {

	std::cout << "Twice of " << data << " is " << data * 2;
    std::cout << " which is a type of " << typeid(data).name();
	std::cout << std::endl;

}

int main() {

	int dataInt = 10;
	printTwice(dataInt);

	double dataDouble = 2.34;
	printTwice(dataDouble);
}
