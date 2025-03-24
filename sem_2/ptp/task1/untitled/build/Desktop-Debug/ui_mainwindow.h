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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLoad;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnSave;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnRemove;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnAdd;
    QSpacerItem *verticalSpacer_5;
    QTableWidget *tableComputers;
    QSplitter *splitter;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineMaxPrice;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineCPU;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spinMinRam;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSpinBox *spinMinHdd;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnShowAll;
    QPushButton *btnFilter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName("btnLoad");

        verticalLayout->addWidget(btnLoad);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");

        verticalLayout->addWidget(btnSave);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");

        verticalLayout->addWidget(btnRemove);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");

        verticalLayout->addWidget(btnAdd);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        tableComputers = new QTableWidget(centralwidget);
        if (tableComputers->columnCount() < 4)
            tableComputers->setColumnCount(4);
        tableComputers->setObjectName("tableComputers");
        tableComputers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableComputers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableComputers->setColumnCount(4);

        horizontalLayout_2->addWidget(tableComputers);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        label_2 = new QLabel(splitter);
        label_2->setObjectName("label_2");
        splitter->addWidget(label_2);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineMaxPrice = new QLineEdit(widget);
        lineMaxPrice->setObjectName("lineMaxPrice");

        horizontalLayout_3->addWidget(lineMaxPrice);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName("widget1");
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        lineCPU = new QLineEdit(widget1);
        lineCPU->setObjectName("lineCPU");

        horizontalLayout_4->addWidget(lineCPU);

        splitter->addWidget(widget1);
        widget2 = new QWidget(splitter);
        widget2->setObjectName("widget2");
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget2);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        spinMinRam = new QSpinBox(widget2);
        spinMinRam->setObjectName("spinMinRam");

        horizontalLayout_5->addWidget(spinMinRam);

        splitter->addWidget(widget2);
        widget3 = new QWidget(splitter);
        widget3->setObjectName("widget3");
        horizontalLayout_6 = new QHBoxLayout(widget3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget3);
        label->setObjectName("label");

        horizontalLayout_6->addWidget(label);

        spinMinHdd = new QSpinBox(widget3);
        spinMinHdd->setObjectName("spinMinHdd");

        horizontalLayout_6->addWidget(spinMinHdd);

        splitter->addWidget(widget3);
        widget4 = new QWidget(splitter);
        widget4->setObjectName("widget4");
        horizontalLayout_7 = new QHBoxLayout(widget4);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnShowAll = new QPushButton(widget4);
        btnShowAll->setObjectName("btnShowAll");

        horizontalLayout_7->addWidget(btnShowAll);

        btnFilter = new QPushButton(widget4);
        btnFilter->setObjectName("btnFilter");

        horizontalLayout_7->addWidget(btnFilter);

        splitter->addWidget(widget4);

        horizontalLayout_8->addWidget(splitter);

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
        btnLoad->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnRemove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\320\274: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\206\320\265\320\275\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\236\320\227\320\243", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 HDD", nullptr));
        btnShowAll->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\216", nullptr));
        btnFilter->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
