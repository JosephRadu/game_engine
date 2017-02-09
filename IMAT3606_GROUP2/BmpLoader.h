#ifndef BMPLOADER_H
#define BMPLOADER_H
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "BMP.h"
#include <iostream>
#include <fstream>



class BmpLoader
{
public:

	BMP* loadBmp(const char* fileName); //LoadBmp method that take filename as parameter

	unsigned char header[54]; //BMP header begins with 54-byte header
	unsigned int dataBegin; 
	unsigned int width, height;
	unsigned int fileSize;

};

#endif //BMPLOADER_H
