/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *greenhouseList;
    QPushButton *addGreenhouseBtn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *bedList;
    QPushButton *addBedBtn;
    QPushButton *searchBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        greenhouseList = new QListWidget(groupBox);
        greenhouseList->setObjectName("greenhouseList");
        greenhouseList->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout_2->addWidget(greenhouseList);

        addGreenhouseBtn = new QPushButton(groupBox);
        addGreenhouseBtn->setObjectName("addGreenhouseBtn");

        verticalLayout_2->addWidget(addGreenhouseBtn);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        bedList = new QListWidget(groupBox_2);
        bedList->setObjectName("bedList");

        verticalLayout_3->addWidget(bedList);

        addBedBtn = new QPushButton(groupBox_2);
        addBedBtn->setObjectName("addBedBtn");

        verticalLayout_3->addWidget(addBedBtn);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        searchBtn = new QPushButton(centralwidget);
        searchBtn->setObjectName("searchBtn");

        verticalLayout->addWidget(searchBtn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(greenhouseList, addGreenhouseBtn);
        QWidget::setTabOrder(addGreenhouseBtn, bedList);
        QWidget::setTabOrder(bedList, addBedBtn);
        QWidget::setTabOrder(addBedBtn, searchBtn);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\276\320\263\320\276\321\200\320\276\320\264\320\276\320\274", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\275\320\270\320\272\320\270", nullptr));
        addGreenhouseBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\275\320\270\320\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\321\217\320\264\320\272\320\270", nullptr));
        addBedBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\217\320\264\320\272\321\203", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\272\321\203\320\273\321\214\321\202\321\203\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
