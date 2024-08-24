#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>       /* time */
#include <ctype.h>
#include <ctime>
#include <stdio.h>
#include <QMessageBox>
#include <QPixmap>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(clockrun()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clockrun()
{

    QFile file("/proc/uptime");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();
        file.close();

        QStringList uptimeData = line.split(" ");
        double uptimeSeconds = uptimeData[0].toDouble();

        int days = uptimeSeconds / (60 * 60 * 24);
        int hours = (int(uptimeSeconds) % (60 * 60 * 24)) / (60 * 60);
        int minutes = (int(uptimeSeconds) % (60 * 60)) / 60;


    ui->lcdNumber->display(days);


    ui->lcdNumber_2->display(hours);


    ui->lcdNumber_3->display(minutes);

    }

}

