/*
	This project is meant to help create header files to aid with SV Tools

	Planned Stuff:

	0. Compiler for Note and Timing Point
	1. Editor Note input
		The number of notes needed can be adjusted
	2. Editor Timing Point input
		The number of points needed can be adjusted
	3. SV (V to C) and its variations
	4. Flooring Notes
		Takes in note as input and prompts for BPM and offset	
	
*/

#include "Converter.h"
#include "Compiler.h"
#include "Input.h"
#include "CALIBRATOR.h"
#include "CALIBRATORF.h"
#include "Stutter.h"

//MAIN_PAUSE SETTINGS
auto MAIN_PAUSE = NULL;

//CALIBRATION TOGGLE
bool CALIBRATION = true;

/*
Add a menu that takes in an enum input if a program encounters an error that can't be fixed*/

int main() {	

	if (CALIBRATION == true){

		CALIBRATORF _CALIBRATORF;
		CALIBRATOR _CALIBRATOR;

		_CALIBRATOR.CALIBRATOR_0(false, false);
		_CALIBRATOR.CALIBRATOR_I(false);
		_CALIBRATORF.CALIBRATORF_I(false, false, false, false, false, false);

	}

	std::cout << "Enter anything to Exit...";
	std::cin >> MAIN_PAUSE;

}