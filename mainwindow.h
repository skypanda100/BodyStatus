#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sleepresult.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initUI();
    void initConnect();

private:
    QWidget *m_mainWidget;
    SleepResult *m_sleepResult;
};

#endif // MAINWINDOW_H
