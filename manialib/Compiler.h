#pragma once
#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <iostream>
#include "DEBUG.h"

class Compiler {

public:

	//Compiles parameters into single notes
	//Input (Int) Number of Keys, (Int) Key of note, (Double) Offset, (Optional String) Extension
	//Return NIL
	void Compiler_NN(int, int, double, std::string = "1,0,0:0:0:0:");

	//Compiles parameters into long notes
	//Input (Int) Number of Keys, (Int) Key of note, (Double) Start Offset, (Double) End Offset, (Optional String) Extension
	//Return NIL
	void Compiler_NL(int, int, double, double, std::string = ":0:0:0:0:");

	//Compiles parameters into a Timing Point
	//Input (Double) Offset, (Double) Code, (Optional String) Extension
	//Return NIL
	void Compiler_T(double, double, std::string = "4,2,0,15,1,0");

};

#endif // !COMPILER_H
