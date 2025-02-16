#pragma once

#include <glad/glad.h>
#include "Shader.h"
#include "GameData.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cursor {
public:
	Cursor();
	void Initialize();
	void UpdatePosition(float x, float y);
	void Render();

private:
	GLuint m_vboID;
	GLuint m_vaoID;
	Shader* m_shader;
	glm::mat4 model;
};