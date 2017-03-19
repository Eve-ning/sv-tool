#pragma once
#ifndef CALIBRATORF_H
#define CALIBRATORF_H

#include "Stutter.h"

class CALIBRATORF {

public:

	//CALIBRATORF_0 is the Calibrator for non-input functions
	void CALIBRATORF_0();

	//CALIBRATORF_I is the Calibrator for input functions
	void CALIBRATORF_I();

private:

	Stutter _Stutter_CAL;


};

#endif // !CALIBRATORF_H
