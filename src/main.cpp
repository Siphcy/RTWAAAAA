#include "core/application.hpp"
#include "rhi/vertex.hpp"
#include "rhi/vertexvector.hpp"

int main() {
  RTWA::VertexVector vv;
  RTWA::Vertex v1({
      -0.8f,
      -0.5f,
      0.0f,
      -0.3f,
      -0.5f,
      0.0f,
      -0.55f,
      0.5f,
      0.0f,
  });

  RTWA::Vertex v2({
      0.3f,
      -0.5f,
      0.0f,
      0.8f,
      -0.5f,
      0.0f,
      0.3f,
      0.5f,
      0.0f,
      0.8f,
      0.5f,
      0.0f,
  });
  RTWA::Vertex v3({
      0.50f,
      -0.2f,
      0.0f,
      0.8f,
      -0.6f,
      0.0f,
      0.5f,
      0.5f,
      0.0f,
  });

  RTWA::Vertex v4({
      -0.4f,
      -0.4f,
      0.0f,
      0.2f,
      -0.4f,
      0.0f,
      -0.4f,
      0.4f,
      0.0f,
      0.2f,
      0.4f,
      0.0f,
  });

  vv.addVertex(v1);

  vv.addVertex(v2);
  // vv.addVertex(v4);
  RTWA::app App;
  App.setShaderPaths("shaders/triangle.vert", "shaders/triangle.frag");
  App.setVertexArray(vv);
  App.Run(1080, 800, "Triangle");
}
