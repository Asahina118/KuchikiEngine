#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

Window::Window(uint32_t width, uint32_t height): m_width(width), m_height(height)
{	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, "Kuchiki", NULL, NULL);
	if (m_window == NULL) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window.");
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, Window::framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD.");
	}
}

// static
void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// NOTE : very clever design by allowing static function to resume back the pointer to the invoker btw.
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (win) {
		glViewport(0, 0, width, height);
		win->m_width = width;
		win->m_height = height;
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
	m_window = nullptr;
}

GLFWwindow* Window::getWindow() const
{
	return m_window;
}

bool Window::windowShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void Window::setWindowShouldClose(bool shouldClose)
{
	glfwSetWindowShouldClose(m_window, shouldClose);
}

void Window::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		setWindowShouldClose(true);
	}
}
