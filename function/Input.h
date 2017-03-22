#pragma once
#ifndef INPUT_H
#define INPUT_H

#include "includes.h"
#include "Flooring.h"

class Input {

public:

	//_S Stands for Singular
	//_M Stands for Multiple

	//Initiates a SINGULAR note input prompt
	//Input (Optional Bool) Toggle Flooring Flag
	//Return (Double) Offset, (Int) Key Position
	std::tuple<double, int> Input_N_S(bool flooring_flag = false);

	//Initiates a MULTIPLE note prompt
	//Input (Int) Number of Inputs, (Optional Bool) Toggle Flooring Flag
	//Return (VDouble) Offset, (VInt) Key Position
	std::tuple <std::vector<double>, std::vector<int>> Input_N_M(unsigned int, bool flooring_flag = false);

	//Initiates a SINGULAR timing point prompt and returns a vector double
	//Input (Optional Bool) Toggle Flooring Flag
	//Return (Double) Offset, (Double) Code, (String) Extension
	std::tuple<double, double, std::string> Input_T_S(bool flooring_flag = false);

	//Initiates a MULTIPLE timing point prompt and returns a vector double
	//Input (Int) Number of Inputs, (Optional Bool) Toggle Flooring Flag
	//Return (VDouble) Offset, (VDouble) Code, (VString) Extension
	std::tuple<std::vector<double>, std::vector<double>, std::vector<std::string>> Input_T_M(unsigned int, bool flooring_flag = false);

};

#endif // !INPUT_H
