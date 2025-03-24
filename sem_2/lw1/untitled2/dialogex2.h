#pragma once

#include <QDialog>
#include "ui_DialogEx2.h"

class DialogEx2 : public QDialog, public Ui::DialogEx2
{
    Q_OBJECT
public:
    DialogEx2(QWidget* parent = 0);
private slots:
    void onExitClicked();
};
