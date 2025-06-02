#include "GridShot.h"

GridShot::GridShot() {
	std::random_device rd;
	gen = std::mt19937(rd());
	distr = std::uniform_int_distribution<int>(1, 16);
	
}

GridShot::~GridShot() {
	m_targetPool.DeletePool();
}

int GridShot::GetRandomNumber() {
	return distr(gen);
}

glm::vec3 GridShot::GetNewPosition() {
	while (true) {
		int rand = GetRandomNumber();
		int row = (rand - 1) / 4;
		int col = (rand - 1) % 4;

		float x = col - 1.5f;
		float y = 1.5f - row;
		float z = -10.0f;
		glm::vec3 vec = glm::vec3(x, y, z);
		auto it = std::find_if(targetsInUse.begin(), targetsInUse.end(),
			[&vec](const std::pair<GameObject*, glm::vec3>& pair) {
				return pair.second == vec;
			});
		if (it == targetsInUse.end()) {
			return glm::vec3(x, y, z);
		}
	}
}

glm::vec3 GridShot::GetNewScale() {
	return glm::vec3(1.0f, 1.0f, 1.0f);
}


void GridShot::HandleInput(SDL_Event& e) {
	for (auto& obj : targetsInUse) {
		obj.first->HandleInput(e);
	}
}

void GridShot::Update() {
	bool targetDeleted = false;
	for (auto it = targetsInUse.begin(); it != targetsInUse.end(); ) {
		if (!it->first->active) {
			it = targetsInUse.erase(it);
			targetDeleted = true;
		}
		else {
			it->first->Update();
			++it;
		}
	}
	if (targetDeleted) {
		glm::vec3 newPos = GetNewPosition();
		GameObject* obj = m_targetPool.SpawnTarget(newPos, glm::vec3(0.0f, 0.0f, 0.0f), GetNewScale());
		targetsInUse.push_back(std::make_pair(obj, newPos));
	}
}

void GridShot::Render() {
	for (auto& obj : targetsInUse) {
		obj.first->Draw();
	}
}

void GridShot::CreateTargetPool(Camera* camera) {
	std::vector<GameObject*> targetPool;
	for (int i = 0; i < 5; i++) {
		GameObject* obj = new GameObject(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), AssetManager::GetModel("sphere_default"), AssetManager::GetShader("shader_default_unlit"), camera);
		std::shared_ptr<GridShotTarget> gridShotTarget = std::make_shared<GridShotTarget>(obj);
		std::shared_ptr<SphereCollider> sphereCollider = std::make_shared<SphereCollider>(obj, 0.5f, glm::vec3(0.0f, 0.0f, 0.0f));
		obj->AddComponent<GridShotTarget>(gridShotTarget);
		obj->AddComponent<SphereCollider>(sphereCollider);
		targetPool.push_back(obj);
	}
	m_targetPool.CreatePool(std::move(targetPool));
}

void GridShot::InitializeTargets() {
	for (int i = 0; i < 3; i++) {
		glm::vec3 newPos = GetNewPosition();
		GameObject* obj = m_targetPool.SpawnTarget(newPos, glm::vec3(0.0f, 0.0f, 0.0f), GetNewScale());
		if (obj == nullptr) {
			std::cout << "what the null pointer?" << std::endl;
		}
		targetsInUse.push_back(std::make_pair(obj, newPos));
	}

}