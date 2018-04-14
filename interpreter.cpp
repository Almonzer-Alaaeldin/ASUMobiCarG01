/*
  interpreter.cpp - Library for interpreting the instruction set for mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 13, 2018.
  Released on Github.
*/
#include "Arduino.h"
#include "interpreter.h"

int interpreter:: exchange(char inst , bool sign1 , bool sign2)
{									//private function takes character of instruction and signs of arguments and supplies op-code for it
	switch (inst)
	{
		case 'L' :		//line instruction
			return 0+sign1*2+sign2*1;
		break;
		
		case 'A' :		//arc instruction
			return 4+sign1*2+sign2*1;
		break;
		
		case 'R' :		//repeat instruction
			return 8+sign2*1;
		break;
		
		case 'S' :		//stop instruction
			return 10;
		break;
		
		case 'B' :		//Bezier curve instruction(under development)
			return 11+sign1*2+sign2*1;
		break;
	}
	return 100;			//for error detection
}

char interpreter:: exchange(int opcode , bool &sign1 , bool &sign2)
{									//private function takes op-code of instruction and supplies instruction character and signs of arguments
	char inst;
	if(opcode>=0&&opcode<=3)
	{
		inst='L';
		opcode-=0;
	}
	else if(opcode>=4&&opcode<=7)
	{
		inst='A';
		opcode-=4;
	}
	else if(opcode==8||opcode==9)
	{
		inst='R';
		opcode-=8;
	}
	else if(opcode==10)
	{
		inst='S';
		opcode-=10;
	}
	else if(opcode>=11&&opcode<=14)
	{
		inst='B';
		opcode-=11;
	}
	switch(opcode)
	{
		case 0:
			sign1=0;
			sign2=0;
			return inst;
		break;
		
		case 1:
			sign1=0;
			sign2=1;
			return inst;
		break;
		
		case 2:
			sign1=1;
			sign2=0;
			return inst;
		break;
		
		case 3:
			sign1=1;
			sign2=1;
			return inst;
		break;
	}
	return '\0';			//for error detection
}

interpreter::interpreter(char  inst , int  arg1 , int  arg2)
{
	
}

interpreter::interpreter(long cod)
{
	
}

interpreter::interpreter()
{
	
}

bool interpreter::encode(char  inst , int  arg1 , int  arg2)
{
	
}

void interpreter::decode(char &inst , int &arg1 , int &arg2)
{
	
}
