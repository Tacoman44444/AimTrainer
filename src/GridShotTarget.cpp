#include "GridShotTarget.h"

GridShotTarget::GridShotTarget(GameObject* parent) {
	m_parent = parent;
}

int GridShotTarget::ScoreLogic() {
	return 250;
}

bool GridShotTarget::IsHit(glm::vec3 ray) {

	return m_parent->GetComponent<SphereCollider>()->CheckCollision(ray);
}

int& GridShotTarget::Health() {
	return health;
}

void GridShotTarget::HandleInput(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		std::cout << "mouse button is down" << std::endl;
		if (IsHit(m_parent->GetCamLookDirection())) {
			std::cout << "IsHit() is true" << std::endl;
			m_parent->active = false;
			ScoreLogic();
		}
	}
}

void GridShotTarget::Update() {

}