#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image/stb_image.h>

#include "Window/Window.h"

int main()
{
	const unsigned SCR_WIDTH = 800;
	const unsigned SCR_HEIGHT = 600;
	Window window(SCR_WIDTH, SCR_HEIGHT);

	while (!window.windowShouldClose()) {
		window.processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
