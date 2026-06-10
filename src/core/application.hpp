#pragma once

#include <memory>

#include "window.hpp"
namespace RTWA {
class app {
public:
  void Run(int width, int height, const char *title);

private:
  std::unique_ptr<RTWA::Window> window;
  void MainLoop();
};

} // namespace RTWA
