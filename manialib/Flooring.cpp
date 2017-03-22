#include "Flooring.h"
#include "DEBUG.h"

double Flooring::Flooring_S(double fix_offset)
{
	
	Input _INPUT;
	Converter _CONVERTER;
	std::vector<double> GLOBAL_TIMINGPOINT_OFFSET_LIST;
	std::vector<double> GLOBAL_TIMINGPOINT_CODE_LIST;
	std::vector<std::string> GLOBAL_TIMINGPOINT_EXTENSION_LIST;

	std::vector<double> timingpoints_BPM_list;

	std::cout << "[FUNCTION INITIALIZED REQUIRES FLOORING]" << std::endl <<
		"Input all BPM points below <ONLY BPM POINTS>: " << std::endl;
	std::tie(GLOBAL_TIMINGPOINT_OFFSET_LIST, GLOBAL_TIMINGPOINT_CODE_LIST, GLOBAL_TIMINGPOINT_EXTENSION_LIST) = _INPUT.Input_T_M(1000);

	//Convert code_list to BPM_list
	unsigned int GLOBAL_TIMINGPOINT_CODE_LIST_size = GLOBAL_TIMINGPOINT_CODE_LIST.size();

	for (unsigned int x = 0; x < GLOBAL_TIMINGPOINT_CODE_LIST_size; x++) {
		timingpoints_BPM_list.push_back(_CONVERTER.BPM_CtoV(GLOBAL_TIMINGPOINT_CODE_LIST[x]));
	}

	//Insert 0 offset BPM line on the start and 9999999 on the end this is necessary for the upcoming loop
	GLOBAL_TIMINGPOINT_OFFSET_LIST.insert(GLOBAL_TIMINGPOINT_OFFSET_LIST.begin(), 0);
	GLOBAL_TIMINGPOINT_OFFSET_LIST.insert(GLOBAL_TIMINGPOINT_OFFSET_LIST.end(), 9999999);

	//Change the 0 offset Line to the very first BPM line and the end to an arbitrary value since we don't use that
	timingpoints_BPM_list.insert(timingpoints_BPM_list.begin(), timingpoints_BPM_list[0]);
	timingpoints_BPM_list.insert(timingpoints_BPM_list.end(), 999);

	unsigned int timingpoint_counter = 0;

	//Precision is the snap to use to "snap" the offsets
	double precision = 48;


	//Fix flag to check if the note is fixed, else it's going to cycle
	bool fix_flag = false;

	while (fix_flag == false) {

		//Case where the note is on negative offset
		if (fix_offset < 0) {

			std::cout << "[ERROR] A note is on negative offset! (" << fix_offset << ")" << std::endl;
			fix_flag = true;

		}
		//Case ||X
		else if ((fix_offset > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

			//Goes to next pair if note is higher in offset than 2 timingpoints
			timingpoint_counter += 1;

		}
		//Case (|X)|
		else if (fix_offset == GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) {

			//Since it is directly on the Timing Point, it is fixed
			std::cout << "[FLOORING] " << fix_offset << " -> " << fix_offset << std::endl;
			fix_flag = true;

		}
		//Case |X|
		else if ((fix_offset > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

			double BPM;
			double gap;
			double fract_part;
			double int_part;
			double offset_fix;

			//We plus one as we inserted a 0 in offset_list
			BPM = timingpoints_BPM_list[timingpoint_counter];

			//We find the gap with respect to the precision given
			gap = (60000 / BPM) / precision;

			//We look at all possible values from this BPM and snap the note_offset to the nearest one
			//Note that all offsets floored by osu shifts to the left or doesn't

			/*
			We mainly want to grab the highest multiple of "gap" to reach this fix_offset
			We know that osu always floors values, so we take the mutliple of gap and add one to get the correct value
			The only exception is when the multiple of gap is exact
			*/
			fract_part = modf(((fix_offset - GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) / gap), &int_part);

			//If error is negligible we don't add 1 on the int as we assume that osu! flooring didn't do anything
			if (fract_part < 0.1) {
				offset_fix = int_part * gap + GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter];
			}
			else {
				offset_fix = (int_part + 1) * gap + GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter];
			}

			std::cout << "[FLOORING] " << fix_offset << " -> " << offset_fix << std::endl;

			//Set the fix
			fix_offset = offset_fix;

			//We change the flag to true to indicate it is fixed
			fix_flag = true;

		}
		//Case X||
		else if ((fix_offset < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

			std::cout << "[ERROR] Something went wrong during flooring" << std::endl;
			fix_flag = true;

		}
		else {

			std::cout << "[FLOORING] " << fix_offset << " -> " << fix_offset << std::endl;
			fix_flag = true;

		}

	}

	std::cout << "[DEBUG] fix_offset: " << fix_offset << std::endl;

	return fix_offset;
	
}

std::vector<double> Flooring::Flooring_M(std::vector<double> fix_offset_list) {


	Input _INPUT;
	Converter _CONVERTER;
	std::vector<double> GLOBAL_TIMINGPOINT_OFFSET_LIST;
	std::vector<double> GLOBAL_TIMINGPOINT_CODE_LIST;
	std::vector<std::string> GLOBAL_TIMINGPOINT_EXTENSION_LIST;

	std::vector<double> timingpoints_BPM_list;

	std::cout << "[FUNCTION INITIALIZED REQUIRES FLOORING]" << std::endl <<
		"Input all BPM points below <ONLY BPM POINTS>: " << std::endl;
	std::tie(GLOBAL_TIMINGPOINT_OFFSET_LIST, GLOBAL_TIMINGPOINT_CODE_LIST, GLOBAL_TIMINGPOINT_EXTENSION_LIST) = _INPUT.Input_T_M(1000);

	//Convert code_list to BPM_list
	unsigned int GLOBAL_TIMINGPOINT_CODE_LIST_size = GLOBAL_TIMINGPOINT_CODE_LIST.size();

	for (unsigned int x = 0; x < GLOBAL_TIMINGPOINT_CODE_LIST_size; x++) {
		timingpoints_BPM_list.push_back(_CONVERTER.BPM_CtoV(GLOBAL_TIMINGPOINT_CODE_LIST[x]));
	}

	//Insert 0 offset BPM line on the start and 9999999 on the end this is necessary for the upcoming loop
	GLOBAL_TIMINGPOINT_OFFSET_LIST.insert(GLOBAL_TIMINGPOINT_OFFSET_LIST.begin(), 0);
	GLOBAL_TIMINGPOINT_OFFSET_LIST.insert(GLOBAL_TIMINGPOINT_OFFSET_LIST.end(), 9999999);

	//Change the 0 offset Line to the very first BPM line and the end to an arbitrary value since we don't use that
	timingpoints_BPM_list.insert(timingpoints_BPM_list.begin(), timingpoints_BPM_list[0]);
	timingpoints_BPM_list.insert(timingpoints_BPM_list.end(), 999);

	unsigned int fix_offset_list_size = fix_offset_list.size();
	unsigned int timingpoint_counter = 0;

	//Precision is the snap to use to "snap" the offsets
	double precision = 48;

	//We sort the fix_offset list
	std::sort(fix_offset_list.begin(), fix_offset_list.end());

	//Cycles through all offsets to fix
	for (unsigned int x = 0; x < fix_offset_list_size; x++) {

		//Fix flag to check if the note is fixed, else it's going to cycle
		bool fix_flag = false;

		while (fix_flag == false) {

			//Case where the note is on negative offset
			if (fix_offset_list[x] < 0) {

				std::cout << "[ERROR] A note is on negative offset! (" << fix_offset_list[x] << ")" << std::endl;
				fix_flag = true;

			}
			//Case ||X
			else if ((fix_offset_list[x] > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset_list[x] > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

				//Goes to next pair if note is higher in offset than 2 timingpoints
				timingpoint_counter += 1;

			}
			//Case (|X)|
			else if (fix_offset_list[x] == GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) {

				//Since it is directly on the Timing Point, it is fixed
				std::cout << "[FLOORING] " << fix_offset_list[x] << " -> " << fix_offset_list[x] << std::endl;
				fix_flag = true;

			}
			//Case |X|
			else if ((fix_offset_list[x] > GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset_list[x] < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

				double BPM;
				double gap;
				double fract_part;
				double int_part;
				double offset_fix;

				//We plus one as we inserted a 0 in offset_list
				BPM = timingpoints_BPM_list[timingpoint_counter];

				//We find the gap with respect to the precision given
				gap = (60000 / BPM) / precision;

				//We look at all possible values from this BPM and snap the note_offset to the nearest one
				//Note that all offsets floored by osu shifts to the left or doesn't

				/*
					We mainly want to grab the highest multiple of "gap" to reach this fix_offset
					We know that osu always floors values, so we take the mutliple of gap and add one to get the correct value
					The only exception is when the multiple of gap is exact
				*/
				fract_part = modf(((fix_offset_list[x] - GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) / gap), &int_part);

				//If error is negligible we don't add 1 on the int as we assume that osu! flooring didn't do anything
				if (fract_part < 0.1) {
					offset_fix = int_part * gap + GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter];
				}
				else {
					offset_fix = (int_part + 1) * gap + GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter];
				}

				std::cout << "[FLOORING] " << fix_offset_list[x] << " -> " << offset_fix << std::endl;

				//Set the fix
				fix_offset_list[x] = offset_fix;

				//We change the flag to true to indicate it is fixed
				fix_flag = true;

			}
			//Case X||
			else if ((fix_offset_list[x] < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter]) && (fix_offset_list[x] < GLOBAL_TIMINGPOINT_OFFSET_LIST[timingpoint_counter + 1])) {

				std::cout << "[ERROR] Something went wrong during flooring" << std::endl;
				fix_flag = true;

			}
			else {

				std::cout << "[FLOORING] " << fix_offset_list[x] << " -> " << fix_offset_list[x] << std::endl;
				fix_flag = true;

			}

		}
	}

	for (unsigned int x = 0; x < fix_offset_list_size; x++) {

		std::cout << "[DEBUG] fix_offset_list: " << fix_offset_list[x] << std::endl;

	}


	return fix_offset_list;

}