#ifndef COMPONENT_H
#define COMPONENT_H

#include "Message.h"

class Component
{
public:

	virtual void update() = 0;
	virtual void init() = 0;
	virtual void deInit() = 0;

	virtual void sendMsg(Message* msg) = 0;
 
private:

};

#endif //COMPONENT_H