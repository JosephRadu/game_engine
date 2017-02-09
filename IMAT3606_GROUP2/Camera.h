//#ifndef CAMERA_H;
//#define CAMERA_H;
//
//#include <iostream>
//#include "glm\glm.hpp"
//#include <vector>
//#include <windef.h>
//
//class Camera
//{
//public:
//
//	Camera();
//	Camera(glm::vec3 passUp, glm::vec3 passView, glm::vec3 passEye, float passSpeed, float passMouseSensi);
//
//	glm::vec3 up;
//	glm::vec3 view; 
//	glm::vec3 eye;
//
//	float speed;
//	float mouseSensi;
//	float angleX(), angleY();
//
//	void mouseRotate();
//	void update();
//	void resetMouse();
//
//	glm::mat4 lookView();
//
//private:
//	POINT _cur;
//	int posForw, posBack, posLeft, posRight;
//
//};
//
//#endif //CAMERA_H;