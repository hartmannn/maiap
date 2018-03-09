/********************************************************************************
** Form generated from reading UI file 'refinement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFINEMENT_H
#define UI_REFINEMENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "glviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionClear;
    QAction *actionLoad;
    QAction *actionBox;
    QAction *actionRefine;
    QAction *actionCircle;
    QAction *actionDelaunay_conforming;
    QAction *actionGabriel_conforming;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    GlViewer *viewer;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuData;
    QMenu *menuAlgorithms;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(798, 629);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/fileNew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/fileOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon1);
        actionBox = new QAction(MainWindow);
        actionBox->setObjectName(QStringLiteral("actionBox"));
        actionRefine = new QAction(MainWindow);
        actionRefine->setObjectName(QStringLiteral("actionRefine"));
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        actionDelaunay_conforming = new QAction(MainWindow);
        actionDelaunay_conforming->setObjectName(QStringLiteral("actionDelaunay_conforming"));
        actionGabriel_conforming = new QAction(MainWindow);
        actionGabriel_conforming->setObjectName(QStringLiteral("actionGabriel_conforming"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        viewer = new GlViewer(centralwidget);
        viewer->setObjectName(QStringLiteral("viewer"));
        viewer->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(viewer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QStringLiteral("menuData"));
        menuAlgorithms = new QMenu(menubar);
        menuAlgorithms->setObjectName(QStringLiteral("menuAlgorithms"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuAlgorithms->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuData->addAction(actionBox);
        menuData->addAction(actionCircle);
        menuData->addAction(actionClear);
        menuAlgorithms->addAction(actionDelaunay_conforming);
        menuAlgorithms->addAction(actionGabriel_conforming);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionRefine);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CGAL - 2D Delaunay refinement", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionClear->setStatusTip(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("MainWindow", "Space", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionLoad->setStatusTip(QApplication::translate("MainWindow", "Load PSLG", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionBox->setText(QApplication::translate("MainWindow", "Box", Q_NULLPTR));
        actionRefine->setText(QApplication::translate("MainWindow", "Refine", Q_NULLPTR));
        actionCircle->setText(QApplication::translate("MainWindow", "Circle", Q_NULLPTR));
        actionDelaunay_conforming->setText(QApplication::translate("MainWindow", "Delaunay conforming", Q_NULLPTR));
        actionGabriel_conforming->setText(QApplication::translate("MainWindow", "Gabriel conforming", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        menuAlgorithms->setTitle(QApplication::translate("MainWindow", "Algorithms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFINEMENT_H
