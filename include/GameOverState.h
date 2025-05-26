#pragma once

#include "GameState.h"
#include "Canvas.h"
#include "GOButtonManager.h"
#include "Cursor.h"
#include "HttpHelper.h"

//eventually, gameoverstate will need to be passed a struct containing player performance data.

class GameOverState : public GameState {

public:

	GameOverState(RoundData::RoundStatistics stats, AccountData::AccountData accountData);
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;
	bool QuitGame() override;

private:
	bool quitGame = false;
	AccountData::AccountData accountData;
	Canvas m_canvas;
	GOButtonManager m_GOButtonManager;
	Cursor m_cursor;
	RoundData::RoundStatistics m_stats;
	Tex m_exitButtonTexture;

	void SendSessionData();
	void GetLeaderboard();
};