cmake_minimum_required(VERSION 3.20)
project(RTWAAAAA VERSION 0.1.0 LANGUAGES CXX)

find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE sources src/*.cpp src/*.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include)
file(GLOB BUTTERFLIES_SOURCES_C ${CMAKE_CURRENT_SOURCE_DIR}/external *.c glad/src/gl.c)

add_executable(RTWAAAAA ${sources} ${includes})
  if(UNIX AND NOT APPLE)
      pkg_check_modules(OPENGL REQUIRED gl)
      pkg_check_modules(GLAD REQUIRED glfw3)

      target_link_libraries(RTWAAAAA
          ${OPENGL_LIBRARIES}
          ${GLFW_LIBRARIES}
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





