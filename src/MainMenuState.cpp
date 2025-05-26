#include "MainMenuState.h"

MainMenuState::MainMenuState() : m_logoTexture(RESOURCES_PATH "media/logo.jpg"), m_playButtonTexture(RESOURCES_PATH "media/Play_BTN.jpg") {
	std::cout << "entering 'main menu' state" << std::endl;
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::Enter() {
	m_canvas.InitializeUIBuffers();
	m_canvas.AddUIBox(0.0f, 100.0f, 0.0f, 8.0f, 5.0f, "LOGO", m_logoTexture);
	m_canvas.AddTextBox("ENTER USERNAME:", 0.0f, 75.0f, 0.5, glm::vec3(0.0f, 0.0f, 0.0f), "CREDENTIALS");
	m_canvas.AddUIBox(350.0f, 10.0f, 0.0f, 1.0f, 0.5f, "MM_PLAY_BUTTON", m_playButtonTexture);
	m_canvas.AddListener(&m_MMButtonManager);
	m_cursor.Initialize();

	AssetManager::AddModel("sphere_default", std::make_shared<Model>(PRIMITIVE_SPHERE, 1.0f));
	AssetManager::AddShader("shader_default_unlit", std::make_shared<Shader>(RESOURCES_PATH "shaders/sphere_vert_shader.vert", RESOURCES_PATH "shaders/sphere_frag_shader.frag"));
}

GameState* MainMenuState::HandleInput(SDL_Event& e) {

	if (enteringUsername) {
		handleUsernameInput(e);
	}
	else if (enteringPassword) {
		handlePasswordInput(e);
	}

	

	if (!enteringUsername && !enteringPassword) {
		m_canvas.HandleInput(e);
		if (m_MMButtonManager.ClickedPlay) {
			std::string response = HttpHelper::Post("http://localhost:8080/api/users", "{\"username\": \"" + accountData.m_username + "\", \"password\": \"" + accountData.m_password + "\"}", "application/json");
			std::cout << response << std::endl;
			std::cout << "Username: " << accountData.m_username << std::endl;
			std::cout << "Password: " << accountData.m_password << std::endl;
			return new StartState(accountData);
		}
	}

	return nullptr;
}

GameState* MainMenuState::ChangeState() {
	return nullptr;
}

void MainMenuState::Update() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	m_cursor.UpdatePosition(x, y);
}

void MainMenuState::Render() {
	m_canvas.Render();
	m_cursor.Render();
}

bool MainMenuState::QuitGame() {
	return quitGame;
}

void MainMenuState::handleUsernameInput(SDL_Event& e) {

	if (enteringUsername) {
		if (e.type == SDL_TEXTINPUT && accountData.m_username.size() < 16 && e.key.keysym.sym != SDLK_SPACE) {
			accountData.m_username += e.text.text;
			m_canvas.UpdateTextString("ENTER USERNAME: " + accountData.m_username, "CREDENTIALS");
		}
		else if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_BACKSPACE && !accountData.m_username.empty()) {
				accountData.m_username.pop_back();
				m_canvas.UpdateTextString("ENTER USERNAME: " + accountData.m_username, "CREDENTIALS");
			}
			else if (e.key.keysym.sym == SDLK_RETURN && !accountData.m_username.empty()) {
				enteringUsername = false;
				enteringPassword = true;
				m_canvas.UpdateTextString("ENTER PASSWORD: ", "CREDENTIALS");
			}
		}
	}
	
}

void MainMenuState::handlePasswordInput(SDL_Event& e) {

	if (enteringPassword) {
		if (e.type == SDL_TEXTINPUT) {
			accountData.m_password += e.text.text;
			m_canvas.UpdateTextString("ENTER PASSWORD: " + accountData.m_password, "CREDENTIALS");
		}
		else if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_BACKSPACE && !accountData.m_password.empty()) {
				accountData.m_password.pop_back();
				m_canvas.UpdateTextString("ENTER PASSWORD: " + accountData.m_password, "CREDENTIALS");
			}
			else if (e.key.keysym.sym == SDLK_RETURN && !accountData.m_password.empty()) {
				enteringPassword = false;
				m_canvas.UpdateTextString("PRESS PLAY!", "CREDENTIALS");
			}
		}
	}
}
