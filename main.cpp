#include <iostream>
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {

    GLFWwindow* window;

    if (!glfwInit())
    {
        printf("GLFW did a dumb");
        return -1;
    }

    glfwSetErrorCallback(error_callback);

    window = glfwCreateWindow(640, 480, "GLFW", NULL, NULL);
    if (!window)
    {
        printf("Failed to initialize opengl context");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    printf("Reached end, terminating");
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}