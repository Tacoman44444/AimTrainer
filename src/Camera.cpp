#include "Camera.h"

Camera::Camera(const glm::vec3& initialPosition, float sens, float camSpeed) {
	cameraPos = initialPosition;
	cameraVel = glm::vec3(0.0f, 0.0f, 0.0f);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); 
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	camFrontProjection = glm::vec3(0.0f, 0.0f, -1.0f);

	sensitivity = sens;
	cameraSpeed = camSpeed;

	lastMousePosX = 400.0f;
	lastMousePosY = 300.0f;

	yaw = -90.0f;
	pitch = 0.0f;

	firstMouse = true;
}

void Camera::SetDirection(MovementDirections direction) {

	switch (direction) {
	case FORWARD:
		cameraVel = cameraSpeed * camFrontProjection;
		break;

	case BACKWARD:
		cameraVel = -(cameraSpeed * camFrontProjection);
		break;

	case LEFT:
		cameraVel = glm::normalize(glm::cross(cameraUp, camFrontProjection)) * cameraSpeed;
		break;

	case RIGHT:
		cameraVel = -(glm::normalize(glm::cross(cameraUp, camFrontProjection)) * cameraSpeed);
		break;
	}

}

void Camera::ResetDirection(MovementDirections direction) {
	switch (direction) {
	case FORWARD:
		cameraVel = glm::vec3(0.0f, 0.0f, 0.0f);
		break;

	case BACKWARD:
		cameraVel = glm::vec3(0.0f, 0.0f, 0.0f);
		break;

	case LEFT:
		cameraVel = glm::vec3(0.0f, 0.0f, 0.0f);
		break;

	case RIGHT:
		cameraVel = glm::vec3(0.0f, 0.0f, 0.0f);
		break;
	}
}

void Camera::Move() {
	cameraPos += cameraVel;
}

void Camera::Look(float offsetX, float offsetY) {
	if (firstMouse)
	{
		firstMouse = false;
	}

	float mouseOffsetX = offsetX * sensitivity;
	float mouseOffsetY = (-offsetY) * sensitivity;

	yaw += mouseOffsetX;
	pitch += mouseOffsetY;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
	camFrontProjection = glm::normalize(glm::vec3(cameraFront.x, 0.0f, cameraFront.z));
	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));

}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

vec3 Camera::GetLookDirection() const {
	return vec3(cameraFront.x, cameraFront.y, cameraFront.z);
}

vec3 Camera::GetPosition() const {
	return vec3(cameraPos.x, cameraPos.y, cameraPos.z);
}