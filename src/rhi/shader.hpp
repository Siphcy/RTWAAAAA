#include "rhi.hpp"
namespace RTWA {
class Shader {
public:
  GLuint ID;
  Shader(const char *vertexPath, const char *fragmentPath);
  void use();
};
} // namespace RTWA
