#include "Copier.h"
#include "DEBUG.h"

//Copies SVs to notes specified
//Input NIL
//Return NIL
void Copier::_Copier()
{

	Input _INPUT;
	Compiler _COMPILER;

	std::vector<double> note_offset_list;
	std::vector<int> note_key_list;
	std::vector<double> timingpoint_offset_list;
	std::vector<double> timingpoint_code_list;
	std::vector<std::string> timingpoint_extension_list;

	std::tie(note_offset_list,note_key_list) = _INPUT.Input_N_M(100);
	std::tie(timingpoint_offset_list, timingpoint_code_list, timingpoint_extension_list) = _INPUT.Input_T_M(100);

	std::cout << std::endl;

	double timingpoint_zero = timingpoint_offset_list[0];

	if (DEBUG == true) {

		std::cout << "[DEBUG] timingpoint_zero: " << timingpoint_zero << std::endl;

	}

	unsigned int timingpoint_offset_list_size = timingpoint_offset_list.size();
	unsigned int note_offset_list_size = note_offset_list.size();

	//Zeroes all timing points according the very first offset in the timing point list
	for (unsigned int x = 0; x < timingpoint_offset_list_size; x++) {

		timingpoint_offset_list[x] = timingpoint_offset_list[x] - timingpoint_zero;

	}
	
	std::cout << "[Generating Code]" << std::endl;

	for (unsigned int y = 0; y < note_offset_list_size; y++) {

		for (unsigned int x = 0; x < timingpoint_offset_list_size; x++) {

			_COMPILER.Compiler_T(timingpoint_offset_list[x] + note_offset_list[y], timingpoint_code_list[x], true, timingpoint_extension_list[x]);

		}

	}

	std::cout << std::endl;
}
