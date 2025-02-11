 #pragma once

#include "Object.h"
#include "AABB.h"
#include "vec3.h"
#include "HelperFunctions.h"
#include <vector>

class Target {
public:

	static std::vector<glm::vec3> Target::targetPositions;
	bool isDestroyed;

	Target(Object& type, const glm::vec3& vec);

	void Render();

	bool OnMouseClick(const vec3& rayOrigin, const vec3& camDirection); //checks collision
	Target* clone();
	void destroy();
	glm::vec3 getTargetPosition();

private:

	Object& bufferType;
	AABB collisionBox;

	glm::mat4 modelMatrix;
	glm::vec3 mPosition;
};