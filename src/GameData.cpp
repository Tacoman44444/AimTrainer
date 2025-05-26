#include "GameData.h"

RoundData::RoundStatistics::RoundStatistics() : m_score(0), m_accuracy(0.0f) {}

RoundData::RoundStatistics::RoundStatistics(int score, float accuracy) : m_score(score), m_accuracy(accuracy) {}