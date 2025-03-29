#include "SoundManager.h"

SoundManager::SoundManager() {

}

bool SoundManager::InitializeSounds() {
	if (!InitializeSound(RESOURCES_PATH "sounds/Gunshot.mp3", "GUNSHOT")) {
		return false;
	}
	return true;
}

void SoundManager::OnNotify(const Event& event) {
	switch (event.type) {
	case TARGET_SHOT:
		Mix_PlayChannel(-1, m_soundChunkMap["GUNSHOT"], 0);
		break;
	}
}

bool SoundManager::InitializeSound(const char* filePath, std::string id) {
	Mix_Chunk* newChunk;
	newChunk = Mix_LoadWAV(filePath);
	if (newChunk == nullptr) {
		std::cout << "failed to load sound effect for <" << id << ">" << " SDL_mixer Error : " << Mix_GetError() << std::endl;
		return false;
	}
	m_soundChunkMap.insert(std::pair(id, newChunk));
	return true;
}