#ifndef LIGHT_H
#define LIGHT_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>
//Soil
#include <SOIL\SOIL.h>
//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//SFML
#include <SFML/Graphics.hpp>
//Class Includes
#include "Scene.h"
//Other Includes
#include <vector>
#include <memory>
#include <string>
#include "ResourceManager.h"

class Light
{
public:
	Light(){}
	Light(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	~Light(){}
	void update(Camera& camera, std::string shader);
	void draw(std::string model);
	void setLightPosition(glm::vec3 lightPos);
	glm::vec3 getLightPosition();
	void setLightColor(glm::vec3 lightColor);
	glm::vec3 getLightColor();
	
private:
	glm::vec3 lightPosition;
	glm::vec3 lightColor;
	std::shared_ptr<ResourceManager> resource;

};
#endif

