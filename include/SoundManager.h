#pragma once 

#include "Observer.h"
#include <SDL_mixer.h>
#include <map>
#include <string>
#include <iostream>

class SoundManager : public Observer {
public:
	SoundManager();
	bool InitializeSounds();
	void OnNotify(Event event) override;

private:
	bool InitializeSound(const char* filePath, std::string id);
	std::map<std::string, Mix_Chunk*> m_soundChunkMap;
};