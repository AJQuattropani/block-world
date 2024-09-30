#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void error_callback(int error, const char* description)
{
  fprintf(stderr, "[ERROR %d]: %s\n", error, description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void) {  
 
 
  if (!glfwInit())
  {
    exit(EXIT_FAILURE);
  }
  //glfwSetErrorCallback(error_callback);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(640, 480, "BlockWorld", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    glfwTerminate();
    error_callback(-1, "Could not load GLAD with GLFW.");
  }
  glfwSwapInterval(1);

  glClearColor(0.25f, 0.4f, 0.5f, 1.0f);

  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}