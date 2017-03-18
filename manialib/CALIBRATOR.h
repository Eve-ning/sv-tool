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
	void CALIBRATOR_0();

	//CALIBRATOR_I is the Calibrator for input functions
	void CALIBRATOR_I();

private:

	Converter _Converter_CAL;
	Compiler _COMPILER_CAL;
	Input _INPUT_CAL;


};


#endif // !CALIBRATOR_H
