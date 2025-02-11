#pragma once

#include "Text.h"
#include "GameData.h"
#include <vector>
#include <memory>
#include <string>

class Canvas {
public:
	Canvas();
	void AddTextBox(std::string text, float x, float y, float scale, glm::vec3 colour, std::string id);
	void AddUIBox();
	void UpdateTextString(std::string text, std::string id);
	void Render();

	//gonna have the canvas initialize the UI vertex array object for now

	void InitializeUIBuffers();

private:
	std::map<std::string, std::unique_ptr<Text>> m_textObjectsMap;
	
	Shader m_textShader;

	GLuint m_ui_vaoID;
	GLuint m_ui_vboID;
};