#pragma once
#ifndef Converter_H
#define Converter_H

#include "includes.h"

class Converter {

public:

	//Converts BPM Value to Code
	//Input (Double) Value
	//Return (Double) Code
	double BPM_VtoC(double);

	//Converts BPM Code to Value
	//Input (Double) Code
	//Return (Double) Value
	double BPM_CtoV(double);

	//Converts SV Value to Code
	//Input (Double) Value
	//Return (Double) Code
	double SV_VtoC(double);

	//Converts SV Code to Value
	//Input (Double) Code
	//Return (Double) Value
	double SV_CtoV(double);

};


#endif // !Converter_H
