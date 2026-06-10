#include "application.hpp"

void RTWA::app::Run(int width, int height, const char *title) {
  if (!glfwInit()) {
    std::cout << "Exception: Unable to initialize GLFW\n";
    return;
  }
  this->window = std::make_unique<RTWA::Window>(width, height, title);
  glfwMakeContextCurrent(this->window->getHandle());
  this->MainLoop();
  glfwTerminate();
}

void RTWA::app::MainLoop() {
  glClearColor(100.0f, 90.0f, 20.0f, 1.0f);
  while (!glfwWindowShouldClose(this->window->getHandle())) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window->getHandle());
  }
}
