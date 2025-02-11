#pragma once

#include <limits>
#include <algorithm>
#include "vec3.h"
#include <iostream>

class AABB {

public:

	AABB();
	AABB(const vec3& minCorner, const vec3& maxCorner);

	bool CheckCollision(const vec3& rayOrigin, const vec3& rayDirection);
	float Raycast(const vec3& rayOrigin, const vec3& rayDirection);

private:

	vec3 minCorner;
	vec3 maxCorner;
};