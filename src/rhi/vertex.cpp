#include "vertex.hpp"
#include <cmath>
#include <vector>

void RTWA::Vertex::load() {
  int flattened_size = std::floor(this->vertexpoints.size() / 3);

  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &this->VBO);
  glBindVertexArray(this->VAO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, this->vertexpoints.size() * sizeof(GLfloat),
               vertexpoints.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, flattened_size, GL_FLOAT, GL_FALSE,
                        3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void RTWA::Vertex::draw() {
  if (this->VAO == 0) {
    std::cout << "Error: Either did not load or VAO failed to generate!"
              << std::endl;
    return;
  }
  int vertexCount = this->vertexpoints.size() / 3;
  GLenum mode = (vertexCount == 4) ? GL_TRIANGLE_STRIP : GL_TRIANGLES;
  glBindVertexArray(this->VAO);
  glDrawArrays(mode, 0, vertexCount);
}

void RTWA::Vertex::clear() {
  glDeleteVertexArrays(1, &this->VAO);
  glDeleteBuffers(1, &this->VBO);
}
