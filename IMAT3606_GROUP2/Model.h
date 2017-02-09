#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <fstream>
#include <glm\glm.hpp>
#include <vector>

class Model
{
public:
	std::vector <glm::vec3> outputVertices;
	std::vector <glm::vec2> outputUvs;
	std::vector <glm::vec3> outputNormals;

};


#endif //MODEL_H