// StrawberryX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
<<<<<<< HEAD

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
const char* title = "Hello, world!";
const int width = 800, height = 600;

void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

int main(int argc, const char *argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window;
	if ((window = glfwCreateWindow(width, height, title, nullptr, nullptr)) == nullptr)
	{
		std::cerr << "创建窗口失败。" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cerr << "初始化glad失败。" << std::endl;
		glfwTerminate();
		return -2;
	}

	glViewport(0, 0, width, height);

	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
