#ifndef OPENGLRENDER_H
#define OPENGLRENDER_H


#include <Windows.h>
#include "Utilities.h"

#include "CreateModelMessage.h"
#include "RobotGameLogic.h"
#include "GraphicsInterface.h"
#include "BMP.h"
#include "GL.h"
#include "GLU.h"
#include "glext.h"

class OpenGLRender : public GraphicsInterface
{
public:

	void update() override;
	void init() override;
	void deInit() override;
	void sendMsg(Message* msg);

	void render();
	GLuint loadToOpenGL(Model* modelToLoad);
	GLuint loadTexture(BMP* bmpToLoad);

	std::vector<GLuint> openGLModelHandles;
	std::vector<int> positionOfObject;
	std::vector<int> textureIdStore;


private:

	int _winWidth;
	int _winHeight;

	void Projection(int width, int height);
};



#endif //OPENGLRENDER_H