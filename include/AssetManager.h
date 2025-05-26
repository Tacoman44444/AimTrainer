#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Model.h"

namespace AssetManager {
	static std::unordered_map<std::string, std::shared_ptr<Model>> g_models;
	static std::unordered_map<std::string, std::shared_ptr<Shader>> g_shaders;

	void AddModel(std::string name, std::shared_ptr<Model>);
	void AddShader(std::string name, std::shared_ptr<Shader>);

	std::shared_ptr<Model> GetModel(std::string name);
	std::shared_ptr<Shader> GetShader(std::string name);

	void SetShaderViewProjMat(glm::mat4& view, glm::mat4& projection);
}