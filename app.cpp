#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);

    customPlot = ui->customPlot;

    customPlot->setLocale(QLocale(QLocale::Chinese, QLocale::UnitedKingdom));

    customPlot->addGraph();
    // customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    customPlot->graph()->setPen(QPen(QColor(225, 225, 20, 255)));
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    customPlot->graph()->setName("Left maxwell function");
    // customPlot->graph()->setBrush(QBrush(QColor(225, 225, 20, 255)));

    // set a more compact font size for bottom and left axis tick labels:
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    customPlot->xAxis->setLabel("Date");
    customPlot->yAxis->setLabel("Random wobbly lines value");
    // make top and right axes visible but without ticks and labels:
    customPlot->xAxis2->setVisible(false);
    customPlot->yAxis2->setVisible(false);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);

    customPlot->xAxis->setRange(0, 100);
    customPlot->yAxis->setRange(0, 100);

    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QColor(255, 255, 255, 150));
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    dataTimer = new QTimer(this);
    connect(dataTimer, &QTimer::timeout, this, &App::realtime_Slot);
    // connect(ui->pushButton, &QPushButton::clicked, this, App::realtime_Slot());
    dataTimer->start(1000);

    this->button_Init();
}

App::~App()
{
    delete ui;
}

void App::realtime_Slot()
{
//    QPushButton *button = qobject_cast<QPushButton*>(sender());
//    if (button == ui->pushButton)
//    {
//        x.append(index);
//        y.append(rand()%75);
//        index++;
//        customPlot->graph()->addData(x, y);
//    }
    x.append(index);
    y.append(rand()%75);
    index++;
    customPlot->graph()->addData(x, y);
    customPlot->replot();
}

void App::button_Slot()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button == ui->pushButton)
    {
        customPlot->xAxis->setRange(0, 100);
        customPlot->yAxis->setRange(0, 100);
        customPlot->replot();
        //qDebug() << "111";
    }
}

void App::button_Init()
{
    connect(ui->pushButton, &QPushButton::clicked, this, &App::button_Slot);
}



























