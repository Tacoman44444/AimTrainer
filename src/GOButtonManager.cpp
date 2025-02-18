#include "GOButtonManager.h"

GOButtonManager::GOButtonManager() {
	ClickedExit = false;
	ClickedRestart = false;
}

void GOButtonManager::OnNotify(std::string id) {
	if (id == "EXIT_BUTTON") {
		ClickedExit = true;
	}
	else if (id == "RESTART_BUTTON") {
		ClickedRestart = true;
	}
}