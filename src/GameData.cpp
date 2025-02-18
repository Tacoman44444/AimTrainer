#include "GameData.h"

RoundData::RoundStatistics::RoundStatistics() : m_score(0), m_misses(0) {}

RoundData::RoundStatistics::RoundStatistics(int score, int misses) : m_score(score), m_misses(misses) {}

float RoundData::Accuracy(RoundStatistics stats) {
	return stats.m_score / stats.m_misses;
}