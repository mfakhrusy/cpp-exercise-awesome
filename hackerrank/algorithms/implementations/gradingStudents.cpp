#include <iostream>
#include <vector>

int main() {

	static const int baseGradeDiv = 5;
	static const int minRoundedGrade = 3;
	static const int minStudentGrade = 38;

	// input number of students
	int studentNumber;
	std::cin >> studentNumber;

	// loop for the whole things
	std::vector<int> finalStudentGrade(studentNumber);
	for (auto i = 0; i < studentNumber; i++) {
		
		// input each student grade
		int studentGrade;
		std::cin >> studentGrade;

		// check if student grade above or equal to 38
		if (studentGrade >= minStudentGrade) {
			// check the remainder of student grade in base 5 division
			int remainderStudentGrade = studentGrade % baseGradeDiv;
			// if remainder > 2 (3 or 4), round it up to nearest 5 divisable number
			if (remainderStudentGrade >= minRoundedGrade) {
				studentGrade += (baseGradeDiv - remainderStudentGrade);
			}
		}

		finalStudentGrade[i] = studentGrade;
	}

	for (auto n : finalStudentGrade) {
		std::cout << n << std::endl;
	}
	return 0;
}
