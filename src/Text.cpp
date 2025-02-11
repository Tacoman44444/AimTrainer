#include "Text.h"

Text::Text(std::string text, Shader& s, float x, float y, float scale, glm::vec3 colour) : m_shader(s){
	m_text = text;
	this->x = x;
	this->y = y;
	this->scale = scale;
	m_colour = colour;
}

void Text::InitializeBuffers() {
	glGenVertexArrays(1,& m_vaoID);
	glGenBuffers(1, &m_vboID);
	glBindVertexArray(m_vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Text::UpdateString(std::string text) {
	m_text = text;
}

void Text::RenderText(glm::mat4 projectionMatrix) {
	//std::cout << "DEBUG: RENDERING TEXT" << std::endl;
	float x_temp = x;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m_shader.use();
	m_shader.setMat("projection", glm::value_ptr(projectionMatrix));
	glUniform3f(glGetUniformLocation(m_shader.ID, "textColor"), m_colour.x, m_colour.y, m_colour.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(m_vaoID);

	std::string::const_iterator c;
	for (c = m_text.begin(); c != m_text.end(); c++) {
		Character ch = FontManager::g_characters[*c];

		float xPos = x_temp + ch.m_bearing.x * scale;
		float yPos = y - (ch.m_Size.y - ch.m_bearing.y) * scale;

		float w = ch.m_Size.x * scale;
		float h = ch.m_Size.y * scale;

		float vertices[6][4] = {
			{xPos, yPos + h, 0.0f, 0.0f},
			{xPos, yPos, 0.0f, 1.0f},
			{xPos + w, yPos, 1.0f, 1.0f},
			{xPos, yPos + h, 0.0f, 0.0f},
			{xPos + w, yPos, 1.0f, 1.0f},
			{xPos + w, yPos + h, 1.0f, 0.0f}
		};
		glBindTexture(GL_TEXTURE_2D, ch.m_textureID); //there is prolly no need to setInt() the texture here.....
		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		x_temp += (ch.m_advance >> 6) * scale;
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}