#include "TransformObjects.h"

void TransformObjects::transform(glm::mat4 & model, glm::vec3 & position, glm::vec3 & rotation, float angle, glm::vec3 & scale)
{
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, rotation);
	model = glm::scale(model, scale);
}
