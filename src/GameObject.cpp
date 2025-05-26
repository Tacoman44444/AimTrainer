#include "GameObject.h"

GameObject::GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader) {
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
	m_model = model;
	m_shader = shader;
}

void GameObject::Draw() {
	m_shader->use();
	glm::mat4 model = GetModelMatrix();
	m_shader->setMat("model", glm::value_ptr(model));
	m_model->Draw(*m_shader);
}

void GameObject::SetPosition(glm::vec3& position) {
	m_position = position;
}

void GameObject::SetRotation(glm::vec3& rotation) {
	m_rotation = rotation;
}

void GameObject::SetScale(glm::vec3& scale) {
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