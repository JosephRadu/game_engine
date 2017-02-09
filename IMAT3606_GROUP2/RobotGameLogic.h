#ifndef ROBOTGAMELOGIC_H
#define ROBOTGAMELOGIC_H

#define PI 3.14159
#define TWO_PI PI*2.0
#define HALF_PI PI/2.0


#include "GameLogicInterface.h"
#include "CreateWindowMessage.h"
#include "CreateModelMessage.h"
#include "KeypressMessage.h"
#include <iostream>
#include "Utilities.h"
#include "SceneGraph.h"

class RobotGameLogic : public GameLogicInterface
{
public:

	void update() override;
	void init() override;
	void deInit() override;
	void sendMsg(Message* msg);

	float a = 0.0f , x = 0.0f, y = 0.0f, z = 0.0f;

	int robotId;
	int crateId, crateId2, crateId3, crateId4;
	int skyboxId;

private:
	
};

#endif //ROBOTGAMELOGIC_H