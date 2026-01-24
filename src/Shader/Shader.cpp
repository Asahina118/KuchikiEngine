#ifdef DEBUG
#define GL_ASSERT_UNIFORM_FOUND(call) do {\
	call;\
	GLenum errorState = glGetError();\
	if (errorState != GL_NO_ERROR) {\
		quill::error(m_logger, "Uniform location not found at: {} {}\n", __FILE__, __LINE__);\
	}\
}\
while (0)
#else
#define GL_ASSERT(call) call
#endif

#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <quill/SimpleSetup.h>
#include <quill/LogFunctions.h>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	initShader(vertexPath, fragmentPath);
}

Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
	initShader(vertexPath.c_str(), fragmentPath.c_str());
}

void Shader::use()
{
	glUseProgram(m_ID);
}

std::string Shader::readFile(const std::string& filePath)
{
	std::ifstream file(filePath, std::ios::binary);

	if (!file.is_open()) {
		quill::error(m_logger, "Error reading file at {}:\n{}\n", filePath);
	}

	std::stringstream stream;
	stream << file.rdbuf();
	return stream.str();
}

void Shader::initShader(const char* vertexPath, const char* fragmentPath)
{
	uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_vertexSource = readFile(vertexPath);
	const GLchar* vertexCode = m_vertexSource.c_str();
	glShaderSource(vertexShader, 1, &vertexCode, NULL);
	glCompileShader(vertexShader);
	checkShaderCompilation(vertexShader, vertexPath);

	uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	m_fragmentSource = readFile(fragmentPath);
	const GLchar* fragmentCode = m_fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
	glCompileShader(fragmentShader);
	checkShaderCompilation(fragmentShader, fragmentPath);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	glLinkProgram(m_ID);
	checkProgramCompilation(m_ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::checkShaderCompilation(const uint32_t shader, std::string_view filePath)
{
	GLchar infoLog[512];
	int32_t success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		quill::error(m_logger, "shader compilation failed at {}\n{}\n", filePath, infoLog);
	}
	else {
		quill::info(m_logger, "shader compiled successfully from {}\n", filePath);
	}
}

void Shader::checkProgramCompilation(const uint32_t shaderProgram)
{
	GLchar infoLog[512];
	int32_t success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		quill::error(m_logger, "shader program linking failed at {}\n", infoLog);
	}
	else {
		quill::info(m_logger, "shader program linked successfully");
	}
}

void Shader::setBool(const std::string& name, bool value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform1i(glGetUniformLocation(m_ID, name.c_str()), static_cast<int32_t>(value)));
}

void Shader::setInt(const std::string& name, int value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value));
}

void Shader::setFloat(const std::string& name, float value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value));
}

void Shader::setMat4(const std::string& name, glm::mat4 transform) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(transform)));
}

void Shader::setVec2(const std::string& name, glm::vec2 value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform2f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y));
}

void Shader::setVec2(const std::string& name, float x, float y) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform2f(glGetUniformLocation(m_ID, name.c_str()), x, y));
}

void Shader::setVec3(const std::string& name, glm::vec3 value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform3f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y, value.z));
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z));
}

void Shader::setVec4(const std::string& name, glm::vec4 value) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform4f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y, value.z, value.w));
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	GL_ASSERT_UNIFORM_FOUND(glUniform4f(glGetUniformLocation(m_ID, name.c_str()), x, y, z, w));
}
