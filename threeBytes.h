
/*
  threeBytes.h - Library for efficiently storing instructions mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 13, 2018.
  Released on Github.
*/
#ifndef threeBytes_h
#define threeBytes_h

#include "Arduino.h"

class threeBytes
{
  public:
	threeBytes(long value);
	threeBytes();
	long aquire();
	bool store(long instruction);
  private:
	byte Byte1;
	byte Byte2;
	byte Byte3;
};

#endif
