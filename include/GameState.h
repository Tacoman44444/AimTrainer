#pragma once

#include <SDL2/SDL.h>

class GameState {

public:
	virtual ~GameState() = default;
	virtual void Enter() = 0;
	virtual GameState* HandleInput(SDL_Event& e) = 0;
	virtual GameState* ChangeState() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool QuitGame() = 0;
};