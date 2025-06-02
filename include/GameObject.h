#pragma once

#include "Model.h"
#include "Mesh.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <typeindex>
#include <IComponent.h>

class GameObject {
public:

    bool active = false;

    GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Camera* camera);

    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
    std::shared_ptr<Model> m_model;
    std::shared_ptr<Shader> m_shader;

    void HandleInput(SDL_Event& e);
    void Update();
    void Draw();
    void SetPosition(const glm::vec3& position);
    void SetRotation(const glm::vec3& rotation);
    void SetScale(const glm::vec3& scale);
    glm::mat4 GetModelMatrix() const;
    glm::vec3 GetCamLookDirection() const;

    template <typename T>
    void AddComponent(std::shared_ptr<T> component) {
        m_components[std::type_index(typeid(T))] = component;
    }

    template <typename T>
    std::shared_ptr<T> GetComponent() {

        std::cout << "GetComponent called on this: " << this << std::endl;
        std::cout << "m_components size: " << m_components.size() << std::endl;

        auto it = m_components.find(std::type_index(typeid(T)));
        if (it != m_components.end()) {
            return std::dynamic_pointer_cast<T>(it->second);
        }
        std::cout << "GetComponent returned null ptr" << std::endl;
        return nullptr;
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_components;
    Camera* m_camera;

};