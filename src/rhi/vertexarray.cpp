#include "vertexarray.hpp"

void RTWA::VertexArray::addVertices(std::vector<GLfloat> vertices) {
  this->VertexVector.push_back(vertices);
}

void RTWA::VertexArray::load() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  for (std::vector<GLfloat> &vertices : this->VertexVector) {
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat),
                 vertices.data(), GL_STATIC_DRAW);
  }
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void RTWA::VertexArray::draw() {
  if (this->VAO == 0) {
    std::cout << "Error: Either did not load or VAO failed to generate!"
              << std::endl;
    return;
  }
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RTWA::VertexArray::clear() {
  glDeleteVertexArrays(1, &this->VAO);
  glDeleteBuffers(1, &this->VBO);
}
