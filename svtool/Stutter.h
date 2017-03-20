#pragma once
#ifndef STUTTER_H
#define STUTTER_H

#include <iostream>
#include <vector>
#include "Converter.h"
#include "Compiler.h"
#include "Input.h"
#include "Input_Validator.h"

class Stutter {

public:

	//Initiates the Stutter SV program
	//Input NIL
	//Return NIL
	void Stutter_SV();

	//Initiates the Stutter BPM program
	//Input NIL
	//Return NIL
	void Stutter_BPM();

};

#endif // !STUTTER_H
