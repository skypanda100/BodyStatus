#ifndef SLEEPRESULT
#define SLEEPRESULT

#include <QtWidgets>
#include "qchartviewer.h"
#include "style.h"
#include "sleep.h"

#define LATENT_COLOR    0x8cc665
#define DEEP_COLOR      0x44a340
#define AWAKE_COLOR     0xff9900
class SleepResult : public QWidget{
    Q_OBJECT
public:
    SleepResult(QWidget *parent = NULL);
    ~SleepResult();

private:
    void initUI();
    void initConnect();
    void makeData();
    void makeChart(double lowlimit, double uplimit, double *labels, int label_len, double *taskNo, int task_len, double *startDate, int startDate_len, double *endDate, int endDate_len, int *colors, int color_len);
    BaseChart *sleep(double lowlimit, double uplimit, double *labels, int label_len, double *taskNo, int task_len, double *startDate, int startDate_len, double *endDate, int endDate_len, int *colors, int color_len);

private:
    QChartViewer *m_ChartViewer;
    QList<Bean::Sleep> m_sleepLst;
};

#endif // SLEEPRESULT

