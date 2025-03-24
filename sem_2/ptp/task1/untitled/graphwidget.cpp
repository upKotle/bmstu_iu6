// graphwidget.cpp
#include "graphwidget.h"
#include <QPainter>
#include <QPen>
#include <QFontMetrics>
#include <numeric> // для std::accumulate

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent) {}

void GraphWidget::setData(const QMap<int, double>& data)
{
    m_data = data;

    // Находим максимальные значения для масштабирования
    maxRam = m_data.isEmpty() ? 0 : m_data.lastKey();
    maxPrice = 0;
    for(const auto &value : m_data) {
        if(value > maxPrice) maxPrice = value;
    }

    update();
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Увеличиваем отступы
    const int margin = 80; // Было 50, теперь 80
    int w = width() - 2 * margin;
    int h = height() - 2 * margin;

    if (w <= 0 || h <= 0 || m_data.isEmpty()) return;

    // Рисуем оси
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(margin, margin, margin, height() - margin); // Ось Y
    painter.drawLine(margin, height() - margin, width() - margin, height() - margin); // Ось X

    // Подписи осей
    QFont font = painter.font();
    font.setPointSize(10); // Увеличиваем размер шрифта
    painter.setFont(font);

    // Подпись оси Y (Цена)
    painter.save();
    painter.translate(margin - 40, height() / 2); // Сдвигаем текст влево
    painter.rotate(-90); // Поворачиваем текст вертикально
    painter.drawText(0, 0, "Цена (RUB)");
    painter.restore();

    // Подпись оси X (ОЗУ)
    painter.drawText(width() / 2 - 40, height() - margin / 2, "ОЗУ (GB)");

    // Масштабирующие коэффициенты
    double xScale = w / static_cast<double>(maxRam);
    double yScale = h / maxPrice;

    // Рисуем сетку и отметки
    QFontMetrics fm(painter.font());
    painter.setPen(QPen(Qt::lightGray, 1, Qt::DotLine));

    // Для оси X (ОЗУ)
    for (auto it = m_data.constBegin(); it != m_data.constEnd(); ++it) {
        int x = margin + static_cast<int>(it.key() * xScale);
        painter.drawLine(x, height() - margin, x, margin);

        // Подписи
        painter.setPen(Qt::black);
        QString label = QString::number(it.key());
        int labelWidth = fm.horizontalAdvance(label);
        painter.drawText(x - labelWidth / 2, height() - margin + 25, label); // Сдвигаем подписи вниз
        painter.setPen(QPen(Qt::lightGray, 1, Qt::DotLine));
    }

    // Для оси Y (Цена)
    for (double price = 0; price <= maxPrice; price += maxPrice / 5) {
        int y = height() - margin - static_cast<int>(price * yScale);
        painter.drawLine(margin, y, width() - margin, y);

        painter.setPen(Qt::black);
        QString label = QString::number(price, 'f', 0);
        int labelWidth = fm.horizontalAdvance(label);
        painter.drawText(margin - labelWidth - 10, y + 5, label); // Сдвигаем подписи влево
        painter.setPen(QPen(Qt::lightGray, 1, Qt::DotLine));
    }

    // Рисуем график
    painter.setPen(QPen(Qt::blue, 2));
    QPoint prevPoint;
    bool first = true;

    for (auto it = m_data.constBegin(); it != m_data.constEnd(); ++it) {
        int x = margin + static_cast<int>(it.key() * xScale);
        int y = height() - margin - static_cast<int>(it.value() * yScale);

        // Точки данных
        painter.drawEllipse(QPoint(x, y), 4, 4);

        // Линии
        if (!first) {
            painter.drawLine(prevPoint, QPoint(x, y));
        }
        prevPoint = QPoint(x, y);
        first = false;
    }
}
