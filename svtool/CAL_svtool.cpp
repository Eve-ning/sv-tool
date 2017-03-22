#include "CAL_svtool.h"
#include "DEBUG.h"

void CAL_svtool::CALIBRATORF_I(bool STUTTER_B, bool COPIER_B, bool FALSE_B, bool MEASURELINE_B, bool NORMALIZER_B, bool SINE_B)
{

	std::cout << "[CALIBRATIONF_I]" << std::endl;

	if (STUTTER_B == true) {

		std::cout << "[CALIBRATION _Stutter_CAL.Stutter_SV]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,1500|3,2000|3,2500|3,3000|3) - " << std::endl <<
			"1" << std::endl <<
			"50" << std::endl <<
			"1.5" << std::endl << std::endl;

		_STUTTER_CAL.Stutter_SV();

		std::cout << "[CALIBRATION _Stutter_CAL.Stutter_BPM]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,1500|3,2000|3,2500|3,3000|3) - " << std::endl <<
			"120" << std::endl <<
			"50" << std::endl <<
			"180" << std::endl << std::endl;

		_STUTTER_CAL.Stutter_BPM();

	}
	else {
		std::cout << "[CALIBRATION SKIPPING STUTTER]" << std::endl;
	}

	if (COPIER_B == true) {

		std::cout << "[CALIBRATION _COPIER_CAL._Copier()]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,1500|3,2000|3,2500|3,3000|3) - " << std::endl <<
			"100,-50,4,2,0,15,0,0" << std::endl <<
			"200,-100,4,2,0,15,1,0" << std::endl <<
			"STOP" << std::endl << std::endl;

		_COPIER_CAL._Copier();

	}
	else {
		std::cout << "[CALIBRATION SKIPPING COMPILER]" << std::endl;
	}

	if (FALSE_B == true) {

		std::cout << "[CALIBRATION _FALSE_CAL.False_SV]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,2000|3,2500|3,3000|3) - " << std::endl <<
			"00:01:000 (2000|3,2500|3) - " << std::endl <<
			"1" << std::endl <<
			"10" << std::endl <<
			"1.5" << std::endl << std::endl;

		_FALSE_CAL.False_SV();

		std::cout << "[CALIBRATION _FALSE_CAL.False_BPM]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,1500|3,2000|3,2500|3,3000|3) - " << std::endl <<
			"00:01:000 (2000|3,2500|3) - " << std::endl <<
			"120" << std::endl <<
			"10" << std::endl <<
			"180" << std::endl << std::endl;

		_FALSE_CAL.False_BPM();

	}
	else {
		std::cout << "[CALIBRATION SKIPPING FALSE]" << std::endl;
	}

	if (MEASURELINE_B == true) {

		std::cout << "[CALIBRATION _MEASURELINE_CAL._MeasureLine]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,1500|3,2000|3,2500|3) - " << std::endl <<
			"100" << std::endl <<
			"1000,600,4,2,0,15,0,0" << std::endl << std::endl;

		_MEASURELINE_CAL._MeasureLine();

	}
	else {
		std::cout << "[CALIBRATION SKIPPING MEASURELINE]" << std::endl;
	}

	if (NORMALIZER_B == true) {

		std::cout << "[CALIBRATION _NORMALIZER_CAL._Normalizer]" << std::endl <<
			"Preset:" << std::endl <<
			"1000,600,4,2,0,5,1,0" << std::endl <<
			"2000,300,4,2,0,5,1,0" << std::endl <<
			"3000,200,4,2,0,5,1,0" << std::endl <<
			"STOP" << std::endl <<
			"100" << std::endl << std::endl;

		_NORMALIZER_CAL._Normalizer();

	}
	else {
		std::cout << "[CALIBRATION SKIPPING NORMALIZER]" << std::endl;
	}

	if (SINE_B == true) {
		
		std::cout << "[CALIBRATION _SINE_CAL.Sine_SV]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,5000|3) - " << std::endl <<
			"1" << std::endl <<
			"90" << std::endl <<
			"00:01:000 (1000|3,3000|3) - " << std::endl <<
			".5" << std::endl <<
			"8" << std::endl << std::endl;

		_SINE_CAL.Sine_SV();

		std::cout << "[CALIBRATION _SINE_CAL.Sine_BPM]" << std::endl <<
			"Preset:" << std::endl <<
			"00:01:000 (1000|3,5000|3) - " << std::endl <<
			"120" << std::endl <<
			"90" << std::endl <<
			"00:01:000 (1000|3,3000|3) - " << std::endl <<
			"60" << std::endl <<
			"8" << std::endl << std::endl;

		_SINE_CAL.Sine_BPM();
	}
	else {
		std::cout << "[CALIBRATION SKIPPING SINE]" << std::endl;
	}
}
