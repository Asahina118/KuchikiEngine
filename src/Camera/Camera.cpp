#include "Camera.h"
#include <iostream>

#include "Calc/KuchikiConstants.h"

#include <glm/glm.hpp>

Camera::Camera(
	glm::vec3 position,
	glm::vec3 worldUp,
	glm::vec3 front,
	float theta,
	float phi
) :
	m_position(position),
	m_worldUp(worldUp),
	m_front(front),
	m_theta(theta),
	m_phi(phi)
{
	// potential changes if we import settings from files
	using namespace KuchikiConstants::Camera;

	m_movementSpeed = BASE_MOVEMENT_SPEED;
	m_sprintSpeed = SPRINT_SPEED;
	m_mouseSensitivity = MOUSE_SENSITIVITY;
	m_zoom = CAMERA_ZOOM;
	m_FOV = CAMERA_FOV;
	m_right = glm::normalize(glm::cross(m_front, m_worldUp));

	m_firstMouse = false;
	m_enableFlashlight = false;
	m_stopUpdating = false;
}

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(m_position, m_position + m_front, m_worldUp);
}

glm::mat4 Camera::getProjMatrix() const
{
	return glm::perspective(glm::radians(m_FOV), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Camera::processKeyboard(CameraMovement movement, float deltaTime)
{
	float velocity = m_movementSpeed * deltaTime;

	switch (movement) {
	case CameraMovement::FORWARD:
		m_position += velocity * m_front;
		break;
	case CameraMovement::BACKWARD:
		m_position -= velocity * m_front;
		break;
	case CameraMovement::RIGHT:
		m_position += velocity * m_right;
		break;
	case CameraMovement::LEFT:
		m_position -= velocity * m_right;
		break;
	case CameraMovement::UP:
		m_position += velocity * m_worldUp;
		break;
	case CameraMovement::DOWN:
		m_position -= velocity * m_worldUp;
		break;
	case CameraMovement::SPRINT:
		m_movementSpeed = m_movementSpeed == 1.0f ? m_sprintSpeed : 1.0f;
	}
}

void Camera::processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch)
{

}

glm::vec3 Camera::getPosition() const
{
	return m_position;
}

void Camera::updateCameraVectors()
{

}
