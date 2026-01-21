#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image/stb_image.h>

#include "Window/Window.h"

#include "Shader/Shader.h"
#include "Entities/Shapes.h"

#include <quill/SimpleSetup.h>
#include <quill/LogFunctions.h>

int main()
{
	auto* logger = quill::simple_logger();
	quill::info(logger, "Hello from {}!", std::string_view{"Kuchiki Engine"});

	const unsigned SCR_WIDTH = 800;
	const unsigned SCR_HEIGHT = 600;
	Window window(SCR_WIDTH, SCR_HEIGHT);

	std::array<float, 9> triangleVertices = Shapes::triangleVertices;

	unsigned VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, triangleVertices.size() * sizeof(float), triangleVertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	Shader shader("GLSL/cube.vert", "GLSL/cube.frag");

	while (!window.windowShouldClose()) {
		window.processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
