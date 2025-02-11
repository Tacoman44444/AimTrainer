#pragma once

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include "Shader.h"
#include "Texture.h"
#include "Object.h"
#include "GameData.h"
#include "Camera.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>

namespace SetupHelper {

	inline bool InitializeSDL() {
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return false;
		}
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);		
		return true;
	}

	inline bool CreateSDLWindow(SDL_Window** window) {
		SDL_Window* win = SDL_CreateWindow("bullshitin", 100, 100, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC);
		if (win == nullptr) {
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return 1;
		}
		*window = win;
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}

	inline bool CreateGLContext(SDL_Window* window, SDL_GLContext* glContext) {
		SDL_GLContext context = SDL_GL_CreateContext(window);
		if (context == nullptr) {
			std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			return 1;
		}
		*glContext = context;
	}

	inline bool LoadGLFunctions() {
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
			std::cerr << "Failed to initialize GLAD" << std::endl;
			//SDL_GL_DeleteContext(glContext);
			//SDL_DestroyWindow(window);
			SDL_Quit();
			return 1;
		}
		glViewport(0, 0, 800, 600);
	}
}