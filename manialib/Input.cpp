#include "Input.h"

//Initiates a SINGULAR note input prompt
//Input NIL
//Return (Double) Offset, (Int) Key Position
std::tuple<double, int> Input::Input_N_S()
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Input_N_S" << std::endl;
	}
	
	std::string input_raw;
	std::string input_bracket;
	std::string input_bar;
	std::string input_bar2;
	double input_offset;
	int input_key;
	
	std::cout << "Input Note (1): ";
	std::getline(std::cin, input_raw, '-');
	
	try {
		input_bracket = input_raw.substr(input_raw.find("(") + 1, input_raw.find(")") - (input_raw.find("(") + 1));
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_S.input_bracket encountered an error!" << std::endl;
		//menu
	}

	try {
		input_bar = input_bracket.substr(0, input_bracket.find("|"));
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_S.input_bar encountered an error!" << std::endl;
		//menu
	}

	try {
		input_bar2 = input_bracket.substr(input_bracket.find("|") + 1, 1);
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_S.input_bar encountered an error!" << std::endl;
		//menu
	}

	try {
		input_offset = stod(input_bar);
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_S.input_offset encountered an error!" << std::endl;
		//menu
	}

	try {
		input_key = stoi(input_bar2);
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_S.input_key encountered an error!" << std::endl;
		//menu
	}

	//----------------DEBUG----------------//

	if (DEBUG == true) {
		std::cout << "[DEBUG] input_bracket: " << input_bracket << std::endl;
		std::cout << "[DEBUG] input_bar/input_offset: " << input_bar << std::endl;
		std::cout << "[DEBUG] input_bar2/input_key: " << input_bar2 << std::endl;
	}

	//----------------DEBUG----------------//

	return std::make_tuple(input_offset,input_key);

}

//Initiates a MULTIPLE note prompt
//Input (Int) Number of Inputs
//Return (VDouble) Offset, (VInt) Key Position
std::tuple<std::vector<double>, std::vector<int>> Input::Input_N_M(unsigned int count)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Input_N_M" << std::endl;
	}

	std::string input_raw;
	std::string input_bracket;
	std::string input_bar;
	std::string input_bar2;
	std::vector<double>input_offset_list;
	std::vector<int>input_key_list;
	double input_offset;
	double input_key;

	if (count > 99) {
		std::cout << "Input Note (*): ";
	}

	else {
		std::cout << "Input Note (" << count << "): ";
	}

	std::getline(std::cin, input_raw, '-');

	try {
		input_bracket = input_raw.substr(input_raw.find("(") + 1, input_raw.find(")") - (input_raw.find("(") + 1));
	}
	catch (...) {
		std::cout << "[ERROR] Input_N_M.input_bracket encountered an error!" << std::endl;
		//menu
	}

	while (input_bracket.length() > 2) {

		try {
			input_bar = input_bracket.substr(0, input_bracket.find("|"));
			input_bar2 = input_bracket.substr(input_bracket.find("|") + 1, 1);
			input_bracket = input_bracket.erase(0, input_bar.length() + 3);
		}
		catch (...) {
			std::cout << "[ERROR] Input_N_M.input_bar(2) encountered an error!" << std::endl;
			//menu
		}

		try {
			input_offset = stod(input_bar);
		}
		catch (...) {
			std::cout << "[ERROR] Input_N_M.input_offset encountered an error!" << std::endl;
			//menu
		}

		try {
			input_key = stoi(input_bar2);
		}
		catch (...) {
			std::cout << "[ERROR] Input_N_M.input_key encountered an error!" << std::endl;
			//menu
		}

		input_offset_list.push_back(input_offset);
		input_key_list.push_back(input_key);

		//----------------DEBUG----------------//

		if (DEBUG == true) {
			std::cout << "[DEBUG] input_bar/input_offset: " << input_bar << std::endl;
			std::cout << "[DEBUG] input_bar2/input_key: " << input_bar2 << std::endl;
		}

		//----------------DEBUG----------------//

	}

	//----------------DEBUG----------------//

	if (DEBUG == true) {

		unsigned int input_offset_list_size = input_offset_list.size();
		unsigned int input_key_list_size = input_key_list.size();

		for (unsigned int x = 0; x < input_offset_list_size; x++) {

			std::cout << "[DEBUG] input_offset_list: " << input_offset_list[x] << std::endl;

		}

		for (unsigned int x = 0; x < input_key_list_size; x++) {

			std::cout << "[DEBUG] input_key_list: " << input_key_list[x] << std::endl;

		}

		if (input_offset_list_size != count) {

			std::cout << "[DEBUG] Mismatch in Count/>99 count" << std::endl;

		}

	}

	//----------------DEBUG----------------//

	return std::make_tuple(input_offset_list,input_key_list);

}

