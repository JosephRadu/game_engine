#include "manager.h"

void Manager::init()
{
	for (int i = 0; i < _listComp.size(); ++i)
	{
		_listComp[i]->init();
	}
}

void Manager::update()
{
	Message* msg = _msgBus.pop();
	
	while (msg != nullptr) 
	{
		for(int i = 0; i < _listComp.size(); ++i)
		{
			_listComp[i]->sendMsg(msg);
		}

		msg = _msgBus.pop();
	}


	for (int i = 0; i < _listComp.size(); ++i)
	{
		_listComp[i]->update();
	}
}

void Manager::deInit()
{
	for (int i = 0; i < _listComp.size(); ++i)
	{
		_listComp[i]->deInit();
	}
}

void Manager::addComp(Component* component)
{
	_listComp.push_back(component);
}

void Manager::msgSend(Message* msg)
{
	_msgBus.push(msg);
}
