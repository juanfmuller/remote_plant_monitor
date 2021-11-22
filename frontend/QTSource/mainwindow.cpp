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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Plot_Button_clicked()
{
    Plot pd(this);
    pd.exec();
}


void MainWindow::on_Get_Value_clicked()
{
    /*QFile file("C:/Users/baddo/OneDrive/Documents/Software Design 2/Textsfilesssssss");
    if(!file.open(QIODevice::ReadOnly))
    QMessageBox::information(0,"info", file.errorString());

    QTextStream in(&file);

    ui->GetValue->setText(in.readAll());  //Text browser name is Getvalues to send the file */

    using namespace std;
    ifstream file;
    file.open("C:/Users/baddo/OneDrive/Documents/Software Design 2/Textsfilesssssss/firstText.txt");
    if(!file) cout << "file not found" << endl;
    string strArray[100];
    string line;
    string ph;
    int i=0;
    while(getline(file, line)){
        strArray[i] = line;
        cout << strArray[i] << endl;
        ph = ph + strArray[i] + "\n";
        ++i;
    }
  //  ui->GetValue->setPlainText(QString::fromStdString(ph));

}
