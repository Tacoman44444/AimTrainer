#pragma once

#include "ButtonObserver.h"

class GOButtonManager : public ButtonObserver {
public:
	GOButtonManager();
	void OnNotify(std::string id);
	bool ClickedExit;
	bool ClickedRestart;
};