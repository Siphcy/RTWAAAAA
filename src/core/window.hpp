#pragma once
#include "core.hpp"

namespace RTWA {
class Window {
public:
  Window(int, int, const char *);
  GLFWwindow *getHandle();

private:
  GLFWwindow *handle;
};

} // namespace RTWA
