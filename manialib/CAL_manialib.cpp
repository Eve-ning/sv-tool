#include "CAL_manialib.h"

//CALIBRATOR_0 is the Calibrator for non-input functions
void CAL_manialib::CALIBRATOR_0(bool CONVERTER_B, bool COMPILER_B)
{

	std::cout << "[CALIBRATION_0]" << std::endl;
	if (CONVERTER_B == true) {

		//Converter Calibration
		std::cout << "[CALIBRATION _CONVERTER.BPM_CtoV]" << std::endl << "[60]" << std::endl <<
			_CONVERTER_CAL.BPM_CtoV(1000) << std::endl << std::endl;

		std::cout << "[CALIBRATION _CONVERTER.BPM_VtoC]" << std::endl << "[60]" << std::endl <<
			_CONVERTER_CAL.BPM_VtoC(1000) << std::endl << std::endl;

		std::cout << "[CALIBRATION _CONVERTER.SV_CtoV]" << std::endl << "[-10]" << std::endl <<
			_CONVERTER_CAL.SV_CtoV(10) << std::endl << std::endl;

		std::cout << "[CALIBRATION _CONVERTER.SV_VtoC]" << std::endl << "[-10]" << std::endl <<
			_CONVERTER_CAL.SV_VtoC(10) << std::endl << std::endl;

	}
	else {
		std::cout << "[CALIBRATION SKIPPING CONVERTER]" << std::endl;
	}

	if (COMPILER_B == true) {

		//Compiler Calibration
		std::cout << "[CALIBRATION _COMPILER.Compiler_NN]" << std::endl << "[192,192,1000,1,0,0:0:0:0:]" << std::endl << std::endl;
		_COMPILER_CAL.Compiler_NN(4, 2, 1000);
		std::cout << std::endl;

		std::cout << "[CALIBRATION _COMPILER.Compiler_NL]" << std::endl << "[192,192,1000,128,0,2000:0:0:0:0:]" << std::endl << std::endl;
		_COMPILER_CAL.Compiler_NL(4, 2, 1000, 2000);
		std::cout << std::endl;

		std::cout << "[CALIBRATION _COMPILER.Compiler_T]" << std::endl << "[4,2,4,2,0,15,1,0]" << std::endl << std::endl;
		_COMPILER_CAL.Compiler_T(4, 2, false);
		std::cout << std::endl;

	}
	else {
		std::cout << "[CALIBRATION SKIPPING COMPILER]" << std::endl;
	}

	

}

//CALIBRATOR_I is the Calibrator for input functions
void CAL_manialib::CALIBRATOR_I(bool INPUT_B, bool FLOORING_B)
{

	std::cout << "[CALIBRATION_1]" << std::endl;

	if (INPUT_B == true) {

		//Note Input Calibration

		double Input_N_S_Offset;
		int Input_N_S_Key;

		std::vector<double> Input_N_M_Offset;
		std::vector<int> Input_N_M_Key;

		double Input_T_S_Offset;
		double Input_T_S_Code;
		std::string Input_T_S_Extension;

		std::vector<double> Input_T_M_Offset;
		std::vector<double> Input_T_M_Code;
		std::vector<std::string> Input_T_M_Extension;
		
		std::cout << "[CALIBRATION _INPUT.Input_N_S]" << std::endl <<
			"Preset:" << std::endl <<
			"00:02:732 (2732|3) - " << std::endl;

		std::tie(Input_N_S_Offset, Input_N_S_Key) = _INPUT_CAL.Input_N_S();
		std::cout << std::endl;

		std::cout << "[CALIBRATION _INPUT.Input_N_M]" << std::endl <<
			"Preset:" << std::endl <<
			"00:02:732 (2732|3,2868|2,3005|3) - " << std::endl;

		std::tie(Input_N_M_Offset, Input_N_M_Key) = _INPUT_CAL.Input_N_M(3);
		std::cout << std::endl;

		//Timing Point Input Calibration
		std::cout << "[CALIBRATION _INPUT.Input_T_S]" << std::endl <<
			"Preset:" << std::endl <<
			"175632,-67.8787878787879,3,1,0,5,0,0" << std::endl;

		std::tie(Input_T_S_Offset, Input_T_S_Code, Input_T_S_Extension) = _INPUT_CAL.Input_T_S();
		std::cout << std::endl;

		std::cout << "[CALIBRATION _INPUT.Input_T_M]" << std::endl <<
			"Preset:" << std::endl <<
			"174822,-67.2727272727273,4,1,0,5,0,0" << std::endl <<
			"175632,-67.8787878787879,3,1,0,5,0,0" << std::endl <<
			"176435,-68.4848484848485,3,1,0,5,0,0" << std::endl <<
			"STOP" << std::endl << std::endl;

		std::tie(Input_T_M_Offset, Input_T_M_Code, Input_T_M_Extension) = _INPUT_CAL.Input_T_M(3);
		std::cout << std::endl;

	}
	else {
		std::cout << "[CALIBRATION SKIPPING INPUT]" << std::endl;
	}

	if (FLOORING_B == true) {

		std::vector<double> fix_list = { 1369,1713,2231 };

		//Flooring Calibration
		std::cout << "[CALIBRATION _FLOORING_CAL.Flooring_M]" << std::endl <<
			"Preset:" << std::endl <<
			"1369,344.827586206897,4,3,0,55,1,0" << std::endl <<
			"STOP" << std::endl << std::endl;

		std::cout << std::endl;

	}
	else {
		std::cout << "[CALIBRATION SKIPPING FLOORING]" << std::endl;
	}

	
}
