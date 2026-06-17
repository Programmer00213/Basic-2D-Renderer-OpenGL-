#include <custom/init.h>

void init()
{
    // initialize glfw
    if (!glfwInit())
    {
        std::cout << "failed to initialize glfw" << std::endl;
    }
    // configure glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLFWwindow *createWindow(int width, int height, const char *title)
{
    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize glad" << std::endl;
        return NULL;
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    return window;
}