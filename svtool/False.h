#pragma once
#ifndef FALSE_H
#define FALSE_H

#include "Converter.h"
#include "Compiler.h"
#include "Input.h"
#include "Input_Validator.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

class False {

public:

	//Initiates the False SV program
	//Input NIL
	//Return NIL
	void False_SV();

	//Initiates the False BPM program
	//Input NIL
	//Return NIL
	void False_BPM();

};
#endif // !FALSE_H
