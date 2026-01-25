#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	enum class CameraMovement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		SPRINT
	};

	Camera(
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 front = glm::vec3(0.0f, 0.0f, 1.0f),
		float theta = 90.0f,
		float phi = 0.0f
	);

	glm::mat4 getViewMatrix() const;
	glm::mat4 getProjMatrix() const;

	void processKeyboard(CameraMovement direction, float deltaTime);

	void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);

	void processMouseScroll(float yOffset);

	glm::vec3 getPosition() const;

private:
	glm::vec3 m_front;
	glm::vec3 m_position;
	glm::vec3 m_worldUp;
	glm::vec3 m_right;

	float m_theta;
	float m_phi;

	float m_movementSpeed;
	float m_mouseSensitivity;
	float m_zoom;
	float m_sprintSpeed;
	float m_FOV;

	bool m_firstMouse;
	bool m_enableFlashlight;
	bool m_stopUpdating;

	void updateCameraVectors();
};