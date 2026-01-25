#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Camera/Camera.h"
#include "Window/Window.h"

class InputHandler {
public:
	InputHandler(const Window&, Camera&);
	void processInput();

private:
	void processCameraInput();
	void processMouseInput();
	const Window& m_window;
	Camera& m_camera;

	bool m_toggleLockSprinting;
	bool m_toggleLockFlashlight;
	bool m_toggleLockChangeMouseInput;
	float m_tempTheta;
	float m_tempPhi;
};