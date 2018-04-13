/*
  threeBytes.h - Library for efficiently storing instructions mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 13, 2018.
  Released on Github.
*/

#include "Arduino.h"
#include "threeByte.h"

threeByte::threeByte(long value)
{
  if(instruction>=16000000)
	{
		Byte1=0;
		Byte2=0;
		Byte3=0;
	}
	else
	{
		Byte3=instruction%256;
		instruction/256;
		Byte2=instruction%256;
		instruction/256;
		Byte1=instruction%256;
	}
}
threeByte::threeByte()
{
	Byte1=0;
	Byte2=0;
	Byte3=0;
}


long threeByte::aquire()
{
  return Byte1*256*256+Byte2*256+Byte3;
}

bool threeByte::store(long instruction)
{
	if(instruction>=16000000)
	{
		return 0;
	}
	else
	{
	 Byte3=instruction%256;
	 instruction/256;
	 Byte2=instruction%256;
	 instruction/256;
	 Byte1=instruction%256;
	}
	return 1;
}
