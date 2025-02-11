#include "UI.h"

UI::UI(float x, float y, float rotation, float scale, Shader& shader, GLuint vaoID, std::shared_ptr<Texture> texturePtr) : m_shader(shader), m_texture(texturePtr){
	this->x = x;
	this->y = y;
	this->rotation = rotation;
	m_vaoID = vaoID;
	m_shader.setInt("texture", 0);
}

void UI::OnClick() {

}

void UI::Render() {

	m_texture->BindTexture();
	m_shader.use();
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(m_vaoID);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}