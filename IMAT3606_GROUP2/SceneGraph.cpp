#include "SceneGraph.h"

int SceneGraph::idCount = 0;
std::vector<GameObject*> SceneGraph::gameObjects;

int SceneGraph::addObject(int x, int y, int z)
{

	GameObject* gameObject = new GameObject;
	gameObjects.push_back(gameObject);
	gameObject->id = idCount;
	idCount = idCount + 1;
	gameObject->posX = x;
	gameObject->posY = y;
	gameObject->posZ = z;
	return gameObject->id;
}

GameObject* SceneGraph::getGameObject(int id)
{
	 
	return gameObjects[id];

}

