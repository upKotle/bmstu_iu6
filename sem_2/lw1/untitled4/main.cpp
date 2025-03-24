#include <QApplication>
#include "convDialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ConvDialog* dialog = new ConvDialog();

    dialog->show();
    return app.exec();
}
