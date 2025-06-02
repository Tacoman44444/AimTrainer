#pragma once
#include "IGameMode.h"
#include "AssetManager.h"
#include "GridShotTarget.h"
#include "TargetPool.h"
#include <random>

class GridShot : IGameMode {
private:
	TargetPool m_targetPool;
	std::vector<std::pair<GameObject*, glm::vec3>> targetsInUse;
	std::uniform_int_distribution<int> distr;
	std::mt19937 gen;

	int GetRandomNumber();

public:
	GridShot();
	~GridShot();
	glm::vec3 GetNewPosition() override;
	glm::vec3 GetNewScale() override;

	void HandleInput(SDL_Event& e) override;
	void Update() override;
	void Render() override;

	void CreateTargetPool(Camera* camera) override;
	void InitializeTargets() override;

};