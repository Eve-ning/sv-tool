#pragma once
#ifndef SINE_H
#define SINE_H

#include "Converter.h"
#include "Compiler.h"
#include "Input.h"
#include "Input_Validator.h"
#include <iostream>
#include <string>
#include <math.h>

class Sine {

public:

	//Initiates the Sine SV program
	//Input NIL	
	//Return NIL
	void Sine_SV();

	//Initiates the Sine BPM program
	//Input NIL
	//Return NIL
	void Sine_BPM();

};
#endif // !SINE_H
