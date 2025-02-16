#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(float startX, float startY, float endX, float endY) {
	m_startX = startX;
	m_startY = startY;
	m_endX = endX;
	m_endY = endY;
}

bool BoxCollider2D::CheckCollision(float mouseX, float mouseY) {
	if (mouseX > m_startX && mouseX < m_endX) {
		if (mouseY > m_startY && mouseY < m_endY) {
			DEBUG_LOG(mouseX, mouseY, true);
			return true;
		}
	}
	DEBUG_LOG(mouseX, mouseY, false);
	return false;
}

void BoxCollider2D::DEBUG_LOG(float mouseX, float mouseY, bool result) {
	std::cout << "-----------------" << std::endl;
	std::cout << "BOX COLLIDER DIMENSIONS" << std::endl;
	std::cout << "bottom left coordinates: (" << m_startX << ", " << m_startY << ")" << std::endl;
	std::cout << "top right coordinates: (" << m_endX << ", " << m_endY << ")" << std::endl;
	std::cout << "mouse coordinates: (" << mouseX << ", " << mouseY << ")" << std::endl;
	std::cout << "CHECK COLLISION RESULT" << std::endl;
	std::cout << result << std::endl;
	std::cout << "-----------------" << std::endl;

}