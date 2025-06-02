#pragma once

#include "Target.h"
#include "SphereCollider.h"
#include "SDL2/SDL.h"
#include "GameObject.h"

class GridShotTarget : public ITargetComponent {
private :
	GameObject* m_parent;
	int health = 0;

public:
	GridShotTarget(GameObject* parent);
	int ScoreLogic() override;
	bool IsHit(glm::vec3 ray) override;
	int& Health() override;
	void HandleInput(SDL_Event& e);
	void Update() override;
};