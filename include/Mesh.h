#pragma once

#include "Shader.h"
#include "Texture.h"
#include <glad/glad.h>
#include <vector>
#include <string>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh {

public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Texture texture);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	GLuint m_vao;
	GLuint m_indexCount;
	Texture m_texture;
	bool isPrimitive;
	void Draw(Shader& shader);

};