#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H

#include "component.h"


class WindowInterface : public Component
{
public:

private:

	virtual void _createWindow(int width, int height) = 0;

};



#endif //WINDOWINTERFACE_H
