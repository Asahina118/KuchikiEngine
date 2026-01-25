#pragma once

#include <glm/glm.hpp>
#include <array>

namespace Shapes
{
	inline constexpr std::array<float, 9> triangleVertices = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};

	inline constexpr std::array<float, 9> triangleVerticesTextured = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};

	struct Square 
	{
		static constexpr std::array<float, 20> vertices = {
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		static constexpr std::array<float, 20> verticesTextured = {
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		static constexpr std::array<uint32_t, 6> indices = {
			0, 1, 2,
			0, 2, 3
		};
	};

}