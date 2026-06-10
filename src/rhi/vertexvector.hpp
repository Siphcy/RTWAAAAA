#pragma once
#include "rhi.hpp"
#include "vertex.hpp"
#include <vector>
namespace RTWA {
class VertexVector {
public:
  void drawAll();
  void loadAll();
  void clearAll();
  void addVertex(RTWA::Vertex vertex);

private:
  std::vector<RTWA::Vertex> vertices;
};
} // namespace RTWA
