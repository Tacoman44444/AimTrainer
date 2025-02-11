#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {

public:
	Transform(const glm::mat4& modelMatrix);
	glm::mat4 m_modelMatrix;

};