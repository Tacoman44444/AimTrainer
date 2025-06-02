#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include "Shader.h"
#include "Model.h"
#include "Target.h"
#include "Camera.h"

class IGameMode {
public:
	virtual glm::vec3 GetNewPosition() = 0;
	virtual glm::vec3 GetNewScale() = 0; 
	//virtual ITargetComponent GetGameModeComponent() = 0;
	virtual void CreateTargetPool(Camera* camera) = 0;
	virtual void InitializeTargets() = 0;
	virtual void HandleInput(SDL_Event& e) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	//virtual std::shared_ptr<Shader> GetShader() = 0;
	//virtual std::shared_ptr<Model> GetModel() = 0;

	virtual ~IGameMode() = default;
};