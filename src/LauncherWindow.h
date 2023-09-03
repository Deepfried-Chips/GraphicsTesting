//
// Created by Chips on 03/09/2023.
//

#ifndef GRAPHICSTESTING_LAUNCHERWINDOW_H
#define GRAPHICSTESTING_LAUNCHERWINDOW_H

#include <QMainWindow>

class LauncherWindow : public QMainWindow
        {
            Q_OBJECT

        public:
            LauncherWindow(QWidget *parent = nullptr);
            ~LauncherWindow();
        };

#endif //GRAPHICSTESTING_LAUNCHERWINDOW_H

