#pragma once

#include <iostream>

class BoxCollider2D {

public:
	BoxCollider2D(float startX, float startY, float endX, float endY);
	bool CheckCollision(float mouseX, float mouseY);

private:
	void DEBUG_LOG(float mouseX, float mouseY, bool result);
	float m_startX, m_startY, m_endX, m_endY;

};