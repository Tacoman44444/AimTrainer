#include "Object.h"

Object::Object(float vertices[], int size) {
	m_vertices = vertices;
	m_size = size;
}

void Object::InitializeShaders(const char* vertShaderPath, const char* fragShaderPath) {
	m_shader = new Shader(vertShaderPath, fragShaderPath);
}

void Object::InitializeBuffers() {
	glGenBuffers(1, &m_vboID);
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(float), m_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glEnable(GL_DEPTH_TEST);
}

void Object::SetTextures() {
	m_shader->use();
	m_shader->setInt("texture1", 0);
}

void Object::BindObject() {
	glBindVertexArray(m_vaoID);
}

void Object::DrawObject(glm::mat4& projectionMatrix, glm::mat4& viewMatrix, glm::mat4& modelMatrix) {
	glEnable(GL_DEPTH_TEST);
	m_shader->use();

	//m_shader->setMat("projection", glm::value_ptr(projectionMatrix));
	m_shader->setMat("view", glm::value_ptr(viewMatrix));
	m_shader->setMat("model", glm::value_ptr(modelMatrix));

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Object::DrawObject(glm::mat4& modelMatrix) {
	glEnable(GL_DEPTH_TEST);

	m_shader->use();
	m_shader->setMat("model", glm::value_ptr(modelMatrix));

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Object::SetProjectionMatrix(glm::mat4& projectionMatrix) {
	m_shader->use();
	m_shader->setMat("projection", glm::value_ptr(projectionMatrix));
}

void Object::SetViewMatrix(glm::mat4& viewMatrix) {
	m_shader->use();
	m_shader->setMat("view", glm::value_ptr(viewMatrix));
}

void Object::SetModelMatrix(glm::mat4& modelMatrix) {
	m_shader->setMat("model", glm::value_ptr(modelMatrix));
}