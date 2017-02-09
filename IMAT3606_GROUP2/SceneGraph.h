#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "manager.h"
#include "Message.h"

#include "GameObject.h"

class SceneGraph 
{
public:

	static std::vector<GameObject*>gameObjects; //list of game objects

	static GameObject* getGameObject(int id);

	static int addObject(int x, int y, int z);

	static int idCount;

};


#endif //SCENEGRAPH_H