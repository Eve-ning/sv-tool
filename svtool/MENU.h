#pragma once
#ifndef MENU_H
#define MENU_H

#include "Copier.h"
#include "False.h"
#include "MeasureLine.h"
#include "Normalizer.h"
#include "Sine.h"
#include "Stutter.h"
#include "CAL_manialib.h"
#include "CAL_svtool.h"
#include "Input_Validator.h"
#include "Flooring.h"

class MENU {

public:
	//Initates Function Menu
	//Input NIL
	//Return (Int) Flag
	int MENU_F();

	//Initates Calibration Menu
	//Input NIL
	//Return (Int) Flag
	int MENU_C();

	////Prompts for Flooring
	////Input NIL
	////Return NIL
	//void flooring_prompt();

private:

	Copier _COPIER;
	False _FALSE;
	MeasureLine _MEASURELINE;
	Normalizer _NORMALIZER;
	Sine _SINE;
	Stutter _STUTTER;

	CAL_manialib _CAL_MANIALIB;
	CAL_svtool _CAL_SVTOOL;

	enum FLAG {

		_MENU,
		_QUIT

	};

};


#endif // !MENU_H
