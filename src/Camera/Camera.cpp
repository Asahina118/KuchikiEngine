#include "Camera.h"
#include <iostream>

#include "Calc/KuchikiConstants.h"

#include <glm/glm.hpp>

Camera::Camera(
	glm::vec3 position,
	glm::vec3 worldUp,
	float theta,
	float phi
) :
	position(position),
	worldUp(worldUp),
	theta(theta),
	phi(phi)
{
	using namespace KuchikiConstants::Camera;

	movementSpeed = MOVEMENT_SPEED;
	sprintSpeed = SPRINT_MULTIPLIER;
	mouseSensitivity = MOUSE_SENSITIVITY;
	zoom = CAMERA_ZOOM;
	FOV = CAMERA_FOV;

	firstMouse = false;
	enableFlashlight = false;
	stopUpdating = false;
}

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(position, position + front, worldUp);
}
