#include "Crosshair.h"

Crosshair::Crosshair(float vertices[], int size) {
	m_vertices = vertices;
	m_size = size;
}

void Crosshair::Initialize() {
	glGenBuffers(1, &m_vboID);
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(float), m_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	m_shader = new Shader(RESOURCES_PATH "shaders/crosshair_vert_shader.vert", RESOURCES_PATH "shaders/crosshair_frag_shader.frag");
	m_shader->use();
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
	m_shader->setMat("projection", glm::value_ptr(projection));
	
}

void Crosshair::Render() {
	
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(m_vaoID);
	m_shader->use();
	glDrawArrays(GL_LINES, 0, 4);

}