//Initiates a SINGULAR timing point prompt and returns a vector double
//Input NIL
//Return (Double) Offset, (Double) Code, (String) Extension
std::tuple<double, double, std::string> Input::Input_T_S()
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Input_T_S" << std::endl;
	}

	std::string input_raw;

	double input_offset;
	double input_code;
	std::string input_extension;

	std::string comma1;
	std::string comma2;

	std::cout << "Input Timing Point (1): ";
	std::cin >> input_raw;

	try {
		comma1 = input_raw.substr(0, input_raw.find(","));
		input_raw = input_raw.erase(0, comma1.length() + 1);
	}
	catch (...) {
		std::cout << "[ERROR] Input_T_S.comma1 encountered an error!" << std::endl;
		//menu
	}

	try {
		comma2 = input_raw.substr(0, input_raw.find(","));
		input_raw = input_raw.erase(0, comma2.length() + 1);
	}
	catch (...) {
		std::cout << "[ERROR] Input_T_S.comma2 encountered an error!" << std::endl;
		//menu
	}

	try {
		input_offset = stod(comma1);
	}
	catch (...) {
		std::cout << "[ERROR] Input_T_S.input_offset encountered an error!" << std::endl;
		//menu
	}

	try {
		input_code = stod(comma2);
	}
	catch (...) {
		std::cout << "[ERROR] Input_T_S.input_code encountered an error!" << std::endl;
		//menu
	}

	input_extension = input_raw;

	//----------------DEBUG----------------//

	if (DEBUG == true) {
		std::cout << "[DEBUG] comma1/input_offset: " << comma1 << std::endl;
		std::cout << "[DEBUG] comma2/input_code: " << comma2 << std::endl;
		std::cout << "[DEBUG] input_raw/input_extension: " << input_raw << std::endl;
	}

	//----------------DEBUG----------------//

	return std::make_tuple(input_offset, input_code, input_extension);
	
}

//Initiates a MULTIPLE timing point prompt and returns a vector double
//Input (Int) Number of Inputs
//Return (VDouble) Offset, (VDouble) Code, (VString) Extension
std::tuple <std::vector<double>, std::vector<double>, std::vector<std::string>> Input::Input_T_M(unsigned int count)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Input_T_M" << std::endl;
	}

	std::string input_raw;
	std::string input_raw_copy;

	double input_offset;
	double input_code;
	std::string input_extension;

	std::vector<double> input_offset_list;
	std::vector<double> input_code_list;
	std::vector<std::string> input_extension_list;

	std::string comma1;
	std::string comma2;

	if (count > 99) {
		std::cout << "Input Timing Point (*) <Type STOP to stop Input>: " << std::endl;
	}
	else {
		std::cout << "Input Timing Point (" << count << ") <Type STOP to stop Input>: " << std::endl;
	}

	std::cin >> input_raw;
	input_raw_copy = input_raw;

	do {

		try {
			comma1 = input_raw.substr(0, input_raw.find(","));
			input_raw = input_raw.erase(0, comma1.length() + 1);
		}
		catch (...) {
			std::cout << "[ERROR] Input_T_S.comma1 encountered an error!" << std::endl;
			//menu
		}

		try {
			comma2 = input_raw.substr(0, input_raw.find(","));
			input_raw = input_raw.erase(0, comma2.length() + 1);
		}
		catch (...) {
			std::cout << "[ERROR] Input_T_S.comma2 encountered an error!" << std::endl;
			//menu
		}

		try {
			input_offset = stod(comma1);
		}
		catch (...) {
			std::cout << "[ERROR] Input_T_S.input_offset encountered an error!" << std::endl;
			//menu
		}

		try {
			input_code = stod(comma2);
		}
		catch (...) {
			std::cout << "[ERROR] Input_T_S.input_code encountered an error!" << std::endl;
			//menu
		}

		input_extension = input_raw;

		//----------------DEBUG----------------//

		if (DEBUG == true) {
			std::cout << "[DEBUG] comma1/input_offset: " << comma1 << std::endl;
			std::cout << "[DEBUG] comma2/input_code: " << comma2 << std::endl;
			std::cout << "[DEBUG] input_raw/input_extension: " << input_raw << std::endl;
		}

		//----------------DEBUG----------------//

		input_offset_list.push_back(input_offset);
		input_code_list.push_back(input_code);
		input_extension_list.push_back(input_extension);

		std::cin >> input_raw;
		input_raw_copy = input_raw;

	} while (input_raw_copy != "STOP");

	//----------------DEBUG----------------//

	if (DEBUG == true) {
	
		unsigned int input_offset_list_size = input_offset_list.size();
		unsigned int input_code_list_size = input_code_list.size();
		unsigned int input_extension_list_size = input_extension_list.size();

		for (unsigned int x = 0; x < input_offset_list_size; x++) {

			std::cout << "[DEBUG] input_offset_list: " << input_offset_list[x] << std::endl;

		}

		for (unsigned int x = 0; x < input_code_list_size; x++) {

			std::cout << "[DEBUG] input_code_list: " << input_code_list[x] << std::endl;

		}

		for (unsigned int x = 0; x < input_extension_list_size; x++) {

			std::cout << "[DEBUG] input_extension_list: " << input_extension_list[x] << std::endl;

		}
	
	}

	//----------------DEBUG----------------//

	return std::make_tuple(input_offset_list, input_code_list, input_extension_list);

}
