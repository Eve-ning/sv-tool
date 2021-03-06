#include "MENU.h"
#include "DEBUG.h"

int MENU::MENU_F()
{
	
	Input_Validator _INPUT_VALIDATOR;
	void flooring_prompt(Flooring);
	int choice;
	std::vector <std::string> function_list;

	function_list = { "Quit",
		"Copier",
		"False (SV)",
		"False (BPM)",
		"Measure Lines",
		"Normalizer",
		"Sine (SV)",
		"Sine (BPM)",
		"Stutter (SV)",
		"Stutter (BPM)",
		"Calibration" };

	std::cout << "[FUNCTION MENU]" << std::endl;

	for (unsigned int x = 0; x < function_list.size(); x++) {

		std::cout << "[" << x << "] " << function_list[x] << std::endl;

	}
	
	choice = _INPUT_VALIDATOR.Input_Value_I(0, (int)(function_list.size() - 1), true);

	std::cout << std::endl;

	switch (choice) {

	case 0: {
		return _QUIT;
		break;
	}
	case 1: {
		_COPIER._Copier();
		return _MENU;
		break;
	}
	case 2: {
		_FALSE.False_SV();
		return _MENU;
		break;
	}
	case 3: {
		_FALSE.False_BPM();
		return _MENU;
		break;
	}
	case 4: {
		_MEASURELINE._MeasureLine();
		return _MENU;
		break;
	}
	case 5: {
		_NORMALIZER._Normalizer();
		return _MENU;
		break;
	}
	case 6: {
		_SINE.Sine_SV();
		return _MENU;
		break;
	}
	case 7: {
		_SINE.Sine_BPM();	
		return _MENU;
		break;
	}
	case 8: {
		_STUTTER.Stutter_SV();
		return _MENU;
		break;
	}
	case 9: {
		_STUTTER.Stutter_BPM();
		return _MENU;
		break;
	}
	case 10: {
		return _MENU;
		break;
	}
	default: {
		return _QUIT;
		break;
	}
	}

}
int MENU::MENU_C()
{
	Input_Validator _INPUT_VALIDATOR;
	bool quit = false;
	int choice;
	std::vector <std::string> calibration_list;

	calibration_list = { "Quit",
		"Calibrate manialib (Converter)",
		"Calibrate manialib (Compiler)",
		"Calibrate manialib (Input)",
		"Calibrate manialib (Flooring)",
		"Calibrate manialib (Input Validator)",
		"Calibrate svtool (Stutter)",
		"Calibrate svtool (Copier)",
		"Calibrate svtool (False)",
		"Calibrate svtool (Measure Line)",
		"Calibrate svtool (Normalizer)",
		"Calibrate svtool (Sine)",
		"Calibrate All",
		"Functions" };

	std::cout << "[CALIBRATION MENU]" << std::endl;

	for (unsigned int x = 0; x < calibration_list.size(); x++) {

		std::cout << "[" << x << "] " << calibration_list[x] << std::endl;

	}

	choice = _INPUT_VALIDATOR.Input_Value_I(0, (int)(calibration_list.size() - 1), true);

	std::cout << std::endl;

	switch (choice) {

	case 0: {
		return _QUIT;
		break;
	}
	case 1: {
		_CAL_MANIALIB.CALIBRATOR_0(true, false);
		return _MENU;
		break;
	}
	case 2: {
		_CAL_MANIALIB.CALIBRATOR_0(false, true);
		return _MENU;
		break;
	}
	case 3: {
		_CAL_MANIALIB.CALIBRATOR_I(true, false, false);
		return _MENU;
		break;
	}
	case 4: {
		_CAL_MANIALIB.CALIBRATOR_I(false, true, false);
		return _MENU;
		break;
	}
	case 5: {
		_CAL_MANIALIB.CALIBRATOR_I(false, false, true);
		return _MENU;
		break;
	}
	case 6: {
		_CAL_SVTOOL.CALIBRATORF_I(true, false, false, false, false, false);
		return _MENU;
		break;
	}
	case 7: {
		_CAL_SVTOOL.CALIBRATORF_I(false, true, false, false, false, false);
		return _MENU;
		break;
	}
	case 8: {
		_CAL_SVTOOL.CALIBRATORF_I(false, false, true, false, false, false);
		return _MENU;
		break;
	}
	case 9: {
		_CAL_SVTOOL.CALIBRATORF_I(false, false, false, true, false, false);
		return _MENU;
		break;
	}
	case 10: {
		_CAL_SVTOOL.CALIBRATORF_I(false, false, false, false, true, false);
		return _MENU;
		break;
	}
	case 11: {
		_CAL_SVTOOL.CALIBRATORF_I(false, false, false, false, false, true);
		return _MENU;
		break;
	}
	case 12: {
		_CAL_MANIALIB.CALIBRATOR_0(true, true);
		_CAL_MANIALIB.CALIBRATOR_I(true, true, true);
		_CAL_SVTOOL.CALIBRATORF_I(true, true, true, true, true, true);
		return _MENU;
		break;
	}
	case 13: {
		return _MENU;
		break;
	}
	default: {
		return _QUIT;
		break;
	}
	}
}

//void flooring_prompt()
//{
//
//	Input _INPUT;
//	char flooring_choice;
//	std::vector<double> GLOBAL_TIMINGPOINT_OFFSET_LIST;
//	std::vector<double> GLOBAL_TIMINGPOINT_CODE_LIST;
//	std::vector <std::string> GLOBAL_TIMINGPOINT_EXTENSION_LIST;
//
//	std::cout << "[NOTICE] If you're planning to use this function, consider setting up Flooring as to make your results more accurate" << std::endl;
//	std::cout << "Set up flooring? (Y/N): ";
//
//	std::cin >> flooring_choice;
//
//	while (!(flooring_choice == 'Y' || flooring_choice == 'N') || std::cin.fail()) {
//
//		std::cin.clear();
//		std::cout << "[ERROR] That input wasn't valid" << std::endl << "Try Again: ";
//		std::cin >> flooring_choice;
//
//	}
//
//	if (flooring_choice == 'Y') {
//
//		std::cout << "Input all of the BPM lines here <ONLY BPM LINES>" << std::endl;
//
//		std::tie(GLOBAL_TIMINGPOINT_OFFSET_LIST, GLOBAL_TIMINGPOINT_CODE_LIST, GLOBAL_TIMINGPOINT_EXTENSION_LIST) = _INPUT.Input_T_M(1000);
//		GLOBAL.setFlooring(GLOBAL_TIMINGPOINT_OFFSET_LIST, GLOBAL_TIMINGPOINT_CODE_LIST, GLOBAL_TIMINGPOINT_EXTENSION_LIST);
//
//	}
//
//	else {
//
//
//	}
//
//}