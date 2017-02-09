#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "Model.h"
#include <iostream>
#include <fstream>
#include <glm\glm.hpp>
#include <vector>



class ModelLoader {

public:

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec2> tempUvs;
	std::vector<glm::vec3> tempNormals;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;


	Model* LoadObj(const char* fileName);
};