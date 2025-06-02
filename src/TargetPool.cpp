#include "TargetPool.h"

TargetPool::TargetPool() {
}

void TargetPool::CreatePool(std::vector<GameObject*>&& pool) {
	m_pool = std::move(pool);
}

void TargetPool::DeletePool() {
	for (auto it : m_pool) {
		delete it;
	}
}

GameObject* TargetPool::SpawnTarget(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) {

	if (m_pool.empty()) {
		std::cout << "Object pool has not been initialized" << std::endl;
		return nullptr;
	}

	for (auto obj : m_pool) {
		if (!obj->active) {
			obj->SetPosition(position);
			obj->SetRotation(rotation);
			obj->SetScale(scale);
			obj->active = true;
			return obj;
		}
	}
}