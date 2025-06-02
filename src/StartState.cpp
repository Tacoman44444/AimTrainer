#include "StartState.h"

StartState::StartState(AccountData::AccountData accountData) {
	this->accountData = accountData;
	world = std::make_unique<World>();
	std::cout << "entering STARTSTATE" << std::endl;
}

StartState::~StartState() {
	//don't delete world !!!
}

void StartState::Enter() {
	world->Initialize();
	m_canvas.AddTextBox("GAY", 400.0f, 580.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f), "GAY");
}

GameState* StartState::HandleInput(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		std::cout << "returned new PLAYSTATE" << std::endl;
		return new PlayState(std::move(world), accountData);
	}
	return nullptr;
}

GameState* StartState::ChangeState() { return nullptr; }

void StartState::Update() {
	
}

void StartState::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	world->Render();
	m_canvas.Render();
	//also render the UI elements here
}

bool StartState::QuitGame() {
	return false;
}



