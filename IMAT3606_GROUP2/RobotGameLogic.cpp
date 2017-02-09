#include "RobotGameLogic.h"


void RobotGameLogic::update() 
{
	
}

void RobotGameLogic::init()
{

////////////////////////-Create Window-//////////////////////////////////////

	CreateWindowMessage* winMsg = new CreateWindowMessage;
	winMsg->MsgId = CREATE_WINDOW_MESSAGE;
	winMsg->width = 1024;
	winMsg->height = 768;
	Utilities::compManager->msgSend(winMsg);




////////////////////////-Create Object's with Id's-//////////////////////////

	robotId = SceneGraph::addObject(0.0f, -3.0f, -300.0f);
	crateId = SceneGraph::addObject(5.0f, -2.0f, -20.0f);
	crateId2 = SceneGraph::addObject(7.0f, -2.0f, -17.0f);
	crateId3 = SceneGraph::addObject(-7.0f, -2.0f, -20.0f);
	crateId4 = SceneGraph::addObject(-1.0f, -2.0f, -13.0f);
	//skyboxId = SceneGraph::addObject(0.0f, 0.0f,-20.0f);


	
////////////////////////-Create model's with obj's-//////////////////////////

	Model* robotModel = Utilities::loadModel("robot.obj");
	Model* crateModel= Utilities::loadModel("crate.obj");
	Model* crateModel2 = Utilities::loadModel("crate.obj");
	Model* crateModel3 = Utilities::loadModel("crate.obj");
	Model* crateModel4 = Utilities::loadModel("crate.obj");
	//Model* skyboxModel = Utilities::loadModel("skybox.obj");


////////////////////////-Load .bmp files/////////////////////////////////////

	BMP* robotText = Utilities::loadBmp("robotMetal.bmp");
	BMP* crateText = Utilities::loadBmp("woodCrate.bmp");
	//BMP* skyboxText = Utilities::loadBmp("skybox.bmp");




////////////////////////-Create Robot-///////////////////////////////////////

	CreateModelMessage* mdlMsg = new CreateModelMessage;
	mdlMsg->MsgId = CREATE_MODEL_MESSAGE;
	mdlMsg->modelMsg = robotModel;
	mdlMsg->gameObjectId = robotId;
	mdlMsg->bmpMsg = robotText;
	Utilities::compManager->msgSend(mdlMsg);

	GameObject* robotGameObject = SceneGraph::getGameObject(robotId);
	robotGameObject->rotY = 1.0f;





////////////////////////-Create Crate's-///////////////////////////////////////

	CreateModelMessage* mdlMsg2 = new CreateModelMessage;
	mdlMsg2->MsgId = CREATE_MODEL_MESSAGE;
	mdlMsg2->modelMsg = crateModel;
	mdlMsg2->gameObjectId = crateId;
	mdlMsg2->bmpMsg = crateText;
	Utilities::compManager->msgSend(mdlMsg2);

	CreateModelMessage* mdlMsg4 = new CreateModelMessage;
	mdlMsg4->MsgId = CREATE_MODEL_MESSAGE;
	mdlMsg4->modelMsg = crateModel2;
	mdlMsg4->gameObjectId = crateId2;
	mdlMsg4->bmpMsg = crateText;
	Utilities::compManager->msgSend(mdlMsg4);

	CreateModelMessage* mdlMsg5 = new CreateModelMessage;
	mdlMsg5->MsgId = CREATE_MODEL_MESSAGE;
	mdlMsg5->modelMsg = crateModel3;
	mdlMsg5->gameObjectId = crateId3;
	mdlMsg5->bmpMsg = crateText;
	Utilities::compManager->msgSend(mdlMsg5);

	CreateModelMessage* mdlMsg6 = new CreateModelMessage;
	mdlMsg6->MsgId = CREATE_MODEL_MESSAGE;
	mdlMsg6->modelMsg = crateModel4;
	mdlMsg6->gameObjectId = crateId4;
	mdlMsg6->bmpMsg = crateText;
	Utilities::compManager->msgSend(mdlMsg6);



////////////////////////-Create Skybox-//////////////////////////////////////

	//CreateModelMessage* mdlMsg3 = new CreateModelMessage;
	//mdlMsg3->MsgId = CREATE_MODEL_MESSAGE;
	//mdlMsg3->modelMsg = skyboxModel;
	//mdlMsg3->gameObjectId = skyboxId;
	////mdlMsg3->bmpMsg = skyboxText;
	//Utilities::compManager->msgSend(mdlMsg3);

	//SkyBox was incomplete


	std::cout << "RobotGameLogic Initialised..." << std::endl;
}

void RobotGameLogic::deInit()
{
}

void RobotGameLogic::sendMsg(Message* msg)
{
	switch (msg->MsgId)
	{
		case KEYPRESS_MESSAGE:
			KeypressMessage* keyMsg = (KeypressMessage*)msg;

				switch (keyMsg->key)
				{
				case 'w':
				{
					GameObject* robotGameObject = SceneGraph::getGameObject(robotId);
					robotGameObject->posX += sin(PI / 180 * robotGameObject->RotA) * 2;
					robotGameObject->posZ += cos(PI / 180 * robotGameObject->RotA) * 2;
				}
					break;
				case 'a':
				{
					GameObject* robotGameObject = SceneGraph::getGameObject(robotId);
					robotGameObject->RotA += 25.0f;
				}
					break;
				case 's':
				{
					GameObject* robotGameObject = SceneGraph::getGameObject(robotId);
					robotGameObject->posX -= sin(PI / 180 * robotGameObject->RotA) * 2;
					robotGameObject->posZ -= cos(PI / 180 * robotGameObject->RotA) * 2;
				}
					break;
				case 'd':
				{
					GameObject* robotGameObject = SceneGraph::getGameObject(robotId);
					robotGameObject->RotA -= 25.0f;
				}
					break;

				}
		
			break;
	}
}