#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
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
    void onSleepDataTriggered();
    void onSleepTriggered(QAction *);
    void onStyleTriggered(QAction *);
    void onPrintTriggered();

private:
    QMenu *m_styleMenu;
    QAction *m_lightStyleAction;
    QAction *m_darkStyleAction;
    QAction *m_printAction;
    QAction *m_sleepDataAction;
    QMenu *m_sleepMenu;
    QAction *m_sleepDistributionAction;
    QAction *m_sleepDurationAction;
    QAction *m_sleepIntervalAction;

    QWidget *m_mainWidget;

    SleepInput *m_sleepInput;
    SleepResult *m_sleepResult;
};

#endif // MAINWINDOW_H
