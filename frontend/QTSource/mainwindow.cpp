#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plot.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <QVector>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_plotButton_clicked()));
    connect(timer, SIGNAL(timeout()), this, SLOT(on_plotHumidity()));
    timer->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_alertButton_clicked()
{
    Plot pd(this);
    pd.exec();
}

void MainWindow::on_downloadDataFromFile()
{
    system("pscp -pw \"raspberry\" pi@192.168.0.20:/home/pi/backend/temp_values.txt C:/Users/JFMuller/Documents/Projects/remote_plant_monitor/frontend/QTSource");
}

void MainWindow::on_plotButton_clicked()
{
    int value;
    int maxTemp = 0;
    int minTemp = 100;
    std::vector<double> x;
    std::vector<double> y;
    std::ifstream file("C:/Users/JFMuller/Documents/Projects/remote_plant_monitor/frontend/QTSource/temp_values.txt");
    if(file.is_open())
    {
        std::cout << "file open";
        while(file >> value)
        {
            maxTemp = (maxTemp < value ? value : maxTemp);
            minTemp = (minTemp > value ? value : minTemp);
            std::cout << value;
            y.push_back(value);
        }
    }
    else
    {
        std::cout << "file NOT open";
    }

    // generate some data:
    for (size_t i=0; i < y.size(); ++i)
    {
      x.push_back(i); // let's plot a quadratic function
    }

    QVector<double> xx;
    QVector<double> yy;
    for(size_t j = 0; j < y.size(); j++){
        yy.push_back(y[j]);
    }
    for(size_t j = 0; j < x.size(); j++){
        xx.push_back(x[j]);
    }

    // create graph and assign data to it:
    ui->tempPlot->addGraph();
    ui->tempPlot->graph(0)->setData(xx, yy);
    // give the axes some labels:
    ui->tempPlot->xAxis->setLabel("Time (s)");
    ui->tempPlot->yAxis->setLabel("Temperature");
    // set axes ranges, so we see all data:
    ui->tempPlot->xAxis->setRange(0, x.size());
    ui->tempPlot->yAxis->setRange((minTemp - 10), (maxTemp + 10));
    ui->tempPlot->replot();
}

void MainWindow::on_plotHumidity()
{
    int value;
    int maxTemp = 0;
    int minTemp = 100;
    std::vector<double> x;
    std::vector<double> y;
    std::ifstream file("C:/Users/JFMuller/Documents/Projects/remote_plant_monitor/frontend/QTSource/humidity_values.txt");
    if(file.is_open())
    {
        std::cout << "file open";
        while(file >> value)
        {
            maxTemp = (maxTemp < value ? value : maxTemp);
            minTemp = (minTemp > value ? value : minTemp);
            std::cout << value;
            y.push_back(value);
        }
    }
    else
    {
        std::cout << "file NOT open";
    }

    // generate some data:
    for (size_t i=0; i < y.size(); ++i)
    {
      x.push_back(i); // let's plot a quadratic function
    }

    QVector<double> xx;
    QVector<double> yy;
    for(size_t j = 0; j < y.size(); j++){
        yy.push_back(y[j]);
    }
    for(size_t j = 0; j < x.size(); j++){
        xx.push_back(x[j]);
    }

    // create graph and assign data to it:
    ui->humidityPlot->addGraph();
    ui->humidityPlot->graph(0)->setData(xx, yy);
    // give the axes some labels:
    ui->humidityPlot->xAxis->setLabel("Time (s)");
    ui->humidityPlot->yAxis->setLabel("Humidity");
    // set axes ranges, so we see all data:
    ui->humidityPlot->xAxis->setRange(0, x.size());
    ui->humidityPlot->yAxis->setRange((minTemp - 10), (maxTemp + 10));
    ui->humidityPlot->replot();
}

