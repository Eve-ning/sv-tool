#include "Converter.h"
#include "DEBUG.h"

//Converts BPM Value to Code
//Input (Double) Value
//Return (Double) Code
double Converter::BPM_VtoC(double value)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] BPM_VtoC" << std::endl;
	}

	double code;

	code = 60000 / value;

	return code;

	if (DEBUG == true) {
		std::cout << "[DEBUG] BPM Value (" << value << ") converted to BPM Code (" << code << ")" << std::endl;
	}
}

//Converts BPM Code to Value
//Input (Double) Code
//Return (Double) Value
double Converter::BPM_CtoV(double code)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] BPM_CtoV" << std::endl;
	}

	double value;

	value = 60000 / code;

	return value;

	if (DEBUG == true) {
		std::cout << "[DEBUG] BPM Code (" << value << ") converted to BPM Value (" << code << ")" << std::endl;
	}
}

//Converts SV Value to Code
//Input (Double) Value
//Return (Double) Code
double Converter::SV_VtoC(double value)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] SV_VtoC" << std::endl;
	}

	double code;

	code = -100 / value;

	return code;

	if (DEBUG == true) {
		std::cout << "[DEBUG] SV Value (" << value << ") converted to SV Code (" << code << ")" << std::endl;
	}
}

//Converts SV Code to Value
//Input (Double) Code
//Return (Double) Value
double Converter::SV_CtoV(double code)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] SV_CtoV" << std::endl;
	}

	double value;

	value = -100 / code;

	return value;

	if (DEBUG == true) {
		std::cout << "[DEBUG] SV Code (" << value << ") converted to SV Value (" << code << ")" << std::endl;
	}
}
