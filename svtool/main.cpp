#include "CAL_manialib.h"
#include "CAL_svtool.h"
#include "Compiler.h"
#include "Converter.h"
#include "Copier.h"
#include "DEBUG.h"
#include "False.h"
#include "Input.h"
#include "Input_Validator.h"
#include "MeasureLine.h"
#include "MENU.h"
#include "Normalizer.h"
#include "Sine.h"
#include "Stutter.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <tuple>

//MAIN_PAUSE SETTINGS
auto MAIN_PAUSE = NULL;

//CALIBRATION TOGGLE
bool CALIBRATION = true;

void startup(std::string);
void menu();

int main() {	

	std::string version;

	version = "v0.10";

	startup(version);
	menu();
	std::cout << "Enter anything to Exit..." << std::endl;
	std::cin >> MAIN_PAUSE;

}

void startup(std::string version)
{

	std::cout << "[SV TOOL " << version << "]" << std::endl;
	std::cout << "[Github: https://github.com/Eve-ning/sv-tool]" << std::endl;
	std::cout << std::endl;

}

void menu()
{

	MENU _MENU;
	Input_Validator _INPUT_VALIDATOR;

	bool quit_flag = false;
	int choice;

	std::vector<std::string> menu_list;

	menu_list = { "Quit",
		"Functions",
		"Calibration" };
	
	while (quit_flag == false) {

		std::cout << "[MAIN MENU]" << std::endl;

		for (unsigned int x = 0; x < menu_list.size(); x++) {
			std::cout << "[" << x << "] " << menu_list[x] << std::endl;
		}

		choice = _INPUT_VALIDATOR.Input_Value_I(0, (int)(menu_list.size() - 1), true);
		std::cout << std::endl;

		switch (choice) {

		case 0: {
			quit_flag = true;
			break;
		}
		case 1: {
			try {
				quit_flag = _MENU.MENU_F();
				break;
			}
			catch (...) {
				std::cout << "[ERROR] _MENU.MENU_F() encountered an error" << std::endl;
				break;
				quit_flag = false;
			}
		}
		case 2: {
			try {
				quit_flag = _MENU.MENU_C();
				break;
			}
			catch (...) {
				std::cout << "[ERROR] _MENU.MENU_C() encountered an error" << std::endl;
				break;
				quit_flag = false;
			}
		}
		default: {
			quit_flag = true;
			break;
		}

		}

	}
}
