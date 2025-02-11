#include "vec3.h"

vec3::vec3(float x, float y, float z) : X(x), Y(y), Z(z) {}

vec3::vec3(float x, float y) : X(x), Y(y), Z(0) {}

vec3::vec3() : X(0), Y(0), Z(0) {}

vec3 vec3::operator+(const vec3& other) const {
	return vec3(X + other.X, Y + other.Y, Z + other.Z);
}

vec3 vec3::operator-(const vec3& other) const {
	return vec3(X - other.X, Y - other.Y, Z - other.Z);
}

vec3 vec3::operator*(float scalar) const {
	return vec3(X * scalar, Y * scalar, Z * scalar);
}

vec3 vec3::operator/(float scalar) const {
	return vec3(X / scalar, Y / scalar, Z / scalar);
}

vec3& vec3::operator+=(const vec3& other) {
	X += other.X, Y += other.Y, Z += other.Z;
	return *this;
}

vec3& vec3::operator-=(const vec3& other) {
	X -= other.X, Y -= other.Y, Z -= other.Z;
	return *this;
}

vec3& vec3::operator*=(float scalar) {
	X *= scalar, Y *= scalar, Z *= scalar;
	return *this;
}

vec3& vec3::operator/=(float scalar) {
	X /= scalar, Y /= scalar, Z /= scalar;
	return *this;
}

float& vec3::operator[](int index) {
	return data[index];
}

const float& vec3::operator[](int index) const {
	return data[index];
}

float vec3::magnitude() const {
	return std::sqrt(X * X + Y * Y + Z * Z);
}

vec3 vec3::normalize() const {
	float mag = magnitude();
	return (mag != 0) ? vec3(X / mag, Y / mag, Z / mag) : vec3();
}

float vec3::dot(const vec3& other) const {
	return X * other.X + Y * other.Y + Z * other.Z;
}

vec3 vec3::cross(const vec3& other) const {
	return vec3(
		Y * other.Z - Z * other.Y,
		Z * other.X - X * other.Z,
		X * other.Y - Y * other.X
	);
}