#include "SphereCollider.h"

SphereCollider::SphereCollider(GameObject* parent, float radius, glm::vec3 center){
	m_parent = parent;
	m_radius = radius;
	m_center = parent->m_position;
}

bool SphereCollider::CheckCollision(glm::vec3 ray) {
	m_center = m_parent->m_position;
	glm::vec3 L = -m_center;
	float a = 1;
	float b = 2 * glm::dot(ray, L);
	float c = glm::dot(L, L) - m_radius * m_radius;

	float discriminant = b * b - 4 * a * c;
	return discriminant > 0;
}

void SphereCollider::Update() {
	m_center = m_parent->m_position;
}

void SphereCollider::HandleInput(SDL_Event& e) {

}