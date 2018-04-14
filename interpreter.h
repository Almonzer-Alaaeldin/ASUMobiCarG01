/*
  interpreter.h - Library for interpreting the instruction set for mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 14, 2018.
  Released on Github.
*/
#ifndef interpreter_h
#define interpreter_h

#include "Arduino.h"

class interpreter
{
  public:
    interpreter(char  inst , int  arg1 , int  arg2);
		interpreter(long cod);
		interpreter();
		bool encode(char  inst , int  arg1 , int  arg2);
		void decode(char &inst , int &arg1 , int &arg2);
  private:
    long code;
		char instruction;
		int argument1;
		int argument2;
		int exchange(char inst   , bool  sign1 , bool  sign2);
		char exchange(int opcode , bool &sign1 , bool &sign2);
};

#endif
