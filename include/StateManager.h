#pragma once

#include "GameState.h"
#include "MainMenuState.h"

class StateManager {
public:

	StateManager(SDL_Window* window);
	void UpdateState(GameState* newState);
	void ChangeState();
	void HandleInput(SDL_Event& e);
	void Update();
	void Render();

private:

	GameState* currentState;
	SDL_Window* mWindow;
};