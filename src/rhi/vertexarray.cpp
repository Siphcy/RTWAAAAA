#include "vertexarray.hpp"

RTWA::VertexArray::VertexArray() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  for (std::vector<GLfloat> &vertices : this->VertexVector) {

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
  }
}

void RTWA::VertexArray::addVertices(std::vector<GLfloat> vertices) {
  this->VertexVector.push_back(vertices);
}
