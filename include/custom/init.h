#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

typedef GLFWwindow Window;

void init();

void framebufferSizeCallback(GLFWwindow *window, int width, int height);

GLFWwindow *createWindow(int width, int height, const char *title);