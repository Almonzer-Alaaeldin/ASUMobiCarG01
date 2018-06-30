/*
  threeBytes.cpp - Library for efficiently storing instructions mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 13, 2018.
  Released on Github.
*/

#include "threeBytes.h"

threeBytes::threeBytes(long instruction)
{
  if(instruction>=256*256*256)
	{
		Byte1=0;
		Byte2=0;
		Byte3=0;
	}
	else
	{
		Byte3=instruction%256;
		instruction/=256;
		Byte2=instruction%256;
		instruction/=256;
		Byte1=instruction%256;
	}
}
threeBytes::threeBytes()
{
	Byte1=0;
	Byte2=0;
	Byte3=0;
}


long threeBytes::aquire()
{
  return Byte1*256*256+Byte2*256+Byte3;
}

bool threeBytes::store(long instruction)
{
	if(instruction==0)
	{
		Byte1=0;
		Byte2=0;
		Byte3=0;
	}
	if(instruction>=256*256*256)
	{
		return 0;
	}
	else
	{
	 Byte3=instruction%256;
	 instruction/=256;
	 Byte2=instruction%256;
	 instruction/=256;
	 Byte1=instruction%256;
	}
	return 1;
}
