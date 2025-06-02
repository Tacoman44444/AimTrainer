#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "Object.h"
#include "Camera.h"
#include "Transform.h"
#include "Target.h"
#include "Subject.h"
#include "Crosshair.h"
#include "GameObject.h"
#include "AssetManager.h"
#include "TargetPool.h"
#include "GridShot.h"

class World {

public:
	World();
	//World(std::vector<Transform*>& env);
	//World(std::vector<Transform*> env, std::vector<Target*> targetsList);
	~World();

	void Initialize();

	void HandleInput(SDL_Event& e);
	void Update();
	void Render();

private:
	bool pressedDown;

	Camera* camera;
	Crosshair crosshair;

	std::vector<GameObject*> m_gameObjects;
	GridShot gridShot; // later will change this to support any gamemode.
};