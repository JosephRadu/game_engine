#include "OpenGLRender.h"


void OpenGLRender::update()
{
	Projection(_winWidth, _winHeight);
	render();
}

void OpenGLRender::init()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);

	std::cout << "OpenGLRender initialised..." << std::endl;
}

void OpenGLRender::deInit()
{
	for (int i = 0; i < openGLModelHandles.size(); ++i) 
	{
		glDeleteLists(openGLModelHandles[i], 1);
	}
}

void OpenGLRender::sendMsg(Message* msg)
{
	switch (msg->MsgId)
	{
	
		case CREATE_WINDOW_MESSAGE:
		{
			CreateWindowMessage* winMsg = (CreateWindowMessage*)msg;
			_winWidth = winMsg->width;
			_winHeight = winMsg->height;
		}
		break;
	
		case CREATE_MODEL_MESSAGE:
		{
			CreateModelMessage* mdlMsg = (CreateModelMessage*)msg;
			GLuint openGLModelHandle = loadToOpenGL(mdlMsg->modelMsg);
			positionOfObject.push_back(mdlMsg->gameObjectId);
			
			if (mdlMsg->bmpMsg == nullptr)
			{
				textureIdStore.push_back(-1);
			}
			else
			{
				GLuint openTexture = loadTexture(mdlMsg->bmpMsg);
				textureIdStore.push_back(openTexture);
			}
			openGLModelHandles.push_back(openGLModelHandle);
		}
		break;

	

	}
}

void OpenGLRender::Projection(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(52.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void OpenGLRender::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//switch (glGetError())
	//{
	//case GL_INVALID_OPERATION:
	//	std::cout << "GL_INVALID_OPERATION" << std::endl;
	//	break;

	//case GL_INVALID_VALUE:
	//		std::cout << "GL_INVALID_VALUE" << std::endl;
	//		break;

	//case GL_INVALID_ENUM:
	//	std::cout << "GL_INVALID_ENUM" << std::endl;
	//	break;
	//}


	
	glLoadIdentity();


	glPushMatrix();								// put current matrix on stack
		
	for (int i = 0; i < openGLModelHandles.size(); ++i) 
	{
		int gameObjectId = positionOfObject[i];
		GameObject* gameObject = SceneGraph::getGameObject(gameObjectId);
		glLoadIdentity();							// reset matrix
		glTranslatef(gameObject->posX, gameObject->posY, gameObject->posZ);
		glRotatef(gameObject->RotA,gameObject->rotX, gameObject->rotY, gameObject->rotZ);			// rotate 
		if (textureIdStore[i] != -1)
		{
			glBindTexture(GL_TEXTURE_2D, textureIdStore[i]);

		}
		glCallList(openGLModelHandles[i]);
	}

	glPopMatrix();

}

GLuint OpenGLRender::loadToOpenGL(Model* modelToLoad)
{
	GLuint list = glGenLists(1);


	glNewList(list, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	
	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 1, 0); //test loader with basic triangle
	//glVertex3f(1, 0, 0);

	
	for(int i = 0; i < modelToLoad->outputVertices.size(); i += 3)
	{
		glTexCoord2f(modelToLoad->outputUvs[i].x, modelToLoad->outputUvs[i].y);
		glVertex3f(modelToLoad->outputVertices[i].x, modelToLoad->outputVertices[i].y, modelToLoad->outputVertices[i].z);
		glTexCoord2f(modelToLoad->outputUvs[i + 1].x, modelToLoad->outputUvs[i + 1].y);
		glVertex3f(modelToLoad->outputVertices[i + 1].x, modelToLoad->outputVertices[i + 1].y, modelToLoad->outputVertices[i + 1].z);
		glTexCoord2f(modelToLoad->outputUvs[i + 2].x, modelToLoad->outputUvs[i + 2].y);
		glVertex3f(modelToLoad->outputVertices[i + 2].x, modelToLoad->outputVertices[i + 2].y, modelToLoad->outputVertices[i + 2].z);
	}
	
	glEnd();

	glEndList();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);

	return list;
	
}

GLuint OpenGLRender::loadTexture(BMP* bmpToLoad)
{

	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpToLoad->width, bmpToLoad->height, 0, GL_RGB, GL_UNSIGNED_BYTE, bmpToLoad->fileData);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	return textureId;
}
