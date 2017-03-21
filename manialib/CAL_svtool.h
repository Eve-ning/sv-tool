#pragma once
#ifndef CAL_SVTOOL_H
#define CAL_SVTOOL_H

#include "Stutter.h"
#include "Copier.h"
#include "False.h"
#include "MeasureLine.h"
#include "Normalizer.h"
#include "Sine.h"

class CAL_svtool {

public:

	//CALIBRATORF_I is the Calibrator for input functions
	//Input (Bool) Stutter, (Bool) Copier, (Bool) False, (Bool) MeasureLine, (Bool) Normalizer, (Bool) Sine
	void CALIBRATORF_I(bool, bool, bool, bool, bool, bool);

private:

	Stutter _STUTTER_CAL;
	Copier _COPIER_CAL;
	False _FALSE_CAL;
	MeasureLine _MEASURELINE_CAL;
	Normalizer _NORMALIZER_CAL;
	Sine _SINE_CAL;

};

#endif // !CAL_SVTOOL_H
