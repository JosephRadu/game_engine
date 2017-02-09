#ifndef CREATEWINDOWMESSAGE_H
#define CREATEWINDOWMESSAGE_H

#include "Message.h"

class CreateWindowMessage : public Message
{
public:
	int width;
	int height;
	const char* title;
};


#endif //CREATEWINDOWMESSAGE_H