//
// Created by Chips on 03/09/2023.
//

#include "LauncherWindow.h"

#include <QDir>
#include <QEventLoop>
#include <QGridLayout>
#include <QImageReader>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

LauncherWindow::LauncherWindow( QWidget *parent ) :
        QDialog( parent )
{
    this->setWindowTitle("Launcher");
    this->setFixedSize(QSize(640, 480));

    auto WindowLayout = new QGridLayout(this);

    ResolutionSelector = new QListWidget(this );

    WindowLayout->addWidget(ResolutionSelector, 0, 0, 4, 6 );

    auto pButtonLayout = new QVBoxLayout();

    auto pLaunchButton = new QPushButton( "Launch", this );
    pButtonLayout->addWidget( pLaunchButton );

    auto pExitButton = new QPushButton("Exit", this );
    pButtonLayout->addWidget(pExitButton );

    WindowLayout->addLayout(pButtonLayout, 0, 6, Qt::AlignLeft );

    this->populateResolutionList();
}

void LauncherWindow::populateResolutionList() const
{
    int count;

    const GLFWvidmode* modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);
    const GLFWvidmode* currentmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    auto VideoModesList = new QStringList();

    for (int index = 0; index < count; index++)
    {
        GLFWvidmode vidmode = modes[index];
        if (vidmode.refreshRate != currentmode->refreshRate) {
            continue;
        }
        QString formatString = QString("%1x%2").arg(QString::number(vidmode.width), QString::number(vidmode.height));
        VideoModesList->append(formatString);
    }

    ResolutionSelector->addItems(*VideoModesList);
}
