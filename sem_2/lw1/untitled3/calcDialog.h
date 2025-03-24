#ifndef CALCDIALOD_H
#define CALCDIALOD_H

#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>

class CalcDialog : public QDialog
{
    Q_OBJECT
public:
    CalcDialog(QWidget* parent = 0);
    virtual ~CalcDialog() {};
protected:
    QSignalMapper* m_pSignalMapper;
    QLineEdit* m_pLineEdit;
    double m_Val;
    int m_Op;
    bool m_bPerf;
    void initNum();
    double getNumEdit();
    void setNumEdit(double);

    void calcPrevOp(int curOp);


    void checkOpPerf();
private slots:
    void clicked(int id);
};

#endif // CALCDIALOD_H
