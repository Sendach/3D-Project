#ifndef TRANSFORMOBJECTS_H
#define TRANSFORMOBJECTS_H

//GLM
#include <glm/gtc/matrix_transform.hpp>

class TransformObjects
{
public:
public:
	TransformObjects() {}
	void transform(glm::mat4& model, glm::vec3& position, glm::vec3& rotation, float angle, glm::vec3& scale);
};
#endif