#pragma once 

#include "Observer.h"

class SoundManager : public Observer {
public:
	SoundManager();
	void OnNotify(Event event) override;

private:

};