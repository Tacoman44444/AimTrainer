#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <openglErrorReporting.h>
#include "SetupHelper.h"
#include "StateManager.h"
#include "LTimer.h"
#include "FontManager.h"
#undef main

#pragma region imgui
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "imguiThemes.h"
#pragma endregion

const double MS_PER_UPDATE = 10;

void resize_gl_viewport(const SDL_Event& event) {
	if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
		int width = event.window.data1;
		int height = event.window.data2;
		glViewport(0, 0, width, height);
	}
}

int main(int argc, char *argv[])
{

	if (!SetupHelper::InitializeSDL()) {
		std::cout << "SDL initialization failed" << std::endl;
		return 1;
	}
	if (!SetupHelper::InitializeSDLMixer()) {
		std::cout << "Mixer initialization failed" << std::endl;
		return 1;
	}
	SDL_Window* window;
	SetupHelper::CreateSDLWindow(&window);
	SDL_GLContext glContext;
	SetupHelper::CreateGLContext(window, &glContext);
	SetupHelper::LoadGLFunctions();
	FontManager::InitializeFreeType();
	FontManager::InitializeCharacters();

	enableReportGlErrors();

	/*
	Texture containerTexture("C:/Users/justf/source/repos/Aim Trainer/SDL2OpenglCMakeSetup-master/resources/media/container.jpg");

	Object cubeObject(Models::vertices, sizeof(Models::vertices));
	cubeObject.InitializeBuffers();
	cubeObject.InitializeShaders(RESOURCES_PATH "shaders/basic_vert_shader.vert", RESOURCES_PATH "shaders/basic_frag_shader.frag");
	
	Camera camera(glm::vec3(0.0f, 0.0f, -3.0f), 0.1f, 0.01f);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(10.0f, 0.01f, 10.0f));
	model = glm::translate(model, glm::vec3(0.0f, -200.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	cubeObject.SetProjectionMatrix(projection);
	cubeObject.SetTextures();
	*/

	StateManager stateManager(window);
	LTimer timer;
	timer.start();
	double previousTicks = timer.getTicks();
	double lag = 0.0;
	bool quit = false;
	SDL_Event e;

	while (!quit) {
		double currentTicks = timer.getTicks();
		double elapsed = currentTicks - previousTicks;
		previousTicks = currentTicks;
		lag += elapsed;

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_WINDOWEVENT) {
				resize_gl_viewport(e);
				if (e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
					SDL_SetRelativeMouseMode(SDL_TRUE);
				}
			}
			else {
				stateManager.HandleInput(e);
			}

		}

		stateManager.ChangeState();
		stateManager.Update();

		stateManager.Render();	// implement Render(lag / MS_PER_UPDATE) later

	}

	// Cleanup SDL
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
