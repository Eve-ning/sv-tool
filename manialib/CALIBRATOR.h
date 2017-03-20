#pragma once
#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

#include "Converter.h"
#include "Compiler.h"
#include "Input.h"



class CALIBRATOR {

public:

	//CALIBRATOR_0 is the Calibrator for non-input functions
	//Input (Bool) Calibrate Converter, (Bool) Calibrate Compiler
	void CALIBRATOR_0(bool, bool);

	//CALIBRATOR_I is the Calibrator for input functions
	//Input (Bool) Calibrate Input
	void CALIBRATOR_I(bool);

private:

	Converter _CONVERTER_CAL;
	Compiler _COMPILER_CAL;
	Input _INPUT_CAL;

};


#endif // !CALIBRATOR_H
