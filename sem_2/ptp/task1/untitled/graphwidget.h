// graphwidget.h
#include <QWidget>
#include <QMap>

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);
    void setData(const QMap<int, double>& data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<int, double> m_data;
    int maxRam = 0;
    double maxPrice = 0;
};
