#pragma once
#include <custom/buffer/vertexArray.h>
#include <custom/buffer/indexBuffer.h>
#include <custom/shader.h>
#include <glfw/glfw3.h>

class Renderer
{
private:
public:
    Renderer()
    {
    }
    ~Renderer()
    {
    }
    void clearScreen(const float r, const float g, const float b, const float a);
    void updateScreen(GLFWwindow *window);
    void draw(const VertexArray &va, const Shader &shader);
};