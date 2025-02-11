#pragma once

#include <glad/glad.h>
#include "Shader.h"
#include "GameData.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object {
public:
	Object(float vertices[], int size);
	void InitializeShaders(const char* vertShaderPath, const char* fragShaderPath);
	void InitializeBuffers();
	void SetTextures();
	void BindObject();
	void DrawObject(glm::mat4& projectionMatrix, glm::mat4& viewMatrix, glm::mat4& modelMatrix);
	void DrawObject(glm::mat4& modelMatrix);


	void SetProjectionMatrix(glm::mat4& projectionMatrix);
	void SetViewMatrix(glm::mat4& viewMatrix);
	void SetModelMatrix(glm::mat4& modelMatrix);

private:

	float* m_vertices;
	GLuint m_vaoID;
	GLuint m_vboID;
	Shader* m_shader;
	int m_size;
};