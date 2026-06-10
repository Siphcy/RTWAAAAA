#include "core/application.hpp"
#include "rhi/vertexarray.hpp"

int main() {
  RTWA::VertexArray va;
  va.addVertices({
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
  });

  RTWA::app App;
  App.setShaderPaths("shaders/triangle.vert", "shaders/triangle.frag");
  App.setVertexArray(va);
  App.Run(800, 600, "Triangle");
}
