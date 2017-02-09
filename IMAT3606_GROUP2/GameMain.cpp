#include "GameMain.h"
#include <SDL_image.h>

#include <iostream>
#include <string>



void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_QUIT;
}

GameMain::GameMain()
{
	_window = nullptr;
	_renderTarget = nullptr;

	//Hardcoded variables
	_screenWidth = 1024;
	_screenHeight = 768;
	_FPS = 60;
	
	_pigPos_x = 450.0f;
	_pigPos_y = 600.0f;

	deltaTime = 0.0f;
	moveSpeed = 500.0f;
	frameTime = 0.0f;
	prevTime = 0;
	currentTime = 0;

	_gameState = GameState::PLAY;
}

GameMain::~GameMain()
{
}



void GameMain::run() //Add methods into this to be called by Main.
{
	
	initSystems();
	drawGame(); 
	gameLoop();
}



void GameMain::initSystems() //intialise things to be used
{
	
	bool success = true;

	//Initialise SDL
	SDL_Init(SDL_INIT_EVERYTHING); 
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	int imgFlags = (IMG_INIT_JPG | IMG_INIT_PNG);
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}


	_window = SDL_CreateWindow("Game_Engine_Robot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created");
	}

	_renderTarget = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	_screenSurface = SDL_GetWindowSurface(_window);

	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //Tells SDL to double buffer


	//_backGround = new sprite("Layout_idea.png", _screenSurface->format);
	//_mainPig = new sprite("Pig_Sprite_Sheet.png", _screenSurface->format);
	//_rightPig = new sprite("Pig_Right_Stance.png", _screenSurface->format);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	_loadObj = new  ModelLoader;



	

}




void GameMain::gameLoop() //Continous loop waiting for return of processInput()
{
	while (_gameState != GameState::EXIT) {
		processInput();
	}


}


void GameMain::processInput() //Processes inputs and events.
{
	SDL_Event evnt;
	_isRunning = true;
	
	//while (SDL_PollEvent(&evnt)) 
	//{
	//	switch (evnt.type) 
	//	{
	//	
	//	case SDL_QUIT:
	//		_gameState = GameState::EXIT;
	//			break;
	//	 Case statement to outprint mouse position, useful for position objects later.

	//	case SDL_MOUSEMOTION:
	//		std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
	//			break;
	//	
	//	}

	while (_isRunning)
	{
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;

		while (SDL_PollEvent(&evnt) != 0)
		{
			if (evnt.type == SDL_QUIT)
			{
				_gameState = GameState::EXIT;
				_isRunning = false;
			}
		}

		_keyState = SDL_GetKeyboardState(NULL);

		if (_keyState[SDL_SCANCODE_RIGHT])
		{
			_pigPos_x += moveSpeed * deltaTime;
		}

		else if (_keyState[SDL_SCANCODE_LEFT])
		{
			_pigPos_x -= moveSpeed * deltaTime;
		}
			


		drawGame();

	}


}


void GameMain::drawGame()
{
	//sprite::drawSprite(_screenSurface, _backGround->optimizedSprite, 0, 0);
	//sprite::drawSprite(_screenSurface, _mainPig->optimizedSprite, _pigPos_x , _pigPos_y);
	

	SDL_UpdateWindowSurface(_window);

}

void GameMain::close() 
{

}