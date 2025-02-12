#include "UI.h"

UI::UI(float x, float y, float rotation, float scaleX, float scaleY, Shader& shader, GLuint vaoID, Texture& texturePtr) : m_shader(shader), m_texture(texturePtr){
	this->x = x;
	this->y = y;
	this->rotation = rotation;
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	m_vaoID = vaoID;
	
}

void UI::OnClick() {

}

void UI::Render() {
	glActiveTexture(GL_TEXTURE0);
	m_texture.BindTexture();
	m_shader.use();
	m_shader.setInt("tex", 0);
	glm::mat4 p = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(m, glm::vec3(x, y, 0.0f));
	m = glm::scale(m, glm::vec3(scaleX * 100, scaleY * 100, 1.0f));
	m = glm::rotate(m, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	
	m_shader.setMat("model", glm::value_ptr(m));
	m_shader.setMat("projection", glm::value_ptr(p));
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(m_vaoID);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}