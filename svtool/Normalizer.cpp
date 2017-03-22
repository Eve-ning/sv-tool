#include "Normalizer.h"
#include "DEBUG.h"

void Normalizer::_Normalizer()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> timingpoint_offset;
	std::vector<double> timingpoint_code;
	std::vector<std::string> timingpoint_extension;
	double timingpoint_code_normalize;
	double BPM;
	bool out_of_range = false;

	//Takes in multiple Timing Point input
	std::tie(timingpoint_offset, timingpoint_code, timingpoint_extension) = _INPUT.Input_T_M(100);

	//Prompts for BPM to normalize to
	std::cout << "Input BPM to Normalize to ";
	BPM = _INPUT_VALIDATOR.Input_Value_D(0, 100000, false);

	std::cout << std::endl;

	std::cout << "[Generating Code]" << std::endl;

	//Code Generation
	unsigned int timingpoint_code_size = timingpoint_code.size();
	for (unsigned int x = 0; x < timingpoint_code_size; x++) {

		timingpoint_code_normalize = (BPM / _CONVERTER.BPM_CtoV(timingpoint_code[x]));
		_COMPILER.Compiler_T(timingpoint_offset[x],_CONVERTER.SV_VtoC(timingpoint_code_normalize), true);

		//out_of_range flag to notify some Normalization might not work
		if (timingpoint_code_normalize < 0.1 || timingpoint_code_normalize > 10.0) {
			out_of_range = true;
		}

	}

	if (out_of_range == true) {
		std::cout << "[NOTICE] SVs generated exceeded the lower bound 0.1 or upper bound 10.0" << std::endl;
	}

	std::cout << std::endl;

}
