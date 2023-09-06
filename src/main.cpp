#include "Widgets/LauncherWindow.h"
#include "GLFW/glfw3.h"

#include <QApplication>
#include <QCommonStyle>
#include <QStyleFactory>
#include <QMessageBox>

void shutdownGLFW()
{
    glfwTerminate();
}

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    if (!glfwInit())
    {
        QMessageBox::critical(nullptr, "Fatal Error", "Failed to initialize 3D video modes");
        return 1;
    }

    QCommonStyle *style = (QCommonStyle *)QStyleFactory::create( "fusion" );
    QApplication::setStyle( style );

    LauncherWindow w;
    w.show();

    atexit(shutdownGLFW);
    return QApplication::exec();
}
