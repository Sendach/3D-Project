#include "OBJ_Loader.h"

#include <fstream>
#include <iostream>

bool OBJ_Loader::loadOBJ(std::string path, std::vector<glm::vec3>& out_position, std::vector<glm::vec3>& out_normals, std::vector<glm::vec2>& out_uvs)
{
	std::ifstream file;
	file.open(path);
	
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	if (file.is_open())
	{
		std::string word;
		while (file >> word)
		{
			
			if (word == "v")
			{
				glm::vec3 vertex;
				file >> vertex.x >> vertex.y >> vertex.z;
				vertex = glm::vec3(vertex.x, vertex.y, vertex.z);
				temp_vertices.push_back(vertex);
			}
			else if (word == "vt")
			{
				glm::vec2 uv;
				file >> uv.x >> uv.y;
				uv = glm::vec2(uv.x, uv.y);
				temp_uvs.push_back(uv);
			}
			else if (word == "vn")
			{
				glm::vec3 normal;
				file >> normal.x >> normal.y >> normal.z;
				normal = glm::vec3(normal.x, normal.y, normal.z);
				temp_normals.push_back(normal);
			}
			else if (word == "f")
			{
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				std::string line;
				std::getline(file, line);
				std::size_t prevX = 0;


				for (int i = 0; i < 3; i++)
				{
					std::size_t x = line.find('/', prevX + 1);
					vertexIndex[i] = atoi(line.substr(prevX + 1, x).c_str());
					prevX = x;
					x = line.find('/', prevX + 1);
					uvIndex[i] = atoi(line.substr(prevX + 1, x).c_str());
					prevX = x;
					x = line.find(' ', prevX + 1);
					normalIndex[i] = atoi(line.substr(prevX + 1, x).c_str());
					prevX = x;

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
			}
			else if (word == "faces")
			{
				break;
			}
		}

	}
	else {
		std::cout << "Failed to load File: " << path << std::endl;
		return false;
	}

	for (unsigned int i = 0; i < vertexIndices.size(); i++)
	{
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		glm::vec3 vertex = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec2 uv = glm::vec2(0.0f, 0.0f);
		glm::vec3 normal = glm::vec3(0.0f, 0.0f, 0.0f);

		if (temp_vertices.size() != 0)
		{
			vertex = temp_vertices[vertexIndex - 1];
		}
		if (temp_uvs.size() != 0)
		{
			uv = temp_uvs[uvIndex - 1];
		}
		if (temp_normals.size() != 0)
		{
			normal = temp_normals[normalIndex - 1];
		}

		

		out_position.push_back(vertex);
		out_uvs.push_back(uv);
		out_normals.push_back(normal);


	}

	return true;
}
