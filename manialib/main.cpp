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

//MAIN_PAUSE SETTINGS
auto MAIN_PAUSE = NULL;

int main() {

	Converter _CONVERTER;
	Compiler _COMPILERS;
	Input _INPUT;
	CALIBRATOR _CALIBRATOR;

	_CALIBRATOR.CALIBRATOR_0();
	std::cout << std::endl;
	_CALIBRATOR.CALIBRATOR_I();


	std::cout << "Enter anything to Exit...";
	std::cin >> MAIN_PAUSE;
}