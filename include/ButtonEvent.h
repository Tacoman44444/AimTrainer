#pragma once

#include "ButtonObserver.h"
#include <vector>

class ButtonEvent {
public:
	ButtonEvent();

	void AddObserver(ButtonObserver* oberserver);
	void RemoveObserver(ButtonObserver* observer);
	void Notify(std::string buttonID);

private:
	std::vector<ButtonObserver*> m_observers;
};