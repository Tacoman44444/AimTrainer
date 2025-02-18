#pragma once

#include "GameState.h"
#include "StartState.h"
#include "Canvas.h"
#include "MMButtonManager.h"
#include "Cursor.h"
#include "BoxCollider2D_test.h"

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
	bool quitGame = false;
	Canvas m_canvas;
	MMButtonManager m_MMButtonManager;
	Cursor m_cursor;
};