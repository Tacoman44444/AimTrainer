#include "AssetManager.h"

void AssetManager::AddModel(std::string name, std::shared_ptr<Model> model) {
	g_models.insert(std::make_pair(name, model));
}

void AssetManager::AddShader(std::string name, std::shared_ptr<Shader> shader) {
	g_shaders.insert(std::make_pair(name, shader));
}

void AssetManager::SetShaderViewProjMat(glm::mat4& view, glm::mat4& proj) {
	for (const auto& pair : g_shaders) {
		pair.second->use();
		pair.second->setMat("view", glm::value_ptr(view));
		pair.second->setMat("projection", glm::value_ptr(proj));
	}
}

std::shared_ptr<Model> AssetManager::GetModel(std::string name) {
	return g_models[name];
}

std::shared_ptr<Shader> AssetManager::GetShader(std::string name) {
	return g_shaders[name];
}