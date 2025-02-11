#pragma once

#include <cmath>

class vec3 {

public:

	union {
		struct {
			float X, Y, Z; // Named members
		};
		float data[3]; // Array for indexed access
	};

	vec3(float x, float y, float z);
	vec3(float x, float y);
	vec3();

	vec3 operator+(const vec3& other) const;
	vec3 operator-(const vec3& other) const;
	vec3 operator*(float scalar) const;
	vec3 operator/(float scalar) const;

	vec3& operator+=(const vec3& other);
	vec3& operator-=(const vec3& other);
	vec3& operator*=(float scalar);
	vec3& operator/=(float scalar);

	float& operator[](int index);
	const float& operator[](int index) const;

	float magnitude() const;
	vec3 normalize() const;

	float dot(const vec3& other) const;
	vec3 cross(const vec3& other) const;
};

namespace Vec3 {
	inline static vec3 Up() {
		return vec3(0, -1, 0);
	}

	inline static vec3 Down() {
		return vec3(0, 1, 0);
	}

	inline static vec3 Left() {
		return vec3(-1, 0, 0);
	}

	inline static vec3 Right() {
		return vec3(1, 0, 0);
	}
}

using Coordinate3D = vec3;