#include "Utilities.h"

Manager* Utilities::compManager;



Model* Utilities::loadModel(const char* fileName)
{
	ModelLoader loader;
	return loader.LoadObj(fileName);
}

BMP* Utilities::loadBmp(const char* fileName)
{
	BmpLoader loader;
	return loader.loadBmp(fileName);
}
