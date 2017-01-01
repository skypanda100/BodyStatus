#ifndef SLEEPRESULT
#define SLEEPRESULT

#include <QtWidgets>
#include "qchartviewer.h"
#include "style.h"
#include "sleep.h"

#define LATENT_COLOR    0x998cc665
#define DEEP_COLOR      0x5044a340
#define AWAKE_COLOR     0x99ff9900
class SleepResult : public QWidget{
    Q_OBJECT
public:
    SleepResult(QWidget *parent = NULL);
    ~SleepResult();

public slots:
    void onSearch(QList<Bean::Sleep>);
    void onStyle();

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

