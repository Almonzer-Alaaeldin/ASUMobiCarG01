/*
  threeBytes.h - Library for efficiently storing instructions mobiCar accurate driving .
  Created by Bassem Abdelwahab, April 13, 2018.
  Released on Github.
*/
#ifndef threeBytes_h
#define threeBytes_h



class threeBytes
{
  public:
	threeBytes(long instruction);
	threeBytes();
	long aquire();
	bool store(long instruction);
  private:
	unsigned char Byte1;
	unsigned char Byte2;
	unsigned char Byte3;
};

#endif
