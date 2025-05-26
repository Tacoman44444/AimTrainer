#pragma once
#include <vector>
#include "Shader.h"
#include "Mesh.h"

enum Primitives {
	PRIMITIVE_SPHERE,
	PRIMITIVE_CUBE,
};

class Model {
public:
	std::vector<Mesh> m_meshes;
	Model(const char* filePath);
	Model(Primitives primitive, float radius);
	void Load(const char* filePath);
	void Load(Primitives primitive, float radius);
	void Draw(Shader& shader);
};

Mesh loadSphereMesh(float radius, int sectorCount, int stackCount);