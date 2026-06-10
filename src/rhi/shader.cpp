#include "shader.hpp"

RTWA::Shader::Shader(const char *vertexPath, const char *fragmentPath) {
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    // Opens shader files
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    // Init string streams from read buffers
    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    // Closes shader files
    vShaderFile.close();
    fShaderFile.close();

    // Sets the output of Streams to string
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

  } catch (std::fstream::failure e) {
    std::cout << "Exception: Could not successfully read shader files!";
  }
  const char *vShaderCode = vertexCode.c_str();

  const char *fShaderCode = fragmentCode.c_str();

  unsigned int vertex, fragment;
  int success;
  char infoLog[512];

  // vertex Shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  // print compile errors if any
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "Error: Shader compilation was not successful\n"
              << infoLog << std::endl;
  };

  // fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  // print compile errors if any
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout << "Error: Shader compilation was not successful\n"
              << infoLog << std::endl;
  };
  // shader Program
  this->ID = glCreateProgram();
  glAttachShader(this->ID, vertex);
  glAttachShader(this->ID, fragment);
  glLinkProgram(this->ID);
  // print linking errors if any
  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
    std::cout << "Error: Shader program linking failed\n"
              << infoLog << std::endl;
  }

  // delete the shaders as they're linked into our program now and no longer
  // necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}
void RTWA::Shader::use() { glUseProgram(this->ID); }
