#pragma once
#include "rhi.hpp"
#include <vector>
namespace RTWA {
class Vertex {
public:
  GLuint VAO, VBO; // Vertex Array Object, Vertex Buffer Object
  Vertex(std::vector<GLfloat> vertexpoints) {
    this->vertexpoints = vertexpoints;
  }
  void load();
  void draw();
  void clear();
  std::vector<GLfloat> vertexpoints;
};
} // namespace RTWA
