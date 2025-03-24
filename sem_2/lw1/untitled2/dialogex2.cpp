#include "dialogex2.h"
#include <QMessageBox>


DialogEx2::DialogEx2(QWidget * parent) :QDialog(parent)
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(onExitClicked()));
}

void DialogEx2::onExitClicked()
{

    if (QMessageBox::question(this, QString(), "Exit?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        exit(0);
    }
    else {
        show();
    }
}
