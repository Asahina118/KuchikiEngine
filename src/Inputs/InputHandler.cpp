#include "InputHandler.h"

InputHandler::InputHandler(const Window& window, Camera& camera)
	: m_window(window), m_camera(camera)
{

}

void InputHandler::processInput()
{
	processCameraInput();
	processMouseInput();
}

void InputHandler::processCameraInput()
{
	float deltaTime = 0.1f;

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window.getWindow(), true);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_W) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::FORWARD, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_S) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::BACKWARD, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_D) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::RIGHT, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_A) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::LEFT, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::UP, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		m_camera.processKeyboard(Camera::CameraMovement::DOWN, deltaTime);

	if (glfwGetKey(m_window.getWindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		if (!m_toggleLockSprinting) {
			m_toggleLockSprinting = true;
			m_camera.processKeyboard(Camera::CameraMovement::SPRINT, deltaTime);
		}
	}
	else {
		m_toggleLockSprinting = false;
	}
}

void InputHandler::processMouseInput()
{
	
}