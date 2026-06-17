#include <custom/renderer.h>

void Renderer::draw(const VertexArray &va, const Shader &shader)
{
    va.bind();
    shader.bind();

    // draw call
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::clearScreen(const float r, const float g, const float b, const float a)
{
    // clear screen (with specified color)
    glClearColor(r, g, b, a);
    // clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::updateScreen(GLFWwindow *window)
{
    // swap framebuffer
    glfwSwapBuffers(window);
    glfwPollEvents();
}