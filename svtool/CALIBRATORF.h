#pragma once
#ifndef CALIBRATORF_H
#define CALIBRATORF_H

#include "Stutter.h"
#include "Copier.h"
#include "False.h"
#include "MeasureLine.h"
#include "Normalizer.h"
#include "Sine.h"

class CALIBRATORF {

public:

	//CALIBRATORF_I is the Calibrator for input functions
	//Input (Bool) Stutter, (Bool) Copier, (Bool) False, (Bool) MeasureLine
	void CALIBRATORF_I(bool, bool, bool, bool);

private:

	Stutter _STUTTER_CAL;
	Copier _COPIER_CAL;
	False _FALSE_CAL;
	MeasureLine _MEASURELINE_CAL;

};

#endif // !CALIBRATORF_H
