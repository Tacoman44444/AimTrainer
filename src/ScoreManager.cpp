#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0), missed(0) { }

void ScoreManager::OnNotify(Event event) {
	switch (event) {
	case TARGET_SHOT:
		score++;

	case TARGETS_MISSED:
		missed++;
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