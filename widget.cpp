#include "widget.h"
#include "ui_widget.h"
#include <qcustomplot.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph()->setPen(QPen(Qt::green));
//    ui->customPlot->graph()->setBrush(QBrush(QColor(Qt::green).lighter(200)));
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
        x[i] = i;
        y0[i] = i;
        //        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
    }

    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->yAxis->setLabel("PPM");

    ui->customPlot->setInteractions(QCP::iRangeDrag |
                                    QCP::iRangeZoom |
                                    QCP::iSelectPlottables);

    //    ui->customPlot->xAxis2->setVisible(true);
    //    ui->customPlot->xAxis2->setTickLabels(false);
    //    ui->customPlot->yAxis2->setVisible(true);
    //    ui->customPlot->yAxis2->setTickLabels(false);

    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),
            ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),
            ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    ui->customPlot->graph(0)->setData(x, y0);
    ui->customPlot->graph(0)->rescaleAxes();

    ui->customPlot->replot();
}

Widget::~Widget()
{
    delete ui;
}

