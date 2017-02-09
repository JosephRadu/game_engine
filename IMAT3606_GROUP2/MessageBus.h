#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <queue>

#include "Message.h"

class MessageBus
{
public:

	void push(Message* msg);
	Message* pop();

private:
	
	std::queue<Message*> _listMsg;

};


#endif //MESSAGEBUS_H
