#include "PlayState.h"

PlayState::PlayState(std::unique_ptr<World> gameWorld) : world(std::move(gameWorld)) {
	std::cout << "entering PLAYSTATE" << std::endl;
}

PlayState::~PlayState() {

}

void PlayState::Enter() {
	startTime = SDL_GetTicks();
	world->TargetShot().AddObserver(&scoreManager);
	canvas.AddTextBox("--", 50.0f, 550.0f, 0.9f, glm::vec3(0.3f, 0.5f, 0.1f), "TIMER");
	canvas.AddTextBox("0", 50.0f, 510.0f, 0.9f, glm::vec3(0.3f, 0.5f, 0.1f), "SCORE");
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
		return new GameOverState();
	}
	return nullptr;
}

void PlayState::Update() {
	if (SDL_GetTicks() > startTime + COUNTDOWN_TIMER) {
		world->Update();
		canvas.UpdateTextString(std::to_string((PLAY_TIME + COUNTDOWN_TIMER + startTime - SDL_GetTicks()) / 1000), "TIMER");
		canvas.UpdateTextString(std::to_string(scoreManager.GetScore()), "SCORE");
	}
	else {
		canvas.UpdateTextString(std::to_string((COUNTDOWN_TIMER + startTime - SDL_GetTicks()) / 1000), "TIMER");
	}
}

void PlayState::Render() {
	world->Render();
	canvas.Render();
	// render UI shit also
}

