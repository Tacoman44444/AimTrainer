#pragma once

#include "GameState.h"
#include "GameOverState.h"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Transform.h"
#include "World.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "Canvas.h"

class PlayState : public GameState {

public:

	const Uint32 COUNTDOWN_TIMER = 5000; //5 seconds
	const Uint32 PLAY_TIME = 60000; //one minute

	PlayState(std::unique_ptr<World> gameWorld, AccountData::AccountData accountData);
	~PlayState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;
	bool QuitGame() override;

private:
	std::unique_ptr<World> world;
	AccountData::AccountData accountData;
	Uint32 startTime;
	ScoreManager scoreManager;
	SoundManager soundManager;
	Canvas canvas;
};