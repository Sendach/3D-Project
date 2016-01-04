#include "ModelCache.h"
#include <iostream>
void ModelCache::setupModel(const std::string path, const std::string modelName, bool normalMapping)
{
	auto modelIterator = _models.find(modelName);

	if (modelIterator == _models.end())
	{
		Model model;
		std::vector<glm::vec3> out_position, out_normals, tangent, bitangent;
		std::vector<glm::vec2> out_uvs;
	
		model.takeInfo(out_position, out_uvs, out_normals, tangent, bitangent, normalMapping);
		model.setupMesh(path, normalMapping);
		_models.insert(make_pair(modelName, model));
	}
	std::cout << modelName << " Loaded\n";
}

Model& ModelCache::getModel(const std::string modelName)
{
	return _models[modelName];
}
