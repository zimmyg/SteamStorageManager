/********************************************************************************
** Form generated from reading UI file 'ssm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSM_H
#define UI_SSM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ssmClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *fastStorageLabel;
    QLabel *massStorageLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *moveToFastButton;
    QPushButton *moveToMassButton;
    QSpacerItem *verticalSpacer_2;
    QListView *fastStorageView;
    QListView *massStorageView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ssmClass)
    {
        if (ssmClass->objectName().isEmpty())
            ssmClass->setObjectName(QStringLiteral("ssmClass"));
        ssmClass->resize(1013, 624);
        centralWidget = new QWidget(ssmClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fastStorageLabel = new QLabel(centralWidget);
        fastStorageLabel->setObjectName(QStringLiteral("fastStorageLabel"));
        fastStorageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fastStorageLabel, 0, 0, 1, 1);

        massStorageLabel = new QLabel(centralWidget);
        massStorageLabel->setObjectName(QStringLiteral("massStorageLabel"));
        massStorageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(massStorageLabel, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moveToFastButton = new QPushButton(centralWidget);
        moveToFastButton->setObjectName(QStringLiteral("moveToFastButton"));

        verticalLayout->addWidget(moveToFastButton);

        moveToMassButton = new QPushButton(centralWidget);
        moveToMassButton->setObjectName(QStringLiteral("moveToMassButton"));

        verticalLayout->addWidget(moveToMassButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        fastStorageView = new QListView(centralWidget);
        fastStorageView->setObjectName(QStringLiteral("fastStorageView"));
        fastStorageView->setFrameShape(QFrame::Box);
        fastStorageView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fastStorageView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fastStorageView->setIconSize(QSize(10, 10));

        gridLayout->addWidget(fastStorageView, 1, 0, 1, 1);

        massStorageView = new QListView(centralWidget);
        massStorageView->setObjectName(QStringLiteral("massStorageView"));
        massStorageView->setFrameShape(QFrame::Box);
        massStorageView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        massStorageView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        massStorageView->setIconSize(QSize(10, 10));

        gridLayout->addWidget(massStorageView, 1, 2, 1, 1);

        ssmClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ssmClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        ssmClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ssmClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ssmClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuOptions->menuAction());

        retranslateUi(ssmClass);
        QObject::connect(fastStorageView, SIGNAL(clicked(QModelIndex)), massStorageView, SLOT(clearSelection()));
        QObject::connect(massStorageView, SIGNAL(clicked(QModelIndex)), fastStorageView, SLOT(clearSelection()));

        QMetaObject::connectSlotsByName(ssmClass);
    } // setupUi

    void retranslateUi(QMainWindow *ssmClass)
    {
        ssmClass->setWindowTitle(QApplication::translate("ssmClass", "Steam StorageManager", 0));
        fastStorageLabel->setText(QApplication::translate("ssmClass", "Fast Storage: ", 0));
        massStorageLabel->setText(QApplication::translate("ssmClass", "Mass Storage: ", 0));
        moveToFastButton->setText(QApplication::translate("ssmClass", "<--", 0));
        moveToMassButton->setText(QApplication::translate("ssmClass", "-->", 0));
        menuFile->setTitle(QApplication::translate("ssmClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("ssmClass", "Help", 0));
        menuOptions->setTitle(QApplication::translate("ssmClass", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class ssmClass: public Ui_ssmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSM_H
