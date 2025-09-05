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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *x1Edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *y1Edit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *x2Edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *y2Edit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *scalarEdit;
    QVBoxLayout *verticalLayout_4;
    QPushButton *multiplyButton;
    QPushButton *sumButton;
    QPushButton *equalButton;
    QPushButton *subtractButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        x1Edit = new QLineEdit(centralwidget);
        x1Edit->setObjectName("x1Edit");

        horizontalLayout_2->addWidget(x1Edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        y1Edit = new QLineEdit(centralwidget);
        y1Edit->setObjectName("y1Edit");

        horizontalLayout_4->addWidget(y1Edit);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        x2Edit = new QLineEdit(centralwidget);
        x2Edit->setObjectName("x2Edit");

        horizontalLayout->addWidget(x2Edit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        horizontalLayout_3->addWidget(label_7);

        y2Edit = new QLineEdit(centralwidget);
        y2Edit->setObjectName("y2Edit");

        horizontalLayout_3->addWidget(y2Edit);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        scalarEdit = new QLineEdit(centralwidget);
        scalarEdit->setObjectName("scalarEdit");

        verticalLayout_3->addWidget(scalarEdit);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName("multiplyButton");

        verticalLayout_4->addWidget(multiplyButton);

        sumButton = new QPushButton(centralwidget);
        sumButton->setObjectName("sumButton");

        verticalLayout_4->addWidget(sumButton);

        equalButton = new QPushButton(centralwidget);
        equalButton->setObjectName("equalButton");

        verticalLayout_4->addWidget(equalButton);

        subtractButton = new QPushButton(centralwidget);
        subtractButton->setObjectName("subtractButton");

        verticalLayout_4->addWidget(subtractButton);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\260\320\273\321\217\321\200", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\274\320\275\320\276\320\266\320\270\321\202\321\214 \320\275\320\260 \321\201\320\272\320\260\320\273\321\217\321\200", nullptr));
        sumButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\266\320\270\321\202\321\214", nullptr));
        equalButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\200\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\276", nullptr));
        subtractButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\265\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
