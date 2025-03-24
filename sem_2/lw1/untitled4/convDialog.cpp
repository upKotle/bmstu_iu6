#include <QString>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "convDialog.h"

bool prev = true; // переменная для обозначения предыдущего рекистра букв
QString big = "QWERTYUIOPASDFGHJKLZXCVBNM";
QString small = "qwertyuiopasdfghjklzxcvbnm";

ConvDialog::ConvDialog(QWidget* parent)
{
    m_pLineEdit = new QLineEdit(this); //создаем строку для ввода

    m_pTextEdit = new QTextEdit(this); //создаем текстовое поле
    m_pTextEdit->setReadOnly(true); //устанавливаем режим только для чтения


    // создание схемы выравнивания
    QVBoxLayout* dlgLayout = new QVBoxLayout();

    //создание кнопки
    QPushButton* button = new QPushButton("Convert");

    // связь сигнала о нажатии кнопки со слотом clicked
    connect(button, SIGNAL(clicked()), this, SLOT(clicked()));
    // связь сигнала о завершении ввода строки со слотом input
    connect(m_pLineEdit, SIGNAL(editingFinished()), this, SLOT(input()));

    // добавление виджетов в схему выравнивания
    dlgLayout->addWidget(m_pLineEdit);
    dlgLayout->addWidget(button);
    dlgLayout->addWidget(m_pTextEdit);

    // связь схемы выравнивания с формой
    setLayout(dlgLayout);
}

// функция для смены регистра строки
QString convert(QString s)
{
    if (prev) {
        s = s.toUpper();
    }
    else {
        s = s.toLower();
    }
    prev = !prev;
    return s;
}

// обработка нажатия кнопки
void ConvDialog::clicked()
{

    QString s = convert(m_pLineEdit->text());
    if (prev) {
        m_pTextEdit->insertPlainText("all lower: ");
    }
    else {
        m_pTextEdit->insertPlainText("ALL UPPER: ");
    }
    m_pTextEdit->insertPlainText(s);
    m_pTextEdit->insertPlainText("\n");
}

// обработка завершения ввода строки
void ConvDialog::input()
{
    m_pTextEdit->insertPlainText("input: ");
    m_pTextEdit->insertPlainText(m_pLineEdit->text());
    m_pTextEdit->insertPlainText("\n");
}
