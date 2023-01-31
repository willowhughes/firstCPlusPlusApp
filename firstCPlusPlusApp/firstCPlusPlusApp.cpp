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

int q5() {
	std::string userInput;
	std::cout << "Enter size of array: " << std::endl;
	std::getline(std::cin, userInput);
	int size = stringToInt(userInput);

	float* array = new float[size];
	for (int i = 0; i < size; ++i) {
		array[i] = 1.0f / pow((i + 1), 2);
	}

	float sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += array[i];
	}

	std::cout << "Square root of sum: " << sqrt(sum) << std::endl;

	delete[] array;
	return 0;
}

int q6() {
	double d = 3.14;
	int i = 42;
	std::string s = "Hello";

	std::cout << "Double: " << &d << " Value: " << d << std::endl;
	std::cout << "Int: " << &i << " Value: " << i << std::endl;
	std::cout << "String: " << &s << " Value: " << s << std::endl;
	return 0;
	/*Memory diagram assuming 64 bit system with 8 byte memory alignment :
	+-----------------+
	|        d        |
	+-----------------+
	|        i        |
	+-----------------+
	|   s (pointer)   |
	+-----------------+
	|   s (char[6])   |
	+-----------------+
	Reordering the variable declarations or changing the length of the string may result in different addresses for the 
	variables, as the compiler may optimize the memory layout. However, the values of the variables will remain unchanged.
	For example, reordering the variable declarations shown here...:

	int i = 42;
	double d = 3.14;
	std::string s = "Hello";

	...result in this memory diagram:
	+-----------------+
	|        i        |
	+-----------------+
	|        d        |
	+-----------------+
	|   s (pointer)   |
	+-----------------+
	|   s (char[6])   |
	+-----------------+
	*/

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

int q8() {
	int* p = new int[6];
	std::cout << "Enter 6 integers (press enter after each integer): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> p[i];
	}
	std::cout << "Integers in reverse order: " << std::endl;
	for (int i = 5; i >= 0; i--) {
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;

	delete[] p;
	return 0;
}

int main() {

	std::string userInput;
	bool menu = true;
	while (menu) {
		std::cout << "Which program would you like to run: \nQ1: Write a program that will compute the area" 
		"of a circle.The program should prompt for the radius of the circle.It should then display the result. " 
		"\n\nQ2: Write another version of the first program. Write a program that will compute the area of a circle." 
		"The program should prompt for the radius of the circle and the precision of the answer.  It should then display " 
		"the result.  You will likely want to switch data types.You will need a highly precise version of pi. "
		"3.141592653589793238 may work.\n\nQ3: Write a program that checks if a 'job candidate' meets the qualifications for " 
		"the job.The job qualification is they have a bachelor or masters degree, speaks Frenchand English, and has more "
		"than 3 years of job experience but less than 10. The user will be prompted to enter answers to each question and "
		"then the program should output whether or not the user is qualified for the job. Make a variable called degree "
		"thats is an enumeration type AcademicDegree(possible values: none, associate, bachelor, master, doctor, "
		"professional). Checks language with speaksFrench and speaksEnglish booleans. If the user enters invalid "
		"values, they should immediately be disqualified.\n\nQ4: Write a program that writes the numbers 1 to an arbitrary "
		"limit determined by a user. The program should write the numbers in rows of 10 numbers each, 1 number per column. "
		"Do not include numbers that are multiples of 6 or are multiples of 17. \n\nQ5: Write a program that reads an array "
		"size from the keyboard and dynamically allocates an array of that size for floating-point values. Using pointer "
		"notation, initialize all the elements of the array so that the value is the index position n, 1 / (n + 1) ^ 2. "
		"Calculate the sum of the elements using array notation, and then output the square root of that sum.\n\nQ6: Write "
		"a short program in c and declare a double, an int and a string. Your program should then print the address and "
		"value of all three variables. Draw a small memory diagram showing the location of each of the variables in your "
		"program.Are they allocated in the same order that you declared them ? Is there any empty space between them ? "
		"Modify your program by rearranging the variable declarations and /or changing the length of the string. "
		"(In particular, try a string that uses 5 or 7 bytes, including the null terminator.) Does this change the results "
		"you got previously? \n\nQ7: Write a function that accepts two variables (by value) of the same data type of your "
		"choice (e.g. int or double) and tries to swap their values.  The call your function in a main function.  Does your "
		"function work as you expected? Can you modify the function to work as you expected?\n\nQ8: Write a program that "
		"dynamically allocates a chunk of memory large enough to store 6 integers.Then prompt the user the enter 6 integers "
		"and store them in your newly - allocated memory.Finally, print the integer values in reverse order. (Recall from "
		"part c that the close correspondence between pointers and arrays in C.This correspondence allows you to treat the "
		"pointer returned by malloc as the name of a 6 - element int array.) Remember to free the memory you allocated ? "

		"\n\nPlease type a number as your answer: ";
		std::getline(std::cin, userInput);
		std::cout << "Running program for question " << userInput << std::endl;
		int i = stringToInt(userInput);

		if (i == 1) { q1(); } if (i == 2) { q2(); } if (i == 3) { q3(); } if (i == 4) { q4(); } 
		if (i == 5) { q5(); } if (i == 6) { q6(); } if (i == 7) { q7(); } if (i == 8) { q8(); }

		std::cout << "Would you like to try another program (type 1 for yes, 2 for no)? ";
		std::getline(std::cin, userInput);
		i = stringToInt(userInput);
		if (i != 1) {
			break;
		}
	}
	return 0;

}

