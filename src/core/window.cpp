#include "window.hpp"

RTWA::Window::Window(int width, int height, const char* title) {
  this->handle = glfwCreateWindow(width, height, title, NULL, NULL);
}

GLFWwindow *RTWA::Window::getHandle() { return this->handle; }
