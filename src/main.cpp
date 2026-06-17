#define STB_IMAGE_IMPLEMENTATION

#include <custom/init.h>

#include <custom/buffer/vertexBuffer.h>
#include <custom/buffer/bufferLayout.h>
#include <custom/buffer/vertexArray.h>

#include <custom/shader.h>
#include <custom/texture.h>
#include <custom/renderer.h>

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    init();

    Window *window = createWindow(800, 800, "Review");
    // vertex data
    // preetier-ignore
    float vertices[] = {
        // pos              // color // tex
        0.0f, 0.577f, 0.0f, 1, 0, 0, 0.5f, 1.0f,
        -0.5f, -0.289f, 0.0f, 0, 1, 0, 0.0f, 0.0f,
        0.5f, -0.289f, 0.0f, 0, 0, 1, 1.0f, 0.0f};

    // render setup
    VertexBuffer vb(vertices, sizeof(vertices));

    BufferLayout layout;
    // vertex data
    layout.push<float>(3);
    // color data
    layout.push<float>(3);
    // texture data
    layout.push<float>(2);

    VertexArray va;
    va.addLayout(vb, layout);

    // shader portion
    Shader shader("../src/shader/code/", {"vertexshader.vs", "fragmentShader.fs"});
    shader.bind();

    // texture portion
    Texture cartTexture("../assets/textures/cart.png");
    Texture smileTexture("../assets/textures/smile.png");
    shader.setUniform("texture1", cartTexture.mySlot);
    shader.setUniform("texture2", smileTexture.mySlot);

    Renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        renderer.clearScreen(0.1, 0.2, 0.5, 1);

        renderer.draw(va, shader);

        renderer.updateScreen(window);
    }

    glfwTerminate();
    return 0;
}