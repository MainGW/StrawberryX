#pragma once

#include "glad/glad.h"

#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>

namespace sbx
{
	class Shader
	{
	private:
		unsigned int id;

	public:

		Shader(const char* vertexPath, const char* fragmentPath);

		//Shader(const char* vertexPath, const char* geometryPath, const char* fragmentPath);

		void use();

		void setUniform(const char* name, int value) const;
		void setUniform(const char* name, bool value) const;
		void setUniform(const char* name, float value) const;
	};
}
