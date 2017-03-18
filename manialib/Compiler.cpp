#include "Compiler.h"

//Compiles parameters into single notes
//Input (Int) Number of Keys, (Int) Key of note, (Double) Offset, (Optional String) Extension
//Return NIL
void Compiler::Compiler_NN(int key_No, int key, double offset, std::string extension)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Compiler_NN" << std::endl;
	}

	double keyGap;
	int keyCode;

	//keyGap determines the keyValue
	keyGap = (double)(512 / ((key_No) * 2));

	//keyCode is the code in the .osu format
	keyCode = (int)((key * 2 - 1) * keyGap);

	if (DEBUG == true) {
		std::cout << "[DEBUG] Key Gap Value: " << keyGap << std::endl;
	}

	if (DEBUG == true) {
		std::cout << "[DEBUG] Key Code Value: " << keyCode << std::endl;
	}

	if ((DEBUG == true) && (extension == "1,0,0:0:0:0:")) {

		std::cout << "[DEBUG] Using Default Extension (1,0,0:0:0:0:)" << std::endl;

	}

	//Printing out the compiled short note
	std::cout << keyCode << ",192," << offset << "," << extension << std::endl;

}

//Compiles parameters into long notes
//Input (Int) Number of Keys, (Int) Key of note, (Double) Start Offset, (Double) End Offset, (Optional String) Extension
//Return NIL
void Compiler::Compiler_NL(int key_No, int key, double offset, double offset2, std::string extension)
{

	if (DEBUG == true) {
		std::cout << "[DEBUG] Compiler_NL" << std::endl;
	}

	double keyGap;
	int keyCode;

	//keyGap determines the keyValue
	keyGap = (double)(512 / ((key_No) * 2));

	//keyCode is the code in the .osu format
	keyCode = (int)((key * 2 - 1) * keyGap);

	if (DEBUG == true) {
		std::cout << "[DEBUG] Key Gap Value: " << keyGap << std::endl;
	}

	if (DEBUG == true) {
		std::cout << "[DEBUG] Key Code Value: " << keyCode << std::endl;
	}

	if ((DEBUG == true) && (extension == ":0:0:0:0:")) {

		std::cout << "[DEBUG] Using Default Extension (:0:0:0:0:)" << std::endl;

	}

	//Printing out the compiled long note
	std::cout << keyCode << ",192," << offset << ",128,0," << offset2 << extension << std::endl;

}

//Compiles parameters into a Timing Point
//Input (Double) Offset, (Double) Code, (Optional String) Extension
//Return NIL
void Compiler::Compiler_T(double offset, double code, std::string extension)
{
	if (DEBUG == true) {
		std::cout << "[DEBUG] Compiler_T" << std::endl;
	}

	if ((DEBUG == true) && (extension == "4,2,0,15,1,0")) {
		std::cout << "[DEBUG] Using Default Extension (4,2,0,15,1,0)" << std::endl;
	}

	//Printing out the compiled timing point
	std::cout << offset << "," << code << "," << extension << std::endl;

}
