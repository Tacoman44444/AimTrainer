#pragma once

#include <glad/glad.h>
#include <iostream>
#include "stb_image.h"


class Texture {
public:
	Texture(const char* texturePath);
	void BindTexture();

private:

	GLuint m_textureID;

};