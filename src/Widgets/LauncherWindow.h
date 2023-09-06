//
// Created by Chips on 03/09/2023.
//

#ifndef GRAPHICSTESTING_LAUNCHERWINDOW_H
#define GRAPHICSTESTING_LAUNCHERWINDOW_H

#include <QDialog>
#include <QListWidget>

class LauncherWindow : public QDialog
{
    public:
        explicit LauncherWindow( QWidget *parent = nullptr );
        void populateResolutionList() const;

    public:
        QListWidget *ResolutionSelector;
};
#endif //GRAPHICSTESTING_LAUNCHERWINDOW_H

