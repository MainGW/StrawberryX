#include "Display.h"

namespace sbx
{
	
	void Display::init(const char * title, int width, int height)
	{
		glfwInit();
		glfwDefaultWindowHints();

		if (!(window = glfwCreateWindow(width, height, title, nullptr, nullptr)))
		{
			throw std::runtime_error("´´½¨´°¿ÚÊ§°Ü¡£");
		}

		glfwMakeContextCurrent(window);

		glfwSetKeyCallback(window, on_key);
	}

	void Display::on_key(GLFWwindow* window, int key, int scancode, int actions, int mods) noexcept
	{

	}
		
}
