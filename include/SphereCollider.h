#pragma once

#include "IComponent.h"
#include "GameObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class SphereCollider : public IComponent {
public:
	SphereCollider(GameObject* parent, float radius, glm::vec3 center);
	bool CheckCollision(glm::vec3 ray);
	void Update() override;
	void HandleInput(SDL_Event& e);

private:
	GameObject* m_parent;
	float m_radius;
	glm::vec3 m_center;

};