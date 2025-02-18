#include "StateManager.h"

StateManager::StateManager(SDL_Window* window) : mWindow(window) {
	currentState = new MainMenuState();
	currentState->Enter();
}

void StateManager::UpdateState(GameState* newState) {
	delete currentState;
	currentState = newState;
	currentState->Enter();
}

void StateManager::ChangeState() {
	GameState* newState = currentState->ChangeState();
	if (newState != nullptr) {
		UpdateState(newState);
	}
}

void StateManager::HandleInput(SDL_Event& e) {
	GameState* newState = currentState->HandleInput(e);
	if (newState != nullptr) {
		UpdateState(newState);
	}
}

void StateManager::Update() {
	currentState->Update();
}

void StateManager::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	currentState->Render();
	SDL_GL_SwapWindow(mWindow);
}

bool StateManager::QuitGame() {
	return currentState->QuitGame();
}