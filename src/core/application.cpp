#include "application.hpp"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

void RTWA::app::Run(int width, int height, const char *title) {
  if (!glfwInit()) {
    std::cout << "Exception: Unable to initialize GLFW\n";
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->window = std::make_unique<RTWA::Window>(width, height, title);
  glfwMakeContextCurrent(this->window->getHandle());

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Exception: Failed to initialize GLAD\n";
    return;
  }

  if (this->vertShaderPath == nullptr || this->fragShaderPath == nullptr) {
    std::cout << "Warning: Please set shader paths";
  } else {
    this->shader = std::make_unique<RTWA::Shader>(vertShaderPath, fragShaderPath);
  }

  if (this->vertexarray == nullptr) {
    std::cout << "Warning: Please set Vertex Array";
  } else {
    this->vertexarray->load();
  }

  this->MainLoop();

  this->vertexarray->clear();
  glfwDestroyWindow(this->window->getHandle());
  glfwTerminate();
}

void RTWA::app::MainLoop() {
  while (!glfwWindowShouldClose(this->window->getHandle())) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (this->shader) this->shader->use();
    this->vertexarray->draw();
    glfwSwapBuffers(this->window->getHandle());
    glfwPollEvents();
  }
}

void RTWA::app::setShaderPaths(const char *vertPath, const char *fragPath) {
  this->vertShaderPath = vertPath;
  this->fragShaderPath = fragPath;
}
void RTWA::app::setVertexArray(RTWA::VertexArray &vertexarray) {
  this->vertexarray = &vertexarray;
}
