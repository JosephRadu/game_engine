#include "BmpLoader.h"

BMP* BmpLoader::loadBmp(const char* fileName)
{
	BMP* bmpLoad = new BMP;

	FILE* file = fopen(fileName, "rb");

	if (file == NULL)
	{
		std::cout << "Error opening BMP file" << std::endl;

	}
	
	if (fread(header, 1, 54, file) != 54)
	{
		std::cout << "Incorrect BMP header" << std::endl;
	}
	

	if (header[0] != 'B' || header[1] != 'M') //File always starts with a BM, so check if right
	{
		std::cout << "Incorrect BM in header" << std::endl;
	}

	dataBegin = *(int*)&(header[0x0A]);
	fileSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

		//deal with misformatting data

		if (fileSize == 0) 
		{
			fileSize = width * height * 3; 
		}
		else if (dataBegin == 0)
		{
			dataBegin = 54;
		}
			
		
		
	bmpLoad->width = width;
	bmpLoad->height = height;

	unsigned char* imageData = new unsigned char[fileSize];
	fread(imageData, 1, fileSize, file);

	for (unsigned int i = 0; i < fileSize; i += 3)
	{
		char temp = imageData[i];
		imageData[i] = imageData[i + 2];
		imageData[i + 2] = temp;
	}

	bmpLoad->fileData = imageData;

	fclose(file);
	return bmpLoad;
}