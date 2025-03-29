#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0), missed(0), shotsTaken(0) { 
	lastPosition = vec3(0, 0, 0);
}

void ScoreManager::OnNotify(const Event& event) {
	shotsTaken++;
	switch (event.type) {
	case TARGET_SHOT: {
		IncreaseScoreScaled(event.targetPosition);
		lastPosition = event.targetPosition;
		break;
	}
	case TARGETS_MISSED: {
		missed++;
		break;
	}
	default: {
		break;
	}
	}

}

void ScoreManager::DEBUG_OUTPUT_SCORE() {
	std::cout << "score: " << score << std::endl;
}

int ScoreManager::GetScore() {
	return score;
}

int ScoreManager::GetMissed() {
	return missed;
}

float ScoreManager::GetAccuracy() {
	if (shotsTaken != 0) {
		std::cout << "SHOTS TAKEN: " << shotsTaken << std::endl;
		std::cout << "MISSED: " << missed << std::endl;
		return ((shotsTaken - missed) / static_cast<float>(shotsTaken)) * 100.0f;
	}
	else {
		return 0;
	}
	
}

void ScoreManager::IncreaseScoreScaled(const vec3& targetPosition) {
	float distanceScaled = (targetPosition - lastPosition).magnitude();
	if (distanceScaled == 0) {
		score += 100;
	}
	else {
		if (distanceScaled < 10) {
			score += (100 - (distanceScaled * 10));
		}
		else {
			score += 0;
		}
	}
}