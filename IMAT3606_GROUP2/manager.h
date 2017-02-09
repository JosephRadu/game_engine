#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "component.h"
#include "MessageBus.h"

class Manager 
{
public:

	void init();

	void update();

	void deInit();
	
	void addComp(Component* component);

	void msgSend(Message* msg);



private:

	std::vector<Component*> _listComp;
	
	MessageBus _msgBus;

};

#endif //MANAGER_H