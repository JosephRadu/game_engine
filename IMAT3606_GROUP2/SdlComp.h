#ifndef SDLCOMP_H
#define SDLCOMP_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

#include "Utilities.h"
#include "WindowInterface.h"
#include "KeypressMessage.h"
#include "CreateWindowMessage.h"


class SdlComp : public WindowInterface
{
public:
	SdlComp();

	void update() override;
	void init() override;
	void deInit() override;
	void sendMsg(Message* msg);

	SDL_GLContext context;

private:
	void _createWindow(int width, int height);

	SDL_Window* _window;

	

	bool _isRunning;


};


#endif //SDLCOMP_H

