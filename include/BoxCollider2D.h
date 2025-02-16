#pragma once



class BoxCollider2D {

public:
	BoxCollider2D(int startX, int startY, int endX, int endY);
	bool CheckCollision(float mouseX, float mouseY);

private:
	float m_startX, m_startY, m_endX, m_endY;

};