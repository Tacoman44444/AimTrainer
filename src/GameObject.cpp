#include "GameObject.h"

GameObject::GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Camera* camera) {
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
	m_model = model;
	m_shader = shader;
	m_camera = camera;
}

void GameObject::HandleInput(SDL_Event& e) {
	for (const auto& pair : m_components) {
		pair.second->HandleInput(e);
	}
}

void GameObject::Update() {
	for (const auto& pair : m_components) {
		pair.second->Update();
	}
}

void GameObject::Draw() {
	if (active) {
		m_shader->use();
		glm::mat4 model = GetModelMatrix();
		m_shader->setMat("model", glm::value_ptr(model));
		m_model->Draw(*m_shader);
	}
	else {
		std::cout << "inactive!!" << std::endl;
	}
}

void GameObject::SetPosition(const glm::vec3& position) {
	m_position = position;
}

void GameObject::SetRotation(const glm::vec3& rotation) {
	m_rotation = rotation;
}

void GameObject::SetScale(const glm::vec3& scale) {
	m_scale = scale;
}

glm::mat4 GameObject::GetModelMatrix() const {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, m_position);
	model = glm::rotate(model, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, m_scale);
	return model;
}

glm::vec3 GameObject::GetCamLookDirection() const {
	vec3 lookDir = m_camera->GetLookDirection();
	return glm::vec3(lookDir.X, lookDir.Y, lookDir.Z);
}