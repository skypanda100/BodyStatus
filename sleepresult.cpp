#include "sleepresult.h"

SleepResult::SleepResult(QWidget *parent)
    :QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

SleepResult::~SleepResult(){
    delete m_ChartViewer;
}

void SleepResult::onSearch(QList<Bean::Sleep> sleepLst){
    this->m_sleepLst.clear();
    this->m_sleepLst = sleepLst;
    this->makeData();
}

void SleepResult::onStyle(){
    this->makeData();
}

void SleepResult::initUI(){
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();
    int MAINWIDTH = clientRect.width();
    int MAINHEIGHT = clientRect.height() - 60;
    this->setFixedSize(MAINWIDTH, MAINHEIGHT);

    m_ChartViewer = new QChartViewer(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(2, 2, 2, 2);
    mainLayout->addWidget(m_ChartViewer);

    this->setLayout(mainLayout);

    /*
    //test
    for(int i = 0;i < 30;i++){
        QDateTime dateTime = QDateTime::currentDateTime().addDays(i);
        Bean::Sleep sleep;
        sleep.setDate(Chart::chartTime2(dateTime.toTime_t()));
        QDateTime startDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.toString("yyyy-MM-dd")).arg("23:00")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setStart(Chart::chartTime2(startDateTime.toTime_t()));
        QDateTime endDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.addDays(1).toString("yyyy-MM-dd")).arg("07:32")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setEnd(Chart::chartTime2(endDateTime.toTime_t()));

        QDateTime deepStartDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.addDays(1).toString("yyyy-MM-dd")).arg("01:02")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setDeepStart01(Chart::chartTime2(deepStartDateTime.toTime_t()));
        QDateTime deepEndDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.addDays(1).toString("yyyy-MM-dd")).arg("02:32")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setDeepEnd01(Chart::chartTime2(deepEndDateTime.toTime_t()));

        QDateTime awakeStartDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.addDays(1).toString("yyyy-MM-dd")).arg("03:02")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setAwakeStart01(Chart::chartTime2(awakeStartDateTime.toTime_t()));
        QDateTime awakeEndDateTime = QDateTime::fromString(
                    QString("%1 %2").arg(dateTime.addDays(1).toString("yyyy-MM-dd")).arg("03:32")
                    ,"yyyy-MM-dd hh:mm");
        sleep.setAwakeEnd01(Chart::chartTime2(awakeEndDateTime.toTime_t()));

        m_sleepLst.append(sleep);
    }
    this->makeData();
    */
}

void SleepResult::initConnect(){
}

void SleepResult::makeData(){
    QList<double> labels;
    QList<double> taskNos;
    QList<double> startDates;
    QList<double> endDates;
    QList<int> colors;
    int sleepCount = m_sleepLst.count();
    for(int i = 0;i < sleepCount;i++){
        Bean::Sleep sleep = m_sleepLst[i];

        //date
        labels.append(sleep.date());

        //latent sleep
        startDates.append(sleep.start());
        endDates.append(sleep.end());
        taskNos.append(i);
        colors.append(LATENT_COLOR);

        //deep sleep
        if(sleep.deepStart01() != 0){
            startDates.append(sleep.deepStart01());
            endDates.append(sleep.deepEnd01());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart02() != 0){
            startDates.append(sleep.deepStart02());
            endDates.append(sleep.deepEnd02());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart03() != 0){
            startDates.append(sleep.deepStart03());
            endDates.append(sleep.deepEnd03());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart04() != 0){
            startDates.append(sleep.deepStart04());
            endDates.append(sleep.deepEnd04());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart05() != 0){
            startDates.append(sleep.deepStart05());
            endDates.append(sleep.deepEnd05());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart06() != 0){
            startDates.append(sleep.deepStart06());
            endDates.append(sleep.deepEnd06());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart07() != 0){
            startDates.append(sleep.deepStart07());
            endDates.append(sleep.deepEnd07());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart08() != 0){
            startDates.append(sleep.deepStart08());
            endDates.append(sleep.deepEnd08());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart09() != 0){
            startDates.append(sleep.deepStart09());
            endDates.append(sleep.deepEnd09());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }
        if(sleep.deepStart10() != 0){
            startDates.append(sleep.deepStart10());
            endDates.append(sleep.deepEnd10());
            taskNos.append(i);
            colors.append(DEEP_COLOR);
        }

        //awake
        if(sleep.awakeStart01() != 0){
            startDates.append(sleep.awakeStart01());
            endDates.append(sleep.awakeEnd01());
            taskNos.append(i);
            colors.append(AWAKE_COLOR);
        }
        if(sleep.awakeStart02() != 0){
            startDates.append(sleep.awakeStart02());
            endDates.append(sleep.awakeEnd02());
            taskNos.append(i);
            colors.append(AWAKE_COLOR);
        }
        if(sleep.awakeStart03() != 0){
            startDates.append(sleep.awakeStart03());
            endDates.append(sleep.awakeEnd03());
            taskNos.append(i);
            colors.append(AWAKE_COLOR);
        }
        if(sleep.awakeStart04() != 0){
            startDates.append(sleep.awakeStart04());
            endDates.append(sleep.awakeEnd04());
            taskNos.append(i);
            colors.append(AWAKE_COLOR);
        }
    }

    double *c_labels = new double[labels.count()];
    double *c_taskNos = new double[taskNos.count()];
    double *c_startDates = new double[startDates.count()];
    double *c_endDates = new double[endDates.count()];
    int *c_colors = new int[colors.count()];
    double lowlimit = 0;
    double uplimit = 0;

    int index = 0;
    for(double label : labels){
        c_labels[index] = label;
        index++;
    }

    index = 0;
    for(double taskNo : taskNos){
        c_taskNos[index] = taskNo;
        index++;
    }

    index = 0;
    for(double startDate : startDates){
        if(lowlimit == 0){
            lowlimit = startDate;
        }else{
            if(lowlimit > startDate){
                lowlimit = startDate;
            }
        }
        c_startDates[index] = startDate;
        index++;
    }

    index = 0;
    for(double endDate : endDates){
        if(uplimit == 0){
            uplimit = endDate;
        }else{
            if(uplimit < endDate){
                uplimit = endDate;
            }
        }
        c_endDates[index] = endDate;
        index++;
    }

    index = 0;
    for(double color : colors){
        c_colors[index] = color;
        index++;
    }

    makeChart(lowlimit, uplimit
              , c_labels, labels.count()
              , c_taskNos, taskNos.count()
              , c_startDates, startDates.count()
              , c_endDates, endDates.count()
              , c_colors, colors.count());

    delete c_labels;
    delete c_taskNos;
    delete c_startDates;
    delete c_endDates;
    delete c_colors;
}

void SleepResult::makeChart(double lowlimit, double uplimit
                            , double *labels, int label_len
                            , double *taskNo, int task_len
                            , double *startDate, int startDate_len
                            , double *endDate, int endDate_len
                            , int *colors, int color_len){
    if(m_ChartViewer->getChart() != NULL){
        delete m_ChartViewer->getChart();
    }
    if(!(label_len == 0 || task_len == 0 || startDate_len == 0 || endDate_len == 0 || color_len == 0)){
        m_ChartViewer->setChart(sleep(lowlimit, uplimit
                                      , labels, label_len
                                      , taskNo, task_len
                                      , startDate, startDate_len
                                      , endDate, endDate_len
                                      , colors, color_len));
        m_ChartViewer->updateDisplay();
    }
}

BaseChart *SleepResult::sleep(double lowlimit, double uplimit
                              , double *labels, int label_len
                              , double *taskNo, int task_len
                              , double *startDate, int startDate_len
                              , double *endDate, int endDate_len
                              , int *colors, int color_len){

    XYChart *c = new XYChart(this->width(), this->height() + 60, GET_STYLE().main_bg_color, -1, 0);

    c->setPlotArea(40, 20, this->width() - 40, this->height() - 60
                   , GET_STYLE().plot_bg_color, -1
                   , -1
                   , GET_STYLE().grid_color
                   , Chart::Transparent
        )->setGridWidth(1, 1, 1, 1);

    c->swapXY();

    c->yAxis()->setDateScale(lowlimit - 600, uplimit + 600, 600);

    c->yAxis()->setMultiFormat(Chart::StartOfHourFilter(), "<*font=arialbd.ttf*>{value|h:n}"
                , Chart::StartOfMinuteFilter(), "<*font=arialbd.ttf*>{value|n}");

    c->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c->setYAxisOnRight();

    c->xAxis()->setLabels(DoubleArray(labels, label_len));

    c->xAxis()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c->xAxis()->setReverse();

    c->xAxis()->setTickOffset(0.5);

    c->xAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    BoxWhiskerLayer *layer = c->addBoxWhiskerLayer2(DoubleArray(startDate, startDate_len), DoubleArray(endDate, endDate_len)
                                                    , DoubleArray(), DoubleArray()
                                                    , DoubleArray(), IntArray(colors, color_len));
    layer->setXData(DoubleArray(taskNo, task_len));
    layer->setBorderColor(Chart::Transparent);

    layer->setDataWidth(c->getPlotArea()->getHeight() / label_len * 2 / 3);

    c->makeChart();

    return c;
}
