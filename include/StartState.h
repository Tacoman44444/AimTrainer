#pragma once

#include "GameState.h"
#include "PlayState.h"
#include "World.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <memory>
#include "Canvas.h"

class StartState : public GameState {
public:

	StartState(AccountData::AccountData accountData);
	~StartState();
	void Enter() override;
	GameState* HandleInput(SDL_Event& e) override;
	GameState* ChangeState() override;
	void Update() override;
	void Render() override;
	bool QuitGame() override;

private:

	AccountData::AccountData accountData;
	std::unique_ptr<World> world;
	Canvas m_canvas;

};