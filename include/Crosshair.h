#pragma once

#include <glad/glad.h>
#include "Shader.h"
#include "GameData.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Crosshair {
public:
	Crosshair(float vertices[], int size);
	void Initialize();

	void Render();

private:

	float* m_vertices;
	GLuint m_vaoID;
	GLuint m_vboID;
	Shader* m_shader;
	int m_size;
};