#pragma once
#ifndef CAL_MANIALIB_H
#define CAL_MANIALIB_H

#include "includes.h"

#include "Converter.h"
#include "Compiler.h"
#include "Input.h"

class CAL_manialib {

public:

	//CALIBRATOR_0 is the Calibrator for non-input functions
	//Input (Bool) Calibrate Converter, (Bool) Calibrate Compiler
	void CALIBRATOR_0(bool, bool);

	//CALIBRATOR_I is the Calibrator for input functions
	//Input (Bool) Calibrate Input, (Bool) Calibrate Flooring
	void CALIBRATOR_I(bool, bool);

private:

	Converter _CONVERTER_CAL;
	Compiler _COMPILER_CAL;
	Input _INPUT_CAL;

};


#endif // !CAL_MANIALIB_H
