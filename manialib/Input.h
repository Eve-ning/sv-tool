#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include "DEBUG.h"


class Input {

public:

	//_S Stands for Singular
	//_M Stands for Multiple

	//Initiates a SINGULAR note input prompt
	//Input NIL
	//Return (Double) Offset, (Int) Key Position
	std::tuple<double, int> Input_N_S();

	//Initiates a MULTIPLE note prompt
	//Input (Int) Number of Inputs
	//Return (VDouble) Offset, (VInt) Key Position
	std::tuple <std::vector<double>, std::vector<int>> Input_N_M(unsigned int);

	//Initiates a SINGULAR timing point prompt and returns a vector double
	//Input NIL
	//Return (Double) Offset, (Double) Code, (String) Extension
	std::tuple<double, double, std::string> Input_T_S();

	//Initiates a MULTIPLE timing point prompt and returns a vector double
	//Input (Int) Number of Inputs
	//Return (VDouble) Offset, (VDouble) Code, (VString) Extension
	std::tuple<std::vector<double>, std::vector<double>, std::vector<std::string>> Input_T_M(unsigned int);

	

};

#endif // !INPUT_H
