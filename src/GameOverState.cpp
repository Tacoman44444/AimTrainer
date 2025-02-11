#include "GameOverState.h"

GameOverState::GameOverState() {

}

void GameOverState::Enter() {
	canvas.AddTextBox("GAME OVER!", 100, 100, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f), "GAMEOVER");
}

GameState* GameOverState::HandleInput(SDL_Event& e) {
	return nullptr;
}

GameState* GameOverState::ChangeState() {
	return nullptr;
}

void GameOverState::Update() {

}

void GameOverState::Render() {

}