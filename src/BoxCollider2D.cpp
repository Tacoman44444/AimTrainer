#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(int startX, int startY, int endX, int endY) {
	m_startX = startX;
	m_startY = startY;
	m_endX = endX;
	m_endY = endY;
}

bool BoxCollider2D::CheckCollision(float mouseX, float mouseY) {
	if (mouseX > m_startX && mouseX < m_endX) {
		if (mouseY > m_startY && mouseY < m_endY) {
			return true;
		}
	}

	return false;
}