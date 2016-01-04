#include "TextureCache.h"

void TextureCache::setupTexture(const GLchar* path, const std::string textureName)
{
	auto textureIterator = _textures.find(textureName);

	if (textureIterator == _textures.end())
	{
		Texture texture;
		texture.loadTexture(path);

		_textures.insert(make_pair(textureName, texture));
	}
}

Texture TextureCache::getTexture(const std::string textureName)
{
	return _textures[textureName];
}