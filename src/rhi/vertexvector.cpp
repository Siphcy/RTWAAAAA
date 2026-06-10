#include "vertexvector.hpp"
#include "vertex.hpp"

void RTWA::VertexVector::addVertex(RTWA::Vertex vertices) {
  this->vertices.push_back(vertices);
}

void RTWA::VertexVector::loadAll() {
  for (auto &vertex : this->vertices) {
    vertex.load();
  }
}

void RTWA::VertexVector::drawAll() {
  for (auto &vertex : this->vertices) {
    vertex.draw();
  }
}

void RTWA::VertexVector::clearAll() {
  for (auto &vertex : this->vertices) {
    vertex.clear();
  }
}
