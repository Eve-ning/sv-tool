#include "MeasureLine.h"
#include "DEBUG.h"

void MeasureLine::_MeasureLine()
{

	Input _INPUT;
	Compiler _COMPILER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	double gap;
	double timingpoint_offset;
	double timingpoint_code;
	std::string timingpoint_extension;

	//Takes in 2 notes for the Start and End
	std::cout << "Input Notes for Start, End, Start(2), End(2), Start(3) ... and so on" << std::endl;
	std::tie(offset_list, key_list) = _INPUT.Input_N_M(100);
	unsigned int offset_list_size = offset_list.size();

	//Checks if the number of inputs are even
	if (offset_list_size % 2 != 0) {

		std::cout << "[ERROR] Input an even number of note timestamps" << std::endl;
		std::tie(offset_list, key_list) = _INPUT.Input_N_M(100);
		offset_list_size = offset_list.size();

	}

	//Prompts for gap between Measure Line
	std::cout << "Input the ms gap between each timing point ";
	gap = _INPUT_VALIDATOR.Input_Value_D(0, 100000, false);

	//Prompts for timing point to repeat
	std::cout << "Input the Timing Point to be replicated:" << std::endl;
	std::tie(timingpoint_offset, timingpoint_code, timingpoint_extension) = _INPUT.Input_T_S();

	std::cout << std::endl;

	std::cout << "[Generating Code]" << std::endl;
	//Generate Code
	for (unsigned int y = 0; y < offset_list_size; y += 2) {

		for (double x = offset_list[y]; x < offset_list[y+1]; x += gap) {

			_COMPILER.Compiler_T(x, timingpoint_code, true, timingpoint_extension);

		}

		//Generates a line on the end offset
		_COMPILER.Compiler_T(offset_list[y+1], timingpoint_code, true, timingpoint_extension);
	}

	std::cout << std::endl;

}