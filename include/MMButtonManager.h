#pragma once

#include "ButtonObserver.h"

class MMButtonManager : public ButtonObserver {
public:
	MMButtonManager();
	void OnNotify(std::string id);
	bool ClickedPlay, ClickedExit;
};