#pragma once

#include "GameState.h"
#include "Canvas.h"
#include "GOButtonManager.h"
#include "Cursor.h"

//eventually, gameoverstate will need to be passed a struct containing player performance data.

class GameOverState : public GameState {

public:

	GameOverState(RoundData::RoundStatistics stats);
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;
	bool QuitGame() override;

private:
	bool quitGame = false;
	Canvas m_canvas;
	GOButtonManager m_GOButtonManager;
	Cursor m_cursor;
	RoundData::RoundStatistics m_stats;
};