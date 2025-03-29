#include "World.h"

World::World() : crosshair(Crosshair(Models::crosshair_vertices, sizeof(Models::crosshair_vertices))) {
	pressedDown = false;
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 0.1f, 0.01f);
	envTexture = new Texture(RESOURCES_PATH "media/wall_texture.png");
	targetTexture = new Texture(RESOURCES_PATH "media/target.jpg");

	//temporary creation of an env
	InitializeEnvironment();
	
}

World::World(std::vector<Transform*>& env) : environment(env), crosshair(Crosshair(Models::crosshair_vertices, sizeof(Models::crosshair_vertices))) {
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 0.1f, 0.01f);
}

World::World(std::vector<Transform*> env, std::vector<Target*> targetList) : environment(env), targets(targetList), crosshair(Crosshair(Models::crosshair_vertices, sizeof(Models::crosshair_vertices))) {

}

World::~World() {
	for (Target* target : targets) {
		delete target;
	}
	targets.clear();
	for (Transform* env : environment) {
		delete env;
	}
	environment.clear();
}

void World::Initialize() {
	bufferTemplate = new Object(Models::vertices, sizeof(Models::vertices));
	bufferTemplate->InitializeBuffers();
	bufferTemplate->InitializeShaders(RESOURCES_PATH "shaders/basic_vert_shader.vert", RESOURCES_PATH "shaders/basic_frag_shader.frag");
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	bufferTemplate->SetProjectionMatrix(projection);
	bufferTemplate->SetTextures();

	if (targets.empty()) {
		InitializeTargets();
	}

	crosshair.Initialize();

}

void World::HandleInput(SDL_Event& e) {
	int x, y;
	if (e.type == SDL_MOUSEMOTION) {
		x = e.motion.xrel;
		y = e.motion.yrel;
		camera->Look(static_cast<float>(x), static_cast<float>(y));
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		bool targetHit = false;
		if (!pressedDown) {
			for (Target* target : targets) {
				if (target->OnMouseClick(camera->GetPosition(), camera->GetLookDirection())) {
					targetShotEvent.Notify(Event {TARGET_SHOT, target->getTargetPosition_vec3()});
					targets.push_back(target->clone());
					target->destroy();
					targetHit = true;
					break;
				}
			}
			if (!targetHit) {
				targetShotEvent.Notify(Event {TARGETS_MISSED, vec3(0, 0, 0)});
			}
		}
		pressedDown = true;
	}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		pressedDown = false;
	}
}

void World::Update() {
	int numTargets = targets.size();
	for (int i = numTargets - 1; i >= 0; i--) {
		if (targets[i]->isDestroyed) {
			std::cout << "Deleting something\n";
			delete targets[i];
			targets.erase(targets.begin() + i);
		}

	}
}

void World::Render() {
	glEnable(GL_DEPTH_TEST);
	bufferTemplate->SetViewMatrix(camera->GetViewMatrix());
	glActiveTexture(GL_TEXTURE0);
	envTexture->BindTexture();
	bufferTemplate->BindObject();
	for (Transform* env : environment) {
		bufferTemplate->DrawObject(env->m_modelMatrix);
	}

	glActiveTexture(GL_TEXTURE0);
	targetTexture->BindTexture();
	for (Target* target : targets) {
		target->Render();
	}

	crosshair.Render();
}

void World::InitializeTargets() {
	int newPosition = HelperFunctions::GenerateRandomNumber(0, Target::targetPositions.size());
	std::cout << "random number (init): " << newPosition << std::endl;
	Target* newTarget = new Target(*bufferTemplate, Target::targetPositions[newPosition]);
	Target::targetPositions.erase(Target::targetPositions.begin() + newPosition);
	targets.push_back(newTarget);
	targets.push_back(newTarget->clone());
	targets.push_back(newTarget->clone());
}

void World::InitializeEnvironment() {
	glm::mat4 model1 = glm::mat4(1.0f);
	model1 = glm::translate(model1, glm::vec3(0.0f, 0.2f, 0.0f));
	model1 = glm::scale(model1, glm::vec3(100.0f, 100.0f, 100.0f));
	Transform* newEnv1 = new Transform(model1);
	environment.push_back(newEnv1);

}

Subject& World::TargetShot() {
	return targetShotEvent;
}