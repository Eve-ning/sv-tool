#include "Input_Validator.h"
#include "DEBUG.h"

double Input_Validator::Input_Value_D(double lower_bound, double upper_bound, bool inclusive)
{
	
	char bracket_o;
	char bracket_c;
	std::string lower_bound_fix;
	std::string upper_bound_fix;
	double input;
	bool validate_flag = false;

	if (inclusive == true) {
		bracket_o = '[';
		bracket_c = ']';
	}
	else {
		bracket_o = '(';
		bracket_c = ')';
	}

	if (lower_bound < -999) {
		lower_bound_fix = "*";
	}
	else {
		lower_bound_fix = std::to_string(lower_bound);
	}

	if (upper_bound > 999) {
		upper_bound_fix = "*";
	}
	else {
		upper_bound_fix = std::to_string(upper_bound);
	}

	std::cout << "[Double] " << bracket_o << lower_bound_fix << " ~ " << upper_bound_fix << bracket_c << ": ";

	std::cin >> input;

	while (validate_flag == false) {

		if (inclusive == true) {

			if (std::cin.fail() || input > upper_bound || input < lower_bound) {

				std::cin.clear();
				std::cout << "[ERROR] Couldn't parse input, make sure that your input is within range and is a double!" << std::endl;
				std::cout << "Try again: ";
				std::cin >> input;

			}
			else {
				validate_flag = true;
			}
		}
		else {

			if (std::cin.fail() || input >= upper_bound || input <= lower_bound) {

				std::cin.clear();
				std::cout << "[ERROR] Couldn't parse input, make sure that your input is within range and is a double!" << std::endl;
				std::cout << "Try again: ";
				std::cin >> input;

			}
			else {
				validate_flag = true;
			}
		}
		
	}

	return input;

}

int Input_Validator::Input_Value_I(int lower_bound, int upper_bound, bool inclusive)
{
	char bracket_o;
	char bracket_c;
	std::string lower_bound_fix;
	std::string upper_bound_fix;
	int input;
	bool validate_flag = false;

	if (inclusive == true) {
		bracket_o = '[';
		bracket_c = ']';
	}
	else {
		bracket_o = '(';
		bracket_c = ')';
	}

	if (lower_bound < -999) {
		lower_bound_fix = "*";
	}
	else {
		lower_bound_fix = std::to_string(lower_bound);
	}

	if (upper_bound > 999) {
		upper_bound_fix = "*";
	}
	else {
		upper_bound_fix = std::to_string(upper_bound);
	}

	std::cout << "[Integer] " << bracket_o << lower_bound_fix << " ~ " << upper_bound_fix << bracket_c << ": ";

	std::cin >> input;

	while (validate_flag == false) {

		if (inclusive == true) {

			if (std::cin.fail() || input > upper_bound || input < lower_bound) {

				std::cin.clear();
				std::cout << "[ERROR] Couldn't parse input, make sure that your input is within range and is an integer!" << std::endl;
				std::cout << "Try again: ";
				std::cin >> input;

			}
			else {
				validate_flag = true;
			}
		}
		else {

			if (std::cin.fail() || input >= upper_bound || input <= lower_bound) {

				std::cin.clear();
				std::cout << "[ERROR] Couldn't parse input, make sure that your input is within range and is an integer!" << std::endl;
				std::cout << "Try again: ";
				std::cin >> input;

			}
			else {
				validate_flag = true;
			}
		}

	}

	return input;
}


