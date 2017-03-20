#include "Sine.h"
#include "DEBUG.h"

void Sine::Sine_SV()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> wavelength_offset_list;
	double start_offset;
	double end_offset;
	double average_SV;
	double start_angle;
	double wavelength;
	double allowed_amplitude1;
	double allowed_amplitude2;
	double amplitude;
	int intermediate_values;
	double max_osu_SV = 10.0;
	double min_osu_SV = 0.1;
	double MATH_PI = 3.14159265358979323846;

	//Takes in Starting and Ending offset with 2 notes
	std::cout << "Input 2 Notes to mark the Start and End respectively:" << std::endl;
	std::tie(offset_list, key_list) = _INPUT.Input_N_M(2);

	start_offset = offset_list[0];
	end_offset = offset_list[1];

	//Takes in Average SV
	std::cout << "Input Average SV ";
	average_SV = _INPUT_VALIDATOR.Input_Value_D(0.1, 10.0, false);

	//Takes in Start Angle (in degrees)
	std::cout << "Input Start Angle (Degrees) ";
	start_angle = ((_INPUT_VALIDATOR.Input_Value_D(-100000, 100000, false)) / 180) * MATH_PI;

	//Takes in Wavelength
	std::cout << "Input 2 Notes for wavelength: " << std::endl;
	std::tie(wavelength_offset_list, key_list) = _INPUT.Input_N_M(2);

	wavelength = wavelength_offset_list[1] - wavelength_offset_list[0];

	//Takes in Amplitude (can't exceed 0.1 and 10.0 bounds)
	allowed_amplitude1 = average_SV - min_osu_SV;
	allowed_amplitude2 = max_osu_SV - average_SV;
	std::cout << "Input Amplitude ";
	amplitude = _INPUT_VALIDATOR.Input_Value_D(0, ((allowed_amplitude1 < allowed_amplitude2) ? allowed_amplitude1 : allowed_amplitude2), true);

	//Takes in Intermediate Values
	std::cout << "Input the number of Timing Points per Wavelength " << std::endl;
	intermediate_values = _INPUT_VALIDATOR.Input_Value_I(1, 100000, true);

	//Generates Code
	std::cout << "[Generating Code]" << std::endl;
	for (double y = start_offset; y < end_offset; y += wavelength) {

		for (double x = 0; x < intermediate_values; x++) {

			double angle;
			angle = (x / intermediate_values)*MATH_PI;

			//Premature break if the cycle doesn't complete
			if (((x / intermediate_values)*wavelength) >= end_offset) {
				_COMPILER.Compiler_T(end_offset, _CONVERTER.SV_VtoC(average_SV + sin(start_angle + angle)*amplitude), true);
				break;
			}

			_COMPILER.Compiler_T(y + ((x / intermediate_values)*wavelength), _CONVERTER.SV_VtoC(average_SV + sin(start_angle + angle)*amplitude), true);

		}

	}

}

void Sine::Sine_BPM()
{

	Input _INPUT;
	Compiler _COMPILER;
	Converter _CONVERTER;
	Input_Validator _INPUT_VALIDATOR;
	std::vector<double> offset_list;
	std::vector<int> key_list;
	std::vector<double> wavelength_offset_list;
	double start_offset;
	double end_offset;
	double average_BPM;
	double start_angle;
	double wavelength;
	double allowed_amplitude1;
	double allowed_amplitude2;
	double amplitude;
	int intermediate_values;
	double min_osu_BPM = 0.001;
	double max_osu_BPM = 1000000.0;
	double MATH_PI = 3.14159265358979323846;

	//Takes in Starting and Ending offset with 2 notes
	std::cout << "Input 2 Notes to mark the Start and End respectively:" << std::endl;
	std::tie(offset_list, key_list) = _INPUT.Input_N_M(2);

	start_offset = offset_list[0];
	end_offset = offset_list[1];

	//Takes in Average SV
	std::cout << "Input Average BPM ";
	average_BPM = _INPUT_VALIDATOR.Input_Value_D(0, 100000, false);

	//Takes in Start Angle (in degrees)
	std::cout << "Input Start Angle (Degrees) ";
	start_angle = ((_INPUT_VALIDATOR.Input_Value_D(-100000, 100000, false)) / 180) * MATH_PI;

	//Takes in Wavelength
	std::cout << "Input 2 Notes for wavelength: " << std::endl;
	std::tie(wavelength_offset_list, key_list) = _INPUT.Input_N_M(2);

	wavelength = wavelength_offset_list[1] - wavelength_offset_list[0];

	//Takes in Amplitude (can't exceed 0.1 and 10.0 bounds)
	allowed_amplitude1 = average_BPM - min_osu_BPM;
	allowed_amplitude2 = max_osu_BPM - average_BPM;
	std::cout << "Input Amplitude ";
	amplitude = _INPUT_VALIDATOR.Input_Value_D(0, ((allowed_amplitude1 < allowed_amplitude2) ? allowed_amplitude1 : allowed_amplitude2), true);

	//Takes in Intermediate Values
	std::cout << "Input the number of Timing Points per Wavelength " << std::endl;
	intermediate_values = _INPUT_VALIDATOR.Input_Value_I(1, 100000, true);

	//Generates Code
	std::cout << "[Generating Code]" << std::endl;
	for (double y = start_offset; y < end_offset; y += wavelength) {

		for (double x = 0; x < intermediate_values; x++) {

			double angle;
			angle = (x / intermediate_values)*MATH_PI;

			//Premature break if the cycle doesn't complete
			if (((x / intermediate_values)*wavelength) >= end_offset) {
				_COMPILER.Compiler_T(end_offset, _CONVERTER.BPM_VtoC(average_BPM + sin(start_angle + angle)*amplitude), true);
				break;
			}

			_COMPILER.Compiler_T(y + ((x / intermediate_values)*wavelength), _CONVERTER.BPM_VtoC(average_BPM + sin(start_angle + angle)*amplitude), true);

		}

	}



}
