// StrawberryX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 初始化glfw和opengl并创建窗口

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

const char* title = "Hello, world!";
const int width = 1920, height = 1080;

/**
* 窗口大小变更回调函数
* @param window 窗口对象
* @param w		新宽度
* @param h		新高度
*/ 
void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);
}

int main(int argc, const char *argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window;
	if (!(window = glfwCreateWindow(width, height, title, NULL, NULL)))
	{
		std::cerr << "创建窗口失败。" << std::endl;
		glfwTerminate();
		return -1;
	}	

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cerr << "初始化glad失败。" << std::endl;
		glfwTerminate();
		return -2;
	}

	// 设置视口大小
	glViewport(0, 0, width, height);

	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	// 事件循环
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
