#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sleepinput.h"
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

private slots:
    void onSleepTriggered();
    void onLightStyleTriggered();
    void onDarkStyleTriggered();
    void onPrintTriggered();

private:
    QAction *m_lightStyleAction;
    QAction *m_darkStyleAction;
    QAction *m_printAction;
    QAction *m_sleepAction;

    QWidget *m_mainWidget;

    SleepInput *m_sleepInput;
    SleepResult *m_sleepResult;
};

#endif // MAINWINDOW_H
