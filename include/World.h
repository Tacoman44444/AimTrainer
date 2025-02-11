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

class World {

public:
	World();
	World(std::vector<Transform*>& env);
	World(std::vector<Transform*> env, std::vector<Target*> targetsList);
	~World();

	void Initialize();

	void HandleInput(SDL_Event& e);
	void Update();
	void Render();

	Subject& TargetShot();

private:
	bool pressedDown;

	std::vector<Transform*> environment;
	std::vector<Target*> targets;
	Object* bufferTemplate;
	Camera* camera;
	Texture* envTexture;
	Texture* targetTexture;
	Subject targetShotEvent;
	Crosshair crosshair;

	void InitializeTargets();
	void InitializeEnvironment();
};