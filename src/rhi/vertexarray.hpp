#pragma once
#include "rhi.hpp"
#include <vector>
namespace RTWA {
class VertexArray {
public:
  GLuint VAO, VBO; // Vertex Array Object, Vertex Buffer Object
  void load();
  void draw();
  void clear();
  void addVertices(std::vector<GLfloat> vertices);

private:
  std::vector<std::vector<GLfloat>> VertexVector;
};
} // namespace RTWA
