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

	inline constexpr std::array<float, 1> planeVertices = {
		1.0f
	};

}