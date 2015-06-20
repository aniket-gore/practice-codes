#include<iostream>

int endianness(int num){
	//CHECK ENDIANNESS
	int n = 1;
	if(*(char *)&n == 1)
	{
		printf("\nLittle-Endian\n");
	}
	else
	{
		printf("Big-Endian\n");
	}

	//CHANGE ENDINESS
	//considering 32-bit int
	int byte1,byte2,byte3,byte4;
	byte1 = (num & 0x000000ff)>>0;
	byte2 = (num & 0x0000ff00)>>8;
	byte3 = (num & 0x00ff0000)>>16;
	byte4 = (num & 0xff000000)>>24;
	return ((byte1<<24) | (byte2<<16) | (byte3<<8) | (byte4<<0));
}