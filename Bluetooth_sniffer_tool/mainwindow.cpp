#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList listOfStrings {"Was", "Geht"};

    ui->cbBluetoothDevices->addItems(listOfStrings);
    connect(ui->cbBluetoothDevices, QOverload<int>::of(&QComboBox::activated), this, [](){qDebug() << "Pressed";});
}

MainWindow::~MainWindow()
{
    delete ui;
}

