#pragma once

#include "../rhi/shader.hpp"
#include "../rhi/vertexvector.hpp"
#include "window.hpp"
#include <memory>
namespace RTWA {
class app {
public:
  void Run(int width, int height, const char *title);
  void setShaderPaths(const char *vertPath, const char *fragPath);
  void setVertexArray(RTWA::VertexVector &vertexvector);

private:
  const char *vertShaderPath = nullptr;
  const char *fragShaderPath = nullptr;
  std::unique_ptr<RTWA::Shader> shader;
  RTWA::VertexVector *vertexvector = nullptr;
  std::unique_ptr<RTWA::Window> window;
  void MainLoop();
};

} // namespace RTWA
