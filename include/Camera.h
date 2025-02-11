#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vec3.h"

enum MovementDirections {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
};

class Camera {

public:
	Camera(const glm::vec3& initialPosition, float sens, float camSpeed);

	void SetDirection(MovementDirections direction);

	void ResetDirection(MovementDirections direction);

	void Move();

	void Look(float mousePosX, float mousePosY);

	glm::mat4 GetViewMatrix();
	vec3 GetLookDirection() const;
	vec3 GetPosition() const;

private:
	glm::vec3 cameraPos;
	glm::vec3 cameraVel;

	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

	glm::vec3 worldUp;
	glm::vec3 camFrontProjection;

	float sensitivity;
	float cameraSpeed;

	float lastMousePosX;
	float lastMousePosY;

	float yaw;
	float pitch;

	bool firstMouse;

};