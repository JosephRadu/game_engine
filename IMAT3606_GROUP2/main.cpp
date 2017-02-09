#include <iostream>
#include <stdio.h>
#include "manager.h"
#include "RobotGameLogic.h"
#include "utilities.h"
#include "SdlComp.h"
#include "OpenGLRender.h"




int main(int argc, char** agrv)
{
	/*
	GameMain gameMain;
	gameMain.run();
	*/

	

	Utilities::compManager = new Manager;
	Utilities::compManager->addComp(new RobotGameLogic);
	Utilities::compManager->addComp(new OpenGLRender);
	Utilities::compManager->addComp(new SdlComp);
	
	

	Utilities::compManager->init();

	while (1)
	{
		Utilities::compManager->update();
	}

	Utilities::compManager->deInit();
	

	return 0;
}