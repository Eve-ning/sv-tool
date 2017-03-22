#pragma once
#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>
#include <iostream>

class Input_Validator {

public:
	//Initiates a double prompt based on range and uses a loop to make sure a valid input is done
	//Input (Double) Lower Bound, (Double) Upper Bound, (Bool) Inclusive of End Points
	//Return (Double) User Input
	double Input_Value_D(double, double, bool);

	//Initiates a integer prompt based on range and uses a loop to make sure a valid input is done
	//Input (Double) Lower Bound, (Double) Upper Bound, (Bool) Inclusive of End Points
	//Return (Int) User Input
	int Input_Value_I(int, int, bool);

};

#endif // !INPUT_VALIDATOR_H
