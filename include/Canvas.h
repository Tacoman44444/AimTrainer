#pragma once

#include "Text.h"
#include "UI.h"
#include "GameData.h"
#include "ButtonEvent.h"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <string>

class Canvas {
public:
	Canvas();
	void AddTextBox(std::string text, float x, float y, float scale, glm::vec3 colour, std::string id);
	void AddUIBox(float x, float y, float rotation, float scaleX, float scaleY, std::string id);
	void UpdateTextString(std::string text, std::string id);

	void HandleInput(SDL_Event& e);
	void Render();

	void AddListener(ButtonObserver* observer);

	//gonna have the canvas initialize the UI vertex array object for now

	void InitializeUIBuffers();

private:
	std::map<std::string, std::unique_ptr<Text>> m_textObjectsMap;
	std::map<std::string, std::unique_ptr<UI>> m_uiObjectsMap;

	ButtonEvent m_onClickEvent;

	Shader m_textShader;
	Shader m_uiShader;

	Texture TEMP_TEXTURE;

	GLuint m_ui_vaoID;
	GLuint m_ui_vboID;
};