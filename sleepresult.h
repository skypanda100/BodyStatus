#ifndef SLEEPRESULT
#define SLEEPRESULT

#include <QtWidgets>
#include <sstream>
#include <algorithm>
#include "qchartviewer.h"
#include "style.h"
#include "sleep.h"

using namespace std;

#define LATENT_COLOR    0x804088aa
#define DEEP_COLOR      0x8000608d
#define AWAKE_COLOR     0x80ff69b4

typedef struct DataGantt{
    double lowlimit;
    double uplimit;
    double *labels;
    int label_len;
    double *taskNo;
    int task_len;
    double *startDate;
    int startDate_len;
    double *endDate;
    int endDate_len;
    int *colors;
    int color_len;
}DataGantt;

typedef struct DataStack{
    double *labels;
    int label_len;
    double *sleepSums;
    int sleepSum_len;
    double *deepSleepSums;
    int deepSleepSum_len;
    double *awakeSums;
    int awakeSum_len;
}DataStack;

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
    void makeChart();
    BaseChart *sleepGantt(int, int, QList<Bean::Sleep>);
    void makeDataGantt(DataGantt *, QList<Bean::Sleep>);

    BaseChart *sleepStack(int, int, QList<Bean::Sleep>);
    void makeDataStack(DataStack *, QList<Bean::Sleep>);

private:
    QChartViewer *m_ChartViewer;
    QList<Bean::Sleep> m_sleepLst01;
    QList<Bean::Sleep> m_sleepLst02;

};

#endif // SLEEPRESULT

