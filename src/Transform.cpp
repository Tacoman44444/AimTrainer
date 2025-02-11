#include "Transform.h"

Transform::Transform(const glm::mat4& modelMatrix) {
	m_modelMatrix = modelMatrix;
}