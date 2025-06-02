#pragma once

#include "IComponent.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ITargetComponent : public IComponent {
public:

	virtual int ScoreLogic() = 0;
	virtual bool IsHit(glm::vec3 ray) = 0;
	virtual int& Health() = 0;

	virtual ~ITargetComponent() = default;
};