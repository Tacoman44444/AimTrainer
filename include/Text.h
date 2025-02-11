#pragma once

#include <string>
#include "Shader.h"
#include "FontManager.h"

class Text {
public:

	Text(std::string text, Shader& s, float x, float y, float scale, glm::vec3 colour);
	void InitializeBuffers();
	void UpdateString(std::string text);
	void RenderText(glm::mat4 projectionMatrix);

private:

	std::string m_text;
	Shader m_shader;
	GLuint m_vaoID;
	GLuint m_vboID;
	float x;
	float y;
	float scale;
	glm::vec3 m_colour;
};