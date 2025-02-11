#pragma once

#include "GameState.h"
#include "GameOverState.h"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Transform.h"
#include "World.h"
#include "ScoreManager.h"
#include "Canvas.h"

class PlayState : public GameState {

public:

	const Uint32 COUNTDOWN_TIMER = 5000; //5 seconds
	const Uint32 PLAY_TIME = 60000; //one minute

	PlayState(std::unique_ptr<World> gameWorld);
	~PlayState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;

private:
	std::unique_ptr<World> world;
	Uint32 startTime;
	ScoreManager scoreManager;
	Canvas canvas;
};