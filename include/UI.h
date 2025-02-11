#pragma once

#include "Shader.h"
#include "Texture.h"

class UI {
public:
	UI(float x, float y, float rotation, float scale, Shader& shader, GLuint vaoID, std::shared_ptr<Texture> texturePtr);
	void OnClick();
	void Render();
private:
	Shader m_shader;
	GLuint m_vaoID;
	std::shared_ptr<Texture> m_texture;
	float x;
	float y;
	float scale;
	float rotation;
};