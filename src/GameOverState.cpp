#include "GameOverState.h"

GameOverState::GameOverState(RoundData::RoundStatistics stats, AccountData::AccountData accountData) : m_stats(stats), m_exitButtonTexture(RESOURCES_PATH "media/Exit_BTN.png") {
	this->accountData = accountData;
}

void GameOverState::Enter() {
	SendSessionData();
	GetLeaderboard();
	m_cursor.Initialize();
	m_canvas.InitializeUIBuffers();
	m_canvas.AddTextBox("GAME OVER!", 100, 100, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f), "GAMEOVER");
	m_canvas.AddUIBox(300.0f, 300.0f, 0.0f, 1.0f, 1.0f, "EXIT_BUTTON", m_exitButtonTexture);
	m_canvas.AddListener(&m_GOButtonManager);
}

GameState* GameOverState::HandleInput(SDL_Event& e) {
	m_canvas.HandleInput(e);
	if (m_GOButtonManager.ClickedExit) {
		quitGame = true;
	}
	return nullptr;
}

GameState* GameOverState::ChangeState() {
	return nullptr;
}

void GameOverState::Update() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	m_cursor.UpdatePosition(x, y);
}

void GameOverState::Render() {
	m_canvas.Render();
	m_cursor.Render();
}

bool GameOverState::QuitGame() {
	return quitGame;
}

void::GameOverState::SendSessionData() {
	std::string response = HttpHelper::Post("http://localhost:8080/api/sessions", "{\"username\": \"" + accountData.m_username + "\", \"password\": \"" + accountData.m_password + "\", \"score\": \"" + std::to_string(m_stats.m_score) + "\", \"accuracy\": \"" + std::to_string(m_stats.m_accuracy) + "\"}", "application/json");
	std::cout << response << std::endl;
}

void GameOverState::GetLeaderboard() {
	std::string response = HttpHelper::Get("http://localhost:8080/api/leaderboards");
	std::cout << response << std::endl;
}
