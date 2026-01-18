#pragma once
#include "Camera/Camera.h"
#include "Window/Window.h"

class Scene
{
public:
	Scene(Window&, Camera&);

private:
	Window& m_window;
	Camera& m_camera;
};