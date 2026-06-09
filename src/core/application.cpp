#include "application.hpp"
#include <GLFW/glfw3.h>

void RTWA::app::Run() {

  this->MainLoop();
  return;
}

void RTWA::app::MainLoop() {
  GLFWwindow *window;
  if (!glfwInit()) {
    return;
  }
  window = glfwCreateWindow(800, 800, "RTWA", NULL, NULL);
}
