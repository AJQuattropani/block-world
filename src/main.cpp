#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

int main()
{
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(640, 480, "BlockWorld", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Couldn't load GLAD." << std::endl;
		glfwTerminate();
		return -1;
	}

	glClearColor(0.54f, 0.3f, 0.7f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glfwSwapBuffers(window);
	}
	

	glfwTerminate();

	std::cout << "Hello BlockWorld!\n";
	return 0;
}
