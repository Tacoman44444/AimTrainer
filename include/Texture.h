#pragma once

#include <glad/glad.h>
#include <iostream>
#include "stb_image.h"

struct Texture {
	GLuint m_textureID;
	GLuint m_width;
	GLuint m_height;

	void Load(const char* filePath);
};

class Tex {
public:
	Tex(const char* texturePath);
	void BindTexture();

private:

	GLuint m_textureID;

};