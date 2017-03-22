#pragma once
#ifndef FLOORING_H
#define FLOORING_H
#include "includes.h"
#include "Converter.h"
#include "Input.h"
#include "Compiler.h"

class Flooring {

public:
	
	//Initiates the Flooring
	//Input (Double) Fix Offset
	//Return (Double) Fixed Offset
	double Flooring_S(double);

	//Initiates the Flooring
	//Input (VDouble) Fix Offset List
	//Return (VDouble) Fixed Offset List
	std::vector<double> Flooring_M(std::vector<double>);

private:

	std::vector<double> GLOBAL_TIMINGPOINT_OFFSET_LIST;
	std::vector<double> GLOBAL_TIMINGPOINT_CODE_LIST;
	std::vector<std::string> GLOBAL_TIMINGPOINT_EXTENSION_LIST;
	bool FLOORING_FLAG;

};


#endif // !FLOORING_H
