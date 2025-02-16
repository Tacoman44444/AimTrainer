#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Subject.h"
#include "BoxCollider2D.h"

class UI {
public:
	UI(float x, float y, float rotation, float scaleX, float scaleY, Shader& shader, GLuint vaoID, Texture& texture);
	bool CheckCollision(float mousePosX, float mousePosY);
	void Render();
private:
	Shader m_shader;
	GLuint m_vaoID;
	Texture m_texture;
	BoxCollider2D m_collider;
	float x;
	float y;
	float scaleX;
	float scaleY;
	float rotation;
};