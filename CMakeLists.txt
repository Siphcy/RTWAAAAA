cmake_minimum_required(VERSION 3.20)
project(RTWAAAAA VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE sources src/*.cpp src/*.hpp)

add_subdirectory(external/glad/)
add_executable(RTWAAAAA ${sources})


  if(UNIX AND NOT APPLE)
      pkg_check_modules(OPENGL REQUIRED gl)
      pkg_check_modules(GLFW REQUIRED glfw3)

      target_link_libraries(RTWAAAAA
          ${OPENGL_LIBRARIES}
          ${GLFW_LIBRARIES}
          glad
      )
      target_include_directories(RTWAAAAA PRIVATE
          ${OPENGL_INCLUDE_DIRS}
          ${GLFW_INCLUDE_DIRS}
      )
  else()
      find_package(OpenGL REQUIRED)
      find_package(glfw3 REQUIRED)

      target_link_libraries(RTWAAAAA
          OpenGL::GL
          glfw
          glad
      )

  endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_compile_options(
    -Wall -Wextra -Wpedantic
    $<$<CONFIG:Release>:-O3 -march=native>
    $<$<CONFIG:Debug>:-g -fsanitize=address>
)





