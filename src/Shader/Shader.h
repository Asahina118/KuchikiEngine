#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include <quill/SimpleSetup.h>
#include <quill/LogFunctions.h>

class Shader
{
public:
	uint32_t m_ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	Shader(std::string vertexPath, std::string fragmentPath);
	Shader(std::string vertexPath, std::string geometryPath, std::string fragmentPath);
	Shader() = delete;
	void use();

	// set uniform vairables
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4 transform) const;
	void setVec2(const std::string& name, glm::vec2 value) const;
	void setVec2(const std::string& name, float x, float y) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, glm::vec3 value) const;
	void setVec4(const std::string& name, glm::vec4 value) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;

private:
	quill::v11::Logger* m_logger = quill::simple_logger();

	std::string m_vertexSource;
	std::string m_fragmentSource;

	std::string readFile(const std::string& filePath);

	void initShader(const char* vertexPath, const char* fragmentPath);
	void initShader(const char* vertexPath, const char* geometryPath, const char* fragmentPath);

	void checkCompilationErrors(uint32_t shader, std::string_view type);

	void checkShaderCompilation(const uint32_t shader, std::string_view filePath);
	void checkProgramCompilation(const uint32_t shaderProgram);
};
