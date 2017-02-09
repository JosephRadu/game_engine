#include "MessageBus.h"


void MessageBus::push(Message* msg)
{
	_listMsg.push(msg);
}

Message* MessageBus::pop()
{
	if (_listMsg.empty())
	{
		return nullptr;
	}

	Message* msg = _listMsg.front();
	_listMsg.pop();
	return msg;
}