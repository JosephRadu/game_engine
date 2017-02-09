#ifndef CREATEMODELMESSAGE_H
#define CREATEMODELMESSAGE_H

#include "Model.h"
#include "BMP.h"
#include "Message.h"

class CreateModelMessage : public Message
{
public:
	CreateModelMessage()
	{
		modelMsg = nullptr;
		bmpMsg = nullptr;
		gameObjectId = -1;
	}

	Model* modelMsg;
	BMP* bmpMsg;


	int gameObjectId;



};

#endif //CREATEMODELMESSAGE_H