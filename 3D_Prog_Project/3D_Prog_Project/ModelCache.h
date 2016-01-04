#ifndef MODELCACHE_H
#define MODELCACHE_H

#include "Model.h"

#include <string>
#include <map>
class ModelCache
{
public:
	void setupModel(const std::string path, const std::string modelName, bool normalMapping);
	Model& getModel(const std::string modelName);
private:
	std::map<std::string, Model> _models;

};
#endif
