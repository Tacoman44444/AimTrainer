#include "MainMenuState.h"

MainMenuState::MainMenuState() {
	std::cout << "entering 'main menu' state" << std::endl;
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::Enter() {
	m_canvas.AddTextBox("AIM LABS", 300.0f, 500.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f), "TITLE");
}

GameState* MainMenuState::HandleInput(SDL_Event& e) {
	//std::cout << "entered MainMenuState::HandleInput" << std::endl;
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_SPACE) {
			return new StartState();
		}
	}
	return nullptr;
}

GameState* MainMenuState::ChangeState() {
	return nullptr;
}

void MainMenuState::Update() {

}

void MainMenuState::Render() {
	m_canvas.Render();
}