#include "MMButtonManager.h"

MMButtonManager::MMButtonManager() {
	ClickedExit = false;
	ClickedPlay = false;
}

void MMButtonManager::OnNotify(std::string id) {
	if (id == "MM_PLAY_BUTTON") {
		ClickedPlay = true;
	}
	else if (id == "MM_EXIT_BUTTON") {
		ClickedExit = true;
	}
}