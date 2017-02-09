#include "ModelLoader.h"



Model* ModelLoader::LoadObj(const char* fileName)
{

	Model* storeLoad = new Model;

	FILE* file = fopen(fileName, "r");

	if (file == NULL)
	{
		std::cout << "Error opening model file" << std::endl;

	}
	else
	{
		while (1)
		{
			char lineResult[256];
			int result = fscanf(file, "%s", lineResult);
			if (result == EOF)
			{
				break;
			}

			if (strcmp(lineResult, "v") == 0)
			{
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				tempVertices.push_back(vertex);
			}
			else if (strcmp(lineResult, "vt") == 0)
			{
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				tempUvs.push_back(uv);
			}
			else if (strcmp(lineResult, "vn") == 0)
			{
				glm::vec3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				tempNormals.push_back(normal);
			}
			else if (strcmp(lineResult, "f") == 0)
			{
				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				if (matches != 9)
				{
					std::cout << "Failed to load file." << std::endl;
					return nullptr;
				}
				
					

				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);

			
				for (unsigned int i = 0; i < vertexIndices.size(); i++)
				{
					unsigned int vertexIndex = vertexIndices[i];
					unsigned int uvIndex = uvIndices[i];
					unsigned int normalIndex = normalIndices[i];

					glm::vec3 vertex = tempVertices[vertexIndex - 1];
					glm::vec2 uv = tempUvs[uvIndex - 1];
					glm::vec3 normal = tempNormals[normalIndex - 1];

					storeLoad->outputVertices.push_back(vertex);
					storeLoad->outputUvs.push_back(uv);
					storeLoad->outputNormals.push_back(normal);

				}
			}
		}
	}
	fclose(file);
	return storeLoad;

}

// %d = decimal integer
// %s = string
// %f = floating point number