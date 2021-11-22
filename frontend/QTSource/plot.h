#ifndef PLOT_H
#define PLOT_H

#include <QDialog>
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class Plot;
}

class Plot : public QDialog
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = nullptr);
    ~Plot();

private:
    Ui::Plot *ui;
};

#endif // PLOT_H
