#pragma once

#include "GameState.h"
#include "PlayState.h"
#include "World.h"
#include <SDL2/SDL.h>
#include <memory>
#include "Canvas.h"

class StartState : public GameState {
public:

	StartState();
	~StartState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;

private:

	std::unique_ptr<World> world;
	Canvas m_canvas;

};