#include <iostream>
#include "glad/gl.h"
#include "LauncherWindow.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <QApplication>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    LauncherWindow w;
    w.show();
    return QApplication::exec();
}
