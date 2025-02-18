#include "Canvas.h"

Canvas::Canvas() : 
	m_textShader(RESOURCES_PATH "shaders/text_vert_shader.vert", RESOURCES_PATH "shaders/text_frag_shader.frag"),  
	m_uiShader(RESOURCES_PATH "shaders/ui_vert_shader.vert", RESOURCES_PATH "shaders/ui_frag_shader.frag"),
	TEMP_TEXTURE(RESOURCES_PATH "media/play_button.jpg")
{

}
void Canvas::AddTextBox(std::string text, float x, float y, float scale, glm::vec3 colour, std::string id) {
	std::unique_ptr<Text> textBox = std::make_unique<Text>(text, m_textShader, x, y, scale, colour);
	textBox->InitializeBuffers();
	m_textObjectsMap.insert(std::pair(id, std::move(textBox)));
}

void Canvas::AddUIBox(float x, float y, float rotation, float scaleX, float scaleY, std::string id) {
	std::unique_ptr<UI> uiBox = std::make_unique<UI>(x, y, rotation, scaleX, scaleY, m_uiShader, m_ui_vaoID, TEMP_TEXTURE);
	m_uiObjectsMap.insert(std::pair(id, std::move(uiBox)));
}

void Canvas::UpdateTextString(std::string text, std::string id) {
	m_textObjectsMap[id]->UpdateString(text);
}

void Canvas::HandleInput(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		for (const auto& [key, value] : m_uiObjectsMap) {
			if (value->CheckCollision(float(x), float(y))) {
				m_onClickEvent.Notify(key);
			}
		}
	}
	
}

void Canvas::Render() {
	for (const auto& [key, value] : m_textObjectsMap) {
		value->RenderText(glm::ortho(0.0f, 800.0f, 0.0f, 600.0f));
	}
	for (const auto& [key, value] : m_uiObjectsMap) {
		value->Render();
	}
}

void Canvas::AddListener(ButtonObserver* observer) {
	m_onClickEvent.AddObserver(observer);
}

void Canvas::InitializeUIBuffers() {
	glGenBuffers(1, &m_ui_vboID);
	glGenVertexArrays(1, &m_ui_vaoID);
	glBindVertexArray(m_ui_vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, m_ui_vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Models::ui_vertices), Models::ui_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glEnable(GL_DEPTH_TEST);

}