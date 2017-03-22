#include "False.h"
#include "DEBUG.h"

//Initiates the False SV program
//Input NIL
//Return NIL
void False::False_SV()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> distance_list;
	std::vector<double> false_list;
	double threshold;
	double average_SV;
	double allowed_SV1;
	double allowed_SV2;
	double min_osu_SV = 0.1;
	double max_osu_SV = 10.0;
	double initial_SV;
	double second_SV;
	double false_gap;
	double min_distance;
	double max_distance;
	double lower_distance_fix;
	double upper_distance_fix;
	
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

	//Takes in 2 note input to calculate false gap
	std::cout << "Input the reference gap with 2 notes:" << std::endl;
	std::tie(false_list, key_list) = _INPUT.Input_N_M(2);
	false_gap = false_list[1] - false_list[0];

	//We get the minimum and maximum values of the distance list
	min_distance = *std::min_element(distance_list.begin(), distance_list.end());
	max_distance = *std::max_element(distance_list.begin(), distance_list.end());

	//Modifies the max_osu_sv or min_osu_sv
	lower_distance_fix = max_distance / false_gap;
	upper_distance_fix = min_distance / false_gap;

	if (DEBUG == true) {

		std::cout << "[DEBUG] min_distance: " << min_distance << std::endl;
		std::cout << "[DEBUG] max_distance: " << max_distance << std::endl;
		std::cout << "[DEBUG] lower_distance_fix: " << lower_distance_fix << std::endl;
		std::cout << "[DEBUG] upper_distance_fix: " << upper_distance_fix << std::endl;

	}

	//Gets Average SV from user
	std::cout << "Input Average SV ";
	average_SV = _INPUT_VALIDATOR.Input_Value_D(0.1, 10.0, false);

	//Gets Threshold from user
	std::cout << "Input Threshold ";
	threshold = _INPUT_VALIDATOR.Input_Value_D(0, 100, false);

	//Calculates SV cases for extreme cases w.r.t. Maximum and Minimum allowable osu! SV
	allowed_SV1 = (average_SV - (max_osu_SV * ((100 - threshold) / 100))) / (threshold / 100);
	allowed_SV2 = (average_SV - (min_osu_SV * ((100 - threshold) / 100))) / (threshold / 100);

	if (DEBUG == true) {

		std::cout << "[DEBUG] allowed_SV1: " << allowed_SV1 << std::endl;
		std::cout << "[DEBUG] allowed_SV2: " << allowed_SV2 << std::endl;

	}

	if (allowed_SV1 > allowed_SV2) {

		allowed_SV1 *= upper_distance_fix;
	}
	else {
		allowed_SV2 *= upper_distance_fix;
	}

	if (allowed_SV1 < allowed_SV2) {

		allowed_SV1 *= lower_distance_fix;
	}
	else {
		allowed_SV2 *= lower_distance_fix;
	}

	if (allowed_SV1 < 0.1) {
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

		_COMPILER.Compiler_T(offset_list[x], _CONVERTER.SV_VtoC(initial_SV * (false_gap / distance_list[x])), true);
		_COMPILER.Compiler_T((offset_list[x] + (distance_list[x] * (threshold / 100))), _CONVERTER.SV_VtoC(second_SV * (false_gap / distance_list[x])), true);

	}

	_COMPILER.Compiler_T(offset_list[offset_list_size - 1], _CONVERTER.SV_VtoC(average_SV), true);

	std::cout << std::endl;

}

//Initiates the False BPM program
//Input NIL
//Return NIL
void False::False_BPM()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> distance_list;
	std::vector<double> false_list;
	double threshold;
	double average_BPM;
	double allowed_BPM1;
	double allowed_BPM2;
	double min_osu_BPM = 0.001;
	double max_osu_BPM = 1000000.0;
	double initial_BPM;
	double second_BPM;
	double false_gap;
	double min_distance;
	double max_distance;
	double lower_distance_fix;
	double upper_distance_fix;
	
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

	//Takes in 2 note input to calculate false gap
	std::cout << "Input the reference gap with 2 notes:" << std::endl;
	std::tie(false_list, key_list) = _INPUT.Input_N_M(2);
	false_gap = false_list[1] - false_list[0];

	//We get the minimum and maximum values of the distance list
	min_distance = *std::min_element(distance_list.begin(), distance_list.end());
	max_distance = *std::max_element(distance_list.begin(), distance_list.end());

	//Modifies the max_osu_sv or min_osu_sv
	lower_distance_fix = max_distance / false_gap;
	upper_distance_fix = min_distance / false_gap;

	//Gets Average BPM from user
	std::cout << "Input Average BPM ";
	average_BPM = _INPUT_VALIDATOR.Input_Value_D(0, 100000, false);

	//Gets Threshold from user
	std::cout << "Input Threshold ";
	threshold = _INPUT_VALIDATOR.Input_Value_D(0, 100, false);

	//Calculates BPM cases for extreme cases w.r.t. Maximum and Minimum allowable osu! SV
	allowed_BPM1 = (average_BPM - (max_osu_BPM * ((100 - threshold) / 100))) / (threshold / 100);
	allowed_BPM2 = (average_BPM - (min_osu_BPM * ((100 - threshold) / 100))) / (threshold / 100);

	if (allowed_BPM1 > allowed_BPM2) {

		allowed_BPM1 *= upper_distance_fix;
	}
	else {
		allowed_BPM2 *= upper_distance_fix;
	}

	if (allowed_BPM1 < allowed_BPM2) {

		allowed_BPM1 *= lower_distance_fix;
	}
	else {
		allowed_BPM2 *= lower_distance_fix;
	}

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

		_COMPILER.Compiler_T(offset_list[x], _CONVERTER.BPM_VtoC(initial_BPM * (false_gap / distance_list[x])), false);
		_COMPILER.Compiler_T((offset_list[x] + (distance_list[x] * (threshold / 100))), _CONVERTER.BPM_VtoC(second_BPM * (false_gap / distance_list[x])), false);

	}

	_COMPILER.Compiler_T(offset_list[offset_list_size - 1], _CONVERTER.BPM_VtoC(average_BPM), false);

	std::cout << std::endl;

}
