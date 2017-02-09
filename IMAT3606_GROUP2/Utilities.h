#ifndef UTILITIES_H
#define UTILITIES_H

#include "manager.h"
#include "ModelLoader.h"
#include "BmpLoader.h"
#include "Message.h"
#include "Model.h"
#include <iostream>

class Utilities
{
public:
	static Manager* compManager;
	


	static Model* loadModel(const char* fileName);
	static BMP* loadBmp(const char* fileName);


private:


};



#endif //UTILITIES_H