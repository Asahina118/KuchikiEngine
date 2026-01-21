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
		quill::error(logger, "Error reading file at {}:\n{}\n", filePath);
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
		quill::error(logger, "shader compilation failed at {}\n{}\n", filePath, infoLog);
	}
	else {
		quill::info(logger, "shader compiled successfully from {}\n", filePath);
	}
}

void Shader::checkProgramCompilation(const uint32_t shaderProgram)
{
	GLchar infoLog[512];
	int32_t success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		quill::error(logger, "shader program linking failed at {}\n", infoLog);
	}
	else {
		quill::info(logger, "shader program linked successfully");
	}
}
