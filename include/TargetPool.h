#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"

class TargetPool {
public:
	TargetPool();
	void CreatePool(std::vector<GameObject*>&& pool);
	void DeletePool();
	GameObject* SpawnTarget(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale);

private:
	std::vector<GameObject*> m_pool;
};