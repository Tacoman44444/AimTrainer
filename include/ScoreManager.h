#pragma once

#include "Observer.h"
#include <iostream>

class ScoreManager : public Observer {
public:
	ScoreManager();
	void OnNotify(const Event& event) override;

	void DEBUG_OUTPUT_SCORE();
	int GetScore();
	int GetMissed();
	float GetAccuracy();
	void IncreaseScoreScaled(const vec3& targetPosition);

private:
	int score;
	int shotsTaken;
	int missed;
	vec3 lastPosition;
};