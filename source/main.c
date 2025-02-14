
#include <stdio.h>

#include "vulkan/vulkan.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

void errorCallback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

int main() {
  if (!glfwInit()) {
    fprintf(stderr, "Error Initializing GLFW\n");
    return 1;
  }

  glfwSetErrorCallback(errorCallback);

  GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Error Creating GLFW Window");
    return 1;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}