#pragma once

#include "GameState.h"
#include "StartState.h"
#include "Canvas.h"
#include "MMButtonManager.h"
#include "Cursor.h"
#include "BoxCollider2D_test.h"
#include "HttpHelper.h"

class MainMenuState : public GameState {

public:
	MainMenuState();
	~MainMenuState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;
	bool QuitGame() override;

private:
	std::string username;
	std::string password;
	bool quitGame = false;
	bool enteringUsername = true;
	bool enteringPassword = false;
	Canvas m_canvas;
	MMButtonManager m_MMButtonManager;
	Cursor m_cursor;
	Texture m_logoTexture;
	Texture m_playButtonTexture;

	void handleUsernameInput(SDL_Event& e);
	void handlePasswordInput(SDL_Event& e);
};