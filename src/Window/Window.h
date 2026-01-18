#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <cstdint>

class Window
{
public:
	Window() = default;
	Window(uint32_t width = 1300, uint32_t height = 800);
	~Window();
	GLFWwindow* getWindow() const;
	bool windowShouldClose() const;
	void setWindowShouldClose(bool);
	void processInput();

private:
	uint32_t m_width;
	uint32_t m_height;

	GLFWwindow* m_window;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};