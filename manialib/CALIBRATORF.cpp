#include "CALIBRATORF.h"

void CALIBRATORF::CALIBRATORF_0()
{

	std::cout << "[CALIBRATIONF_0]" << std::endl;

}

void CALIBRATORF::CALIBRATORF_I()
{

	std::cout << "[CALIBRATIONF_I]" << std::endl;

	std::cout << "[CALIBRATION _Stutter_CAL.Stutter_SV]" << std::endl <<
		"03:01:379 (181379|3,181471|3,181654|3,181837|3,182020|3) - " << std::endl <<
		"1" << std::endl <<
		"10" << std::endl <<
		"9.1" << std::endl;

	_Stutter_CAL.Stutter_SV();

	std::cout << "[CALIBRATION _Stutter_CAL.Stutter_BPM]" << std::endl <<
		"03:01:379 (181379|3,181471|3,181654|3,181837|3,182020|3) - " << std::endl <<
		"164" << std::endl <<
		"10" << std::endl <<
		"1600" << std::endl;

	_Stutter_CAL.Stutter_BPM();
	

}
