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

    QList<double> sleepSums;
    QList<double> deepSleepSums;
    QList<double> awakeSums;

    int sleepCount = m_sleepLst.count();
    for(int i = 0;i < sleepCount;i++){
        Bean::Sleep sleep = m_sleepLst[i];

        //date
        labels.append(sleep.date());

        //sleepSum
        sleepSums.append(sleep.sleepSum());

        //deepSleepSum
        deepSleepSums.append(sleep.deepSleepSum());

        //awakeSums
        awakeSums.append(sleep.awakeSum());

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
    double *c_sleepSums = new double[sleepSums.count()];
    double *c_deepSleepSums = new double[deepSleepSums.count()];
    double *c_awakeSums = new double[awakeSums.count()];

    int index = 0;
    for(double label : labels){
        c_labels[index] = label;
        index++;
    }

    index = 0;
    for(double sum : sleepSums){
        c_sleepSums[index] = sum;
        index++;
    }

    index = 0;
    for(double sum : deepSleepSums){
        c_deepSleepSums[index] = sum;
        index++;
    }

    index = 0;
    for(double sum : awakeSums){
        c_awakeSums[index] = sum;
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
              , c_colors, colors.count()
              , c_sleepSums, sleepSums.count()
              , c_deepSleepSums, deepSleepSums.count()
              , c_awakeSums, awakeSums.count());

    delete c_labels;
    delete c_taskNos;
    delete c_startDates;
    delete c_endDates;
    delete c_colors;
    delete c_sleepSums;
    delete c_deepSleepSums;
    delete c_awakeSums;
}

void SleepResult::makeChart(double lowlimit, double uplimit
                            , double *labels, int label_len
                            , double *taskNo, int task_len
                            , double *startDate, int startDate_len
                            , double *endDate, int endDate_len
                            , int *colors, int color_len
                            , double *sleepSums, int sleepSum_len
                            , double *deepSleepSums, int deepSleepSum_len
                            , double *awakeSums, int awakeSum_len){
    if(m_ChartViewer->getChart() != NULL){
        delete m_ChartViewer->getChart();
    }
    if(!(label_len == 0 || task_len == 0 || startDate_len == 0 || endDate_len == 0 || color_len == 0)){
        m_ChartViewer->setChart(sleep(lowlimit, uplimit
                                      , labels, label_len
                                      , taskNo, task_len
                                      , startDate, startDate_len
                                      , endDate, endDate_len
                                      , colors, color_len
                                      , sleepSums, sleepSum_len
                                      , deepSleepSums, deepSleepSum_len
                                      , awakeSums, awakeSum_len));
        m_ChartViewer->updateDisplay();
    }
}

BaseChart *SleepResult::sleep(double lowlimit, double uplimit
                              , double *labels, int label_len
                              , double *taskNo, int task_len
                              , double *startDate, int startDate_len
                              , double *endDate, int endDate_len
                              , int *colors, int color_len
                              , double *sleepSums, int sleepSum_len
                              , double *deepSleepSums, int deepSleepSum_len
                              , double *awakeSums, int awakeSum_len){

    MultiChart *mc = new MultiChart(this->width(), this->height() + 60, GET_STYLE().main_bg_color);

    //gantt
    XYChart *c_gantt = new XYChart(mc->getWidth(), mc->getHeight() / 2, GET_STYLE().main_bg_color, -1, 0);

    c_gantt->setPlotArea(40, 20, c_gantt->getWidth() - 40, c_gantt->getHeight() - 20
                   , GET_STYLE().plot_bg_color, -1
                   , -1
                   , GET_STYLE().grid_color
                   , Chart::Transparent
        )->setGridWidth(1, 1, 1, 1);

    c_gantt->swapXY();

    c_gantt->yAxis()->setDateScale(lowlimit - 600, uplimit + 600, 600);

    c_gantt->yAxis()->setMultiFormat(Chart::StartOfHourFilter(), "<*font=arialbd.ttf*>{value|h:n}"
                , Chart::StartOfMinuteFilter(), "<*font=arialbd.ttf*>{value|n}");

    c_gantt->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c_gantt->setYAxisOnRight();

    c_gantt->xAxis()->setLabels(DoubleArray(labels, label_len));

    c_gantt->xAxis()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c_gantt->xAxis()->setReverse();

    c_gantt->xAxis()->setTickOffset(1);

    c_gantt->xAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    BoxWhiskerLayer *layer_gantt = c_gantt->addBoxWhiskerLayer2(DoubleArray(startDate, startDate_len), DoubleArray(endDate, endDate_len)
                                                    , DoubleArray(), DoubleArray()
                                                    , DoubleArray(), IntArray(colors, color_len));
    layer_gantt->setXData(DoubleArray(taskNo, task_len));
    layer_gantt->setBorderColor(Chart::Transparent);

    layer_gantt->setDataWidth(c_gantt->getPlotArea()->getHeight() / label_len * 2 / 3);

    mc->addChart(0, 0, c_gantt);

    //stack
    XYChart *c_stack = new XYChart(mc->getWidth(), mc->getHeight() / 2, GET_STYLE().main_bg_color, -1, 0);

    c_stack->setPlotArea(40, 20, c_stack->getWidth() - 40, c_stack->getHeight() - 100
                         , GET_STYLE().plot_bg_color, -1
                         , -1
                         , GET_STYLE().grid_color
                         , GET_STYLE().grid_color
              )->setGridWidth(1, 1, 1, 1);

    c_stack->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c_stack->xAxis2()->setLabels(DoubleArray(labels, label_len));

    c_stack->xAxis2()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c_stack->xAxis2()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    AreaLayer *layer_stack = c_stack->addAreaLayer(Chart::Stack);
    layer_stack->setBorderColor(Chart::SameAsMainColor);
    layer_stack->addDataSet(DoubleArray(awakeSums, awakeSum_len), AWAKE_COLOR,
        "awake");
    layer_stack->addDataSet(DoubleArray(deepSleepSums, deepSleepSum_len), DEEP_COLOR,
        "deep sleep");
    layer_stack->addDataSet(DoubleArray(sleepSums, sleepSum_len), LATENT_COLOR,
        "sleep");

    mc->addChart(0, c_gantt->getHeight(), c_stack);


    mc->makeChart();

    return mc;
}
