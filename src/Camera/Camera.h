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
		DOWN
	};

	Camera(
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
		float theta = 90.0f,
		float phi = 0.0f
	);

	Camera() = delete;

	glm::mat4 getViewMatrix() const;

	void processKeyboard(CameraMovement direction, float deltaTime);

	void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);

	void processMouseScroll(float yOffset);

private:
	glm::vec3 front;
	glm::vec3 position;
	glm::vec3 worldUp;
	glm::vec3 right;

	float theta;
	float phi;

	float movementSpeed;
	float mouseSensitivity;
	float zoom;
	float sprintSpeed;
	float FOV;

	bool firstMouse;
	bool enableFlashlight;
	bool stopUpdating;

	void updateCameraVectors();
};