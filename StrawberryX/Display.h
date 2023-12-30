#pragma once

#include <string>
#include <stdexcept>

#pragma execution_character_set("utf-8")
#include "GLFW/glfw3.h"

namespace sbx
{
	class Display
	{
	protected:
		GLFWwindow* window;

	public:

		Display() : window()
		{

		}

		Display(const char* title, int width, int height) : window()
		{
			this->init(title, width, height);
		}

		void init(const char* title, int width, int height);

		virtual void on_keydown();

		virtual void on_keyup();

	private:

		/** GLFW �����ص�����
		* @param window ���ھ��
		* @param key	������
		* @param scancode ����ɨ����
		* @param action
		* @param mods
		*/
		static void on_key(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept;
	};
}
