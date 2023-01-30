#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <numbers>
#include <cmath>

using namespace std;

int stringToInt(string myString) {
	int x;
	stringstream ss(myString);
	ss >> x;
	return x;
}

int q1() {
	double pi = 3.14159;

	std::string userInput;
	std::cout << "Enter the circle's radius: ";
	std::getline(std::cin, userInput);
	std::cout << "Circle Radius: " << userInput << std::endl;
	int radius = stringToInt(userInput);

	double area;

	area = pi * radius * radius;

	cout << "My circle with radius " << radius << " has an area equals to " << area << std::endl;

	return 0;
}

int q2() {
	
	long double pi = 3.141592653589793238;

	std::string userInput;
	std::cout << "Enter the circle's radius: ";
	std::getline(std::cin, userInput);
	int radius = stringToInt(userInput);
	std::cout << "Circle Radius: " << userInput << std::endl;
	std::cout << "Enter the desired answer precision: ";
	std::getline(std::cin, userInput);
	int precision = stringToInt(userInput);
	std::cout << "Answer recision: " << userInput << std::endl;

	long double area = pi * pow(radius, 2);
	std::cout.precision(precision);
	std::cout << "The area of the circle is " << std::fixed << area << std::endl;
	return 0;
}

bool stringToBool(string ip) {
	bool op;
	istringstream(ip) >> std::boolalpha >> op;
	return op;
}

enum AcademicDegree {
	NONE,
	ASSOCIATE,
	BACHELOR,
	MASTER,
	DOCTOR,
	PROFESSIONAL
};

int q3() {
	std::string userInput;
	AcademicDegree degree = NONE;
	bool isQualified = false;

	while (isQualified == false) {
		std::cout << "Do you speak French (true for yes, false for no)?" << std::endl;
		std::getline(std::cin, userInput);
		bool speaksFrench = stringToBool(userInput);
		if (speaksFrench == false) {
			break;
		}

		std::cout << "Do you speak English (true for yes, false for no)?" << std::endl;
		std::getline(std::cin, userInput);
		bool speaksEnglish = stringToBool(userInput);
		if (speaksEnglish == false) {
			break;
		}

		std::cout << "What is your highest degree(0 for none, 1 for associate, 2 for bachelor, 3 for master, 4 for doctor, 5 for professional) ? " << std::endl;
		std::getline(std::cin, userInput);
		degree = static_cast<AcademicDegree>(stringToInt(userInput));
		if (degree < BACHELOR || degree > MASTER) {
			break;
		}

		std::cout << "How many years of job experience do you have?" << std::endl;
		std::getline(std::cin, userInput);
		int yearsExperience = stringToInt(userInput);
		if (yearsExperience < 3 || yearsExperience > 10) {
			break;
		}
			std::cout << "You meet the qualifications for the job." << std::endl;
			isQualified = true;
	}
	if (isQualified == false) {
		std::cout << "You do not meet the qualifications for the job." << std::endl;
	}

	return 0;
}

int q4() {
	std::string userInput;
	std::cout << "What's the limit?: " << std::endl;
	std::getline(std::cin, userInput);
	int limit = stringToInt(userInput);
	int count = 0;
	for (int i = 1; i <= limit; i++) {
		if (i % 6 == 0 || i % 17 == 0) {
			continue;
		}
		std::cout << i << '\t';
		count++;
		if (count % 10 == 0) {
			std::cout << std::endl;
		}
	}
	return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int q7() {
	int x = 5, y = 10;
	std::cout << "Before swap: x = " << x << " y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << " y = " << y << std::endl;
	return 0;
	//My function works as expected
}

int main() {

	std::string userInput;
	bool menu = true;
	while (menu) {
		std::cout << "Which program would you like to run: Q1, Q2, Q3, Q4, Q5, Q6, Q7, or Q8. "
			<< std::endl << "Please type a number as your answer: ";
		std::getline(std::cin, userInput);
		std::cout << "Running program for question " << userInput << std::endl;
		int i = stringToInt(userInput);

		if (i == 1) {
			q1();
		} if (i == 2) {
			q2();
		} if (i == 3) {
			q3();
		} if (i == 4) {
			q4();
		} if (i == 5) {
			q1();
		} if (i == 6) {
			q1();
		} if (i == 7) {
			q7();
		} if (i == 8) {
			q1();
		}
		else {
			//std::cout << "Please type a valid response..." << std::endl;
		}
	}
	return 0;

}

