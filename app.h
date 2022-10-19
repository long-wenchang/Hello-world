#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

protected:
    void button_Init();

private slots:
    void realtime_Slot();
    void button_Slot();

private:
    Ui::App *ui;

    QTimer *dataTimer;

    QCustomPlot *customPlot;

    QVector<double> y, x;
    int index = 0;
};
#endif // APP_H
