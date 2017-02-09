#include "SdlComp.h"


SdlComp::SdlComp()
{

}



void SdlComp::update()
{

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt) != 0)
	{
		if (evnt.type == SDL_KEYDOWN)
		{
			KeypressMessage* msg = new KeypressMessage;
			msg->MsgId = KEYPRESS_MESSAGE;

			switch (evnt.key.keysym.sym)
			{
			case SDLK_w:
			case SDLK_UP:
				msg->key = 'w';
				break;
			case SDLK_a:
			case SDLK_LEFT:
				msg->key = 'a';
				break;
			case SDLK_s:
			case SDLK_DOWN:
				msg->key = 's';
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				msg->key = 'd';
				break;
		/*	case SDLK_ESCAPE:
				deInit();
				break;
		*/
			}

			Utilities::compManager->msgSend(msg);
		}
		else if (evnt.type == SDL_QUIT)
		{
			deInit();
		}
	}

	SDL_GL_SwapWindow(_window);
}

void SdlComp::init()
{
	//Initialise Everything in SDL and check if failed
	SDL_Init(SDL_INIT_VIDEO);

	if ((SDL_Init(SDL_INIT_VIDEO) == -1))
	{
		std::cout << "SDL failed to initialize:" << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "SdlComp initialized..." << std::endl;
	}

}


void SdlComp::deInit()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}


void SdlComp::_createWindow(int width, int height)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	_window = nullptr;
	_window = SDL_CreateWindow("Robot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (_window == nullptr)
	{
		std::cout << "SDL Window creation has failed:" << SDL_GetError() << std::endl;
	}
	else
	{

		context = SDL_GL_CreateContext(_window);

		if (context == NULL)
		{
			std::cout << "SDL context creation has failed:" << SDL_GetError() << std::endl;
		}
	}
	
	std::cout << "Created Window..." << std::endl;

}

void SdlComp::sendMsg(Message* msg)
{
	switch (msg->MsgId)
	{
	case CREATE_WINDOW_MESSAGE:
		CreateWindowMessage* keyMsg = (CreateWindowMessage*)msg;

		std::cout << "Create Window Message sent:" << keyMsg->width << ", " << keyMsg->height << std::endl;
		_createWindow(keyMsg->width, keyMsg->height);
		break;
	}
}