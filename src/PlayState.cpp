#include "PlayState.h"

PlayState::PlayState(std::unique_ptr<World> gameWorld, AccountData::AccountData accountData) : world(std::move(gameWorld)) {
	this->accountData = accountData;
	std::cout << "entering PLAYSTATE" << std::endl;
}

PlayState::~PlayState() {

}

void PlayState::Enter() {
	startTime = SDL_GetTicks();
	soundManager.InitializeSounds();
	canvas.AddTextBox("--", 50.0f, 550.0f, 0.9f, glm::vec3(0.3f, 0.5f, 0.1f), "TIMER");
	canvas.AddTextBox("0", 50.0f, 510.0f, 0.9f, glm::vec3(0.3f, 0.5f, 0.1f), "SCORE");
	canvas.AddTextBox("-", 50.0f, 470.0f, 0.9f, glm::vec3(0.3f, 0.5f, 0.1f), "ACCURACY");
}

GameState* PlayState::HandleInput(SDL_Event& e) {
	if (SDL_GetTicks() > startTime + COUNTDOWN_TIMER) {
		world->HandleInput(e);
		return nullptr;
	}
	return nullptr;
}

GameState* PlayState::ChangeState() {
	if (SDL_GetTicks() - startTime > COUNTDOWN_TIMER + PLAY_TIME) {
		RoundData::RoundStatistics stats = { scoreManager.GetScore(), scoreManager.GetAccuracy()};
		return new GameOverState(stats, accountData);
	}
	return nullptr;
}

void PlayState::Update() {
	if (SDL_GetTicks() > startTime + COUNTDOWN_TIMER) {
		world->Update();
		canvas.UpdateTextString(std::to_string((PLAY_TIME + COUNTDOWN_TIMER + startTime - SDL_GetTicks()) / 1000), "TIMER");
		canvas.UpdateTextString(std::to_string(scoreManager.GetScore()), "SCORE");
		canvas.UpdateTextString(std::to_string(scoreManager.GetAccuracy()), "ACCURACY");
	}
	else {
		canvas.UpdateTextString(std::to_string((COUNTDOWN_TIMER + startTime - SDL_GetTicks()) / 1000), "TIMER");
	}
}

void PlayState::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	world->Render();
	canvas.Render();
	// render UI shit also
}

bool PlayState::QuitGame() {
	return false;
}
