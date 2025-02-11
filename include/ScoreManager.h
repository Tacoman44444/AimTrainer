#pragma once

#include "Observer.h"
#include <iostream>

class ScoreManager : public Observer {
public:
	ScoreManager();
	void OnNotify(Event event) override;

	void DEBUG_OUTPUT_SCORE();
	int GetScore();

private:
	int score;
};