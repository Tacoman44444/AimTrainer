#include "Cursor.h"

Cursor::Cursor() {
	model = glm::mat4(1.0f);
}

void Cursor::Initialize() {
	glGenBuffers(1, &m_vboID);
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Models::crosshair_vertices), Models::crosshair_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	m_shader = new Shader(RESOURCES_PATH "shaders/cursor_vert_shader.vert", RESOURCES_PATH "shaders/cursor_frag_shader.frag");
	m_shader->use();
	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f);
	m_shader->setMat("projection", glm::value_ptr(projection));
}

void Cursor::UpdatePosition(float x, float y) {
	//std::cout << "(" << x << ", " << y << ")" << std::endl;
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	model = glm::scale(model, glm::vec3(1000.0f, 1000.0f, 1.0f));
	//the problem is that translate doesnt map to the screen coords.
}

void Cursor::Render() {
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(m_vaoID);
	m_shader->use();
	m_shader->setMat("model", glm::value_ptr(model));
	glDrawArrays(GL_LINES, 0, 4);
}