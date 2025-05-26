#pragma once

#include "Model.h"
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <typeindex>

class GameObject {
public:
    GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader);

    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
    std::shared_ptr<Model> m_model;
    std::shared_ptr<Shader> m_shader;

    void Draw();
    void SetPosition(glm::vec3& position);
    void SetRotation(glm::vec3& rotation);
    void SetScale(glm::vec3& scale);
    glm::mat4 GetModelMatrix() const;

private:
    //std::unordered_map<std::type_index, std::shared_ptr<IComponent>> components;

};