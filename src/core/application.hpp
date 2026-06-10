#pragma once

#include "../rhi/shader.hpp"
#include "../rhi/vertexarray.hpp"
#include "window.hpp"
#include <memory>
namespace RTWA {
class app {
public:
  void Run(int width, int height, const char *title);
  void setShaderPaths(const char *vertPath, const char *fragPath);
  void setVertexArray(RTWA::VertexArray &vertexarray);

private:
  const char *vertShaderPath = nullptr;
  const char *fragShaderPath = nullptr;
  std::unique_ptr<RTWA::Shader> shader;
  RTWA::VertexArray *vertexarray = nullptr;
  std::unique_ptr<RTWA::Window> window;
  void MainLoop();
};

} // namespace RTWA
