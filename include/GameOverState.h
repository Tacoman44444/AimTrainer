#pragma once

#include "GameState.h"
#include "Canvas.h"

//eventually, gameoverstate will need to be passed a struct containing player performance data.

class GameOverState : public GameState {

public:

	GameOverState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;

private:
	Canvas canvas;
};