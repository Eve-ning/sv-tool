#include "Stutter.h"
#include "DEBUG.h"

//Initiates the Stutter SV program
//Input NIL
//Return NIL
void Stutter::Stutter_SV()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> distance_list;
	double threshold;
	double average_SV;
	double allowed_SV1;
	double allowed_SV2;
	double min_osu_SV = 0.1;
	double max_osu_SV = 10.0;
	double initial_SV;
	double second_SV;
	
	//Takes in input for an infinite amount of notes
	std::tie(offset_list, key_list) = _INPUT.Input_N_M(100);
	unsigned int offset_list_size = offset_list.size();

	std::cout << std::endl;

	//Generates a list of distances between the offsets generated
	try {
		for (unsigned int x = 1; x < offset_list_size; x++) {
			distance_list.push_back(offset_list[x] - offset_list[x - 1]);
		}
	}
	catch (...) {
		std::cout << "[ERROR] Unsuccessful distance_list.push_back()" << std::endl;
	}

	if (DEBUG == true) {

		unsigned int distance_list_size = distance_list.size();

		for (unsigned int x = 0; x < distance_list_size; x++) {
			std::cout << "[DEBUG] distance_list: " << distance_list[x] << std::endl;
		}

	}

	//Gets Average SV from user
	std::cout << "Input Average SV ";
	average_SV = _INPUT_VALIDATOR.Input_Value_D(0.1, 10.0, false);
	
	std::cout << std::endl;

	//Gets Threshold from user
	std::cout << "Input Threshold ";
	threshold = _INPUT_VALIDATOR.Input_Value_D(0, 100, false);

	std::cout << std::endl;

	//Calculates SV cases for extreme cases w.r.t. Maximum and Minimum allowable osu! SV
	allowed_SV1 = (average_SV - (max_osu_SV * ((100 - threshold) / 100))) / (threshold / 100);
	allowed_SV2 = (average_SV - (min_osu_SV * ((100 - threshold) / 100))) / (threshold / 100);

	if (allowed_SV1 < 0.1){
		allowed_SV1 = 0.1;
	}
	if (allowed_SV1 > 10.0) {
		allowed_SV1 = 10.0;
	}
	if (allowed_SV2 < 0.1) {
		allowed_SV2 = 0.1;
	}
	if (allowed_SV2 > 10.0) {
		allowed_SV2 = 10.0;
	}

	//Gets Initial SV from user
	std::cout << "Input Initial SV ";
	initial_SV = _INPUT_VALIDATOR.Input_Value_D(((allowed_SV1 < allowed_SV2) ? allowed_SV1 : allowed_SV2), ((allowed_SV1 > allowed_SV2) ? allowed_SV1 : allowed_SV2), true);

	std::cout << std::endl;

	//Calculates Second SV
	second_SV = (1 - (initial_SV * (threshold / 100))) / ((100 - threshold) / 100);	
	std::cout << "[Generating Code]" << std::endl;

	//Compiles and Generates Code
	for (unsigned int x = 0; x < (offset_list_size - 1); x++) {

		_COMPILER.Compiler_T(offset_list[x], _CONVERTER.SV_VtoC(initial_SV), true);
		_COMPILER.Compiler_T((offset_list[x] + (distance_list[x] * (threshold / 100))), _CONVERTER.SV_VtoC(second_SV), true);

	}

	_COMPILER.Compiler_T(offset_list[offset_list_size - 1], _CONVERTER.SV_VtoC(initial_SV), true);

}

//Initiates the Stutter BPM program
//Input NIL
//Return NIL
void Stutter::Stutter_BPM()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> distance_list;
	double threshold;
	double average_BPM;
	double allowed_BPM1;
	double allowed_BPM2;
	double min_osu_BPM = 0.001;
	double max_osu_BPM = 1000000.0;
	double initial_BPM;
	double second_BPM;

	//Takes in input for an infinite amount of notes
	std::tie(offset_list, key_list) = _INPUT.Input_N_M(100);

	unsigned int offset_list_size = offset_list.size();

	//Generates a list of distances between the offsets generated
	try {
		for (unsigned int x = 1; x < offset_list_size; x++) {
			distance_list.push_back(offset_list[x] - offset_list[x - 1]);
		}
	}
	catch (...) {
		std::cout << "[ERROR] Unsuccessful distance_list.push_back()" << std::endl;
	}

	if (DEBUG == true) {

		unsigned int distance_list_size = distance_list.size();

		for (unsigned int x = 0; x < distance_list_size; x++) {
			std::cout << "[DEBUG] distance_list: " << distance_list[x] << std::endl;
		}

	}

	//Gets Average BPM from user
	std::cout << "Input Average BPM ";
	average_BPM = _INPUT_VALIDATOR.Input_Value_D(0, 100000, false);

	std::cout << std::endl;

	//Gets Threshold from user
	std::cout << "Input Threshold ";
	threshold = _INPUT_VALIDATOR.Input_Value_D(0, 100, false);

	std::cout << std::endl;

	//Calculates BPM cases for extreme cases w.r.t. Maximum and Minimum allowable osu! SV
	allowed_BPM1 = (average_BPM - (max_osu_BPM * ((100 - threshold) / 100))) / (threshold / 100);
	allowed_BPM2 = (average_BPM - (min_osu_BPM * ((100 - threshold) / 100))) / (threshold / 100);

	if (allowed_BPM1 < 0.001) {
		allowed_BPM1 = 0.001;
	}
	if (allowed_BPM1 > 1000000.0) {
		allowed_BPM1 = 1000000.0;
	}
	if (allowed_BPM2 < 0.001) {
		allowed_BPM2 = 0.001;
	}
	if (allowed_BPM2 > 1000000.0) {
		allowed_BPM2 = 1000000.0;
	}

	//Gets Initial BPM from user
	std::cout << "Input Initial BPM ";
	initial_BPM = _INPUT_VALIDATOR.Input_Value_D(((allowed_BPM1 < allowed_BPM2) ? allowed_BPM1 : allowed_BPM2), ((allowed_BPM1 > allowed_BPM2) ? allowed_BPM1 : allowed_BPM2), true);

	std::cout << std::endl;

	//Calculates Second BPM
	second_BPM = (average_BPM - (initial_BPM * (threshold / 100))) / ((100 - threshold) / 100);
	std::cout << "[Generating Code]" << std::endl;

	//Compiles and Generates Code
	for (unsigned int x = 0; x < (offset_list_size - 1); x++) {

		_COMPILER.Compiler_T(offset_list[x], _CONVERTER.BPM_VtoC(initial_BPM), false);
		_COMPILER.Compiler_T((offset_list[x] + (distance_list[x] * (threshold / 100))), _CONVERTER.BPM_VtoC(second_BPM), false);

	}

	_COMPILER.Compiler_T(offset_list[offset_list_size - 1], _CONVERTER.BPM_VtoC(initial_BPM), false);

}
