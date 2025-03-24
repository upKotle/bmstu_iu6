#ifndef CONVDIALOG_H
#define CONVDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QSignalMapper>

class ConvDialog : public QDialog
{
    Q_OBJECT

public:
    ConvDialog(QWidget* parent = 0);
    virtual ~ConvDialog() {};
protected:
    QLineEdit* m_pLineEdit;
    QTextEdit* m_pTextEdit;
private slots:
    void clicked();
    void input();
};

#endif // CONVDIALOG_H
