#ifndef SLEEPRESULT
#define SLEEPRESULT

#include <QtWidgets>
#include "qchartviewer.h"
#include "style.h"

class SleepResult : public QWidget{
    Q_OBJECT
public:
    SleepResult(QWidget *parent = NULL);
    ~SleepResult();

private:
    void initUI();
    void initConnect();
    void makeChart();
    BaseChart *sleep();

private:
    QChartViewer *m_ChartViewer;

};

#endif // SLEEPRESULT

