#pragma once

#include "Shader.h"
#include "Texture.h"

class UI {
public:
	UI(float x, float y, float rotation, float scaleX, float scaleY, Shader& shader, GLuint vaoID, Texture& texture);
	void OnClick();
	void Render();
private:
	Shader m_shader;
	GLuint m_vaoID;
	Texture m_texture;
	float x;
	float y;
	float scaleX;
	float scaleY;
	float rotation;
};