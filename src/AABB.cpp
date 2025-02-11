#include "AABB.h"

AABB::AABB() {
	minCorner = vec3(0, 0, 0);
	maxCorner = vec3(0, 0, 0);
}

AABB::AABB(const vec3& minCorner, const vec3& maxCorner) {
	this->minCorner = minCorner;
	this->maxCorner = maxCorner;
}

bool AABB::CheckCollision(const vec3& rayOrigin, const vec3& rayDirection) {
	float pointOfIntersection = Raycast(rayOrigin, rayDirection);
	if (pointOfIntersection >= 0) {
		std::cout << "------CHECK COLLISION RETURNS TRUE------" << std::endl;
		return true;
	}
	else {
		std::cout << "CHECK COLLISION RETURN FALSE" << std::endl;
		return false;
	}
}

float AABB::Raycast(const vec3& rayOrigin, const vec3& rayDirection) {
	float t1, t2, t3, t4, t5, t6;
	if (rayDirection.X != 0) {
		t1 = (minCorner.X - rayOrigin.X) / rayDirection.X;
		t2 = (maxCorner.X - rayOrigin.X) / rayDirection.X;
	}
	if (rayDirection.Y != 0) {
		t3 = (minCorner.Y - rayOrigin.Y) / rayDirection.Y;
		t4 = (maxCorner.Y - rayOrigin.Y) / rayDirection.Y;

	}
	if (rayDirection.X != 0) {
		t5 = (minCorner.Z - rayOrigin.Z) / rayDirection.Z;
		t6 = (maxCorner.Z - rayOrigin.Z) / rayDirection.Z;

	}
	float t_min = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t4, t5));
	float t_max = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

	if (t_max < 0.0f) {
		return -1;
	}
	if (t_min > t_max) {
		return -1;
	}
	if (t_min < 0.0f) {
		return t_max;
	}
	return t_min;
}