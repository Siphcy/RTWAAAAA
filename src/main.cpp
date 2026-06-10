#include "core/application.hpp"
int main() {

  std::cout << "Hello World";
  RTWA::app App;
  App.Run(800, 800, "Testing");
}
