#include "plot.h"
#include "ui_plot.h"
#include <QChart>

Plot::Plot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plot)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Flower");


    *set0 << 60 << 50 << 12 << 67 << 13 << 23;


    QBarSeries *series = new QBarSeries();
    series->append(set0);


    QChart *chart = new QChart();
    chart-> addSeries(series);
    chart->setTitle("Aletrs Over the Week");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList days;
    days << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX ->append(days);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    axisY->setRange(0, 20);


    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalframe);


}

Plot::~Plot()
{
    delete ui;
}
