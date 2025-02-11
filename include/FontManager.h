#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <iostream>

struct Character {
	GLuint m_textureID;
	glm::ivec2 m_Size;
	glm::ivec2 m_bearing;
	unsigned int m_advance;
};

namespace FontManager {
	inline FT_Library ft;
	inline FT_Face face;
	inline std::map <char, Character> g_characters;
	bool InitializeFreeType();
	void InitializeCharacters();
}