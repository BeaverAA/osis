#include "mainwindow.h"
#include "ui_mainwindow.h"

static int figure=0;
static QColor color = Qt::white;
static bool isDraw = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sw = new SecondWindow();
    sw->show();

    connect(this, &MainWindow::sendMessage, sw, &SecondWindow::GetMessage);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_radioButton_6_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_5_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_4_clicked()
{
    changeState();
}

void MainWindow::on_checkBox_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_2_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_3_clicked()
{
    changeState();
}

void MainWindow::on_radioButton_7_clicked()
{
    changeState();
}

void MainWindow::changeState() {
    if(ui->radioButton->isChecked())
        figure = 1;
    else if(ui->radioButton_2->isChecked())
        figure = 2;
    else if(ui->radioButton_3->isChecked())
        figure = 3;
    else if(ui->radioButton_7->isChecked())
        figure = 4;

    if(ui->radioButton_4->isChecked())
        color = Qt::red;
    else if(ui->radioButton_5->isChecked())
        color = Qt::green;
    else if(ui->radioButton_6->isChecked())
        color = Qt::blue;

    isDraw = ui->checkBox->isChecked();

    emit sendMessage(figure, &color, isDraw);
}
