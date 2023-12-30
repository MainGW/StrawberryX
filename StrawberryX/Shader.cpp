#include "Shader.h"

namespace sbx
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{

		// 1. 读取文件内容
		std::string vCode, fCode;
		std::ifstream vFile, fFile;
		vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		
		vFile.open(vertexPath);
		fFile.open(fragmentPath);

		std::stringstream vStream, fStream;
		vStream << vFile.rdbuf();
		fStream << fFile.rdbuf();

		vCode = vStream.str();
		fCode = fStream.str();
		
		const char* vsCode, * fsCode;
		vsCode = vCode.c_str(), fsCode = fCode.c_str();
		// 2. 编译着色器

		unsigned int vId, fId;
		int success;
		char infoLog[512];

		vId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vId, 1, &vsCode, NULL);
		glCompileShader(vId);
		glGetShaderiv(vId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vId, 512, NULL, infoLog);
			throw std::runtime_error("编译顶点着色器失败，原因：" + std::string(infoLog));
		}
		
		fId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(fId, 1, &fsCode, NULL);
		glCompileShader(fId);
		glGetShaderiv(fId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fId, 512, NULL, infoLog);
			throw std::runtime_error("编译片段着色器失败，原因：" + std::string(infoLog));
		}

		id = glCreateProgram();
		glAttachShader(id, vId);
		glAttachShader(id, fId);
		glLinkProgram(id);
		glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(id, 512, nullptr, infoLog);
			throw std::runtime_error("连接着色器失败，原因：" + std::string(infoLog));
		}

		glDeleteShader(vId);
		glDeleteShader(fId);
	}

	void Shader::use()
	{
		glUseProgram(id);
	}

	void Shader::setUniform(const char* name, int value) const
	{
		glUniform1i(glGetUniformLocation(id, name), value);
	}
	
	void Shader::setUniform(const char* name, bool value) const
	{
		glUniform1i(glGetUniformLocation(id, name), static_cast<bool>(value));
	}

	void Shader::setUniform(const char* name, float value) const
	{
		glUniform1f(glGetUniformLocation(id, name), value);
	}
}
