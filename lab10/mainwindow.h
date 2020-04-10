#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>
#include <QtDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void changeState();
public slots:

signals:
    void sendMessage(int figure, QColor* color, bool isDraw);

private slots:

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_4_clicked();

    void on_checkBox_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SecondWindow *sw;
};
#endif // MAINWINDOW_H
