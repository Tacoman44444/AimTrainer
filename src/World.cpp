#include "World.h"


World::World() : crosshair(Crosshair(Models::crosshair_vertices, sizeof(Models::crosshair_vertices))) {
	pressedDown = false;
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 0.1f, 0.01f);
}

/*
World::World(std::vector<Transform*>& env) : crosshair(Crosshair(Models::crosshair_vertices, sizeof(Models::crosshair_vertices))) {
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 0.1f, 0.01f);
}
*/



World::~World() {

}

void World::Initialize() {

	/*
	GameObject obj = GameObject(glm::vec3(3.0f, 5.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), AssetManager::GetModel("sphere_default"), AssetManager::GetShader("shader_default_unlit"), camera);
	m_gameObjects.push_back(obj);
	obj = GameObject(glm::vec3(-3.0f, 5.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), AssetManager::GetModel("sphere_default"), AssetManager::GetShader("shader_default_unlit"), camera);
	m_gameObjects.push_back(obj);
	*/
	
	crosshair.Initialize();
	gridShot.CreateTargetPool(camera);
	gridShot.InitializeTargets();
}

void World::HandleInput(SDL_Event& e) {
	int x, y;
	if (e.type == SDL_MOUSEMOTION) {
		x = e.motion.xrel;
		y = e.motion.yrel;
		camera->Look(static_cast<float>(x), static_cast<float>(y));
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		pressedDown = true;
	}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		pressedDown = false;
	}
	gridShot.HandleInput(e);
}

void World::Update() {
	gridShot.Update();
}

void World::Render() {
	
	glEnable(GL_DEPTH_TEST);

	AssetManager::SetShaderViewProjMat(camera->GetViewMatrix(), glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f));
	
	for (GameObject* obj : m_gameObjects) {
		obj->Draw();
	}
	gridShot.Render();
	crosshair.Render();
}