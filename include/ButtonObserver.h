#pragma once

#include <string>

class ButtonObserver {
public:
	virtual ~ButtonObserver();
	virtual void OnNotify(std::string buttonID) = 0;
};