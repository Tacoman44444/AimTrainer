#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <openglErrorReporting.h>
#include "CurlManager.h"
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
	CurlManager curlInit;

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
				if (stateManager.QuitGame()) {
					quit = true;
				}
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
