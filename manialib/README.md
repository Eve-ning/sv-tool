## manialib
This is where all of the supporting functions go
If you do use these files somewhere else give me a heads up here or on osu! (Evening)

## Functions

# Legends:

- C: Code
- V: Value
- NN: Note (Short)
- NL: Note (Long)
- T: Timing Point
- S: Singular
- M: Mulitple
- V: Vector

- Code: The code you find in the .osu format
- Value: The actual value for that parameter

- Eg. SV Code = -10; SV Value = 10
- Eg. BPM Code = 600; BPM Value = 100

**_Converter.BPM_CtoV:**  

- Converts BPM Value to Code
- Input (Double) Value
- Return (Double) Code

**_Converter.BPM_VtoC:** 

- Converts BPM Code to Value
- Input (Double) Code
- Return (Double) Value
	
**_Converter.SV_CtoV:**

- Converts SV Value to Code  
- Input (Double) Value  
- Return (Double) Code  

**_Converter.SV_VtoC:**

- Converts SV Code to Value  
- Input (Double) Code  
- Return (Double) Value  

**_COMPILER.Compiler_NN:**

- Compiles parameters into single notes  
- Input (Int) Number of Keys, (Int) Key of note, (Double) Offset, (Optional String) Extension  
- Return NIL  
  
**_COMPILER.Compiler_NL:**

- Compiles parameters into long notes  
- Input (Int) Number of Keys, (Int) Key of note, (Double) Start Offset, (Double) End Offset, (Optional String) Extension  
- Return NIL  
  
**_COMPILER.Compiler_T:**

- Compiles parameters into a Timing Point  
- Input (Double) Offset, (Double) Code, (Optional String) Extension  
- Return NIL  

**_INPUT.Input_N_S:**

- Initiates a SINGULAR note input prompt  
- Input NIL  
- Return (Double) Offset, (Int) Key Position  

**_INPUT.Input_N_M:**

- Initiates a MULTIPLE note prompt  
- Input (Int) Number of Inputs  
- Return (VDouble) Offset, (VInt) Key Position  
  
**_INPUT.Input_T_S:**

- Initiates a SINGULAR timing point prompt and returns a vector double  
- Input NIL  
- Return (Double) Offset, (Double) Code, (String) Extension  

**_INPUT.Input_T_M:**

- Initiates a MULTIPLE timing point prompt and returns a vector double  
- Input (Int) Number of Inputs  
- Return (VDouble) Offset, (VDouble) Code, (VString) Extension  

##Files

**Input.cpp & Input.h**

- These files contain the functions that require input

**Converter.cpp & Converter.h**

- These files contain the code to value and value to code functions

**Compiler.cpp & Compiler.h**

- These files contain the functions that compile parameters into working .osu format

**Calibrator.cpp & Calibrator.h**

- These files is meant to test or calibrate the functions, checking if they are working correctly
- CALIBRATOR_0 Calibrates non-input functions; CALIBRATOR_I Calibrates input functions

**DEBUG.h**

- This file just contains a parameter that can toggle the DEBUG messages on or off

**main.cpp**

- Example file that is tuned to calibrate when ran

