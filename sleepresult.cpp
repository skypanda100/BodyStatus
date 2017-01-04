#include "sleepresult.h"

SleepResult::SleepResult(QWidget *parent)
    :QWidget(parent)
    ,m_moduleId(0)
{
    this->initUI();
    this->initConnect();
}

SleepResult::~SleepResult(){
    delete m_ChartViewer;
}

void SleepResult::onSearch(QList<Bean::Sleep> sleepLst){
    this->m_sleepLst01.clear();
    this->m_sleepLst02.clear();
    for(Bean::Sleep sleep: sleepLst){
        if(sleep.person() == 0){
            this->m_sleepLst01.append(sleep);
        }else{
            this->m_sleepLst02.append(sleep);
        }
    }
    this->makeChart();
}

void SleepResult::onModule(int moduleId){
    this->m_moduleId = moduleId;
    this->onStyle();
}

void SleepResult::onStyle(){
    this->makeChart();
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
}

void SleepResult::initConnect(){
}

void SleepResult::makeChart(){
    if(m_ChartViewer->getChart() != NULL){
        delete m_ChartViewer->getChart();
    }
    MultiChart *mc = new MultiChart(this->width(), this->height() + 60, GET_STYLE().main_bg_color);
    if(m_moduleId == 0){
        //gantt
        if(m_sleepLst01.count() > 0 && m_sleepLst02.count() > 0){
            BaseChart *chart01 = sleepGantt(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst01);
            BaseChart *chart02 = sleepGantt(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst02);
            mc->addChart(0, 0, chart01);
            mc->addChart(0, chart01->getHeight(), chart02);
        }else if(m_sleepLst01.count() > 0 && m_sleepLst02.count() == 0){
            BaseChart *chart01 = sleepGantt(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst01);
            mc->addChart(0, 0, chart01);
        }else if(m_sleepLst01.count() == 0 && m_sleepLst02.count() > 0){
            BaseChart *chart02 = sleepGantt(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst02);
            mc->addChart(0, 0, chart02);
        }else{

        }
    }else if(m_moduleId == 1){
        //stack
        if(m_sleepLst01.count() > 0 && m_sleepLst02.count() > 0){
            BaseChart *chart01 = sleepStack(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst01);
            BaseChart *chart02 = sleepStack(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst02);
            mc->addChart(0, 0, chart01);
            mc->addChart(0, chart01->getHeight(), chart02);
        }else if(m_sleepLst01.count() > 0 && m_sleepLst02.count() == 0){
            BaseChart *chart01 = sleepStack(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst01);
            mc->addChart(0, 0, chart01);
        }else if(m_sleepLst01.count() == 0 && m_sleepLst02.count() > 0){
            BaseChart *chart02 = sleepStack(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst02);
            mc->addChart(0, 0, chart02);
        }else{

        }
    }else if(m_moduleId == 2){
        //line
        if(m_sleepLst01.count() > 0 && m_sleepLst02.count() > 0){
            BaseChart *chart01 = sleepLine(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst01);
            BaseChart *chart02 = sleepLine(mc->getWidth(), (mc->getHeight() - 80) / 2, m_sleepLst02);
            mc->addChart(0, 0, chart01);
            mc->addChart(0, chart01->getHeight(), chart02);
        }else if(m_sleepLst01.count() > 0 && m_sleepLst02.count() == 0){
            BaseChart *chart01 = sleepLine(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst01);
            mc->addChart(0, 0, chart01);
        }else if(m_sleepLst01.count() == 0 && m_sleepLst02.count() > 0){
            BaseChart *chart02 = sleepLine(mc->getWidth(), (mc->getHeight() - 80), m_sleepLst02);
            mc->addChart(0, 0, chart02);
        }else{

        }
    }


    mc->makeChart();
    m_ChartViewer->setChart(mc);
    m_ChartViewer->updateDisplay();
}

BaseChart *SleepResult::sleepGantt(int width, int height, QList<Bean::Sleep> sleepLst){
    if(sleepLst.count() == 0){
        return NULL;
    }

    DataGantt dataGantt;
    makeDataGantt(&dataGantt, sleepLst);

    //gantt
    XYChart *c = new XYChart(width, height, GET_STYLE().main_bg_color, -1, 0);

    c->setPlotArea(40, 20, width - 40, height - 20
                   , GET_STYLE().plot_bg_color, -1
                   , -1
                   , GET_STYLE().grid_color
                   , Chart::Transparent
        )->setGridWidth(1, 1, 1, 1);

    c->swapXY();

    c->yAxis()->setDateScale(dataGantt.lowlimit - 600, dataGantt.uplimit + 600, 600);

    c->yAxis()->setMultiFormat(Chart::StartOfHourFilter(), "<*font=arialbd.ttf*>{value|h:n}"
                , Chart::StartOfMinuteFilter(), "<*font=arialbd.ttf*>{value|n}");

    c->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c->setYAxisOnRight();

    c->xAxis()->setLabels(DoubleArray(dataGantt.labels, dataGantt.label_len));

    c->xAxis()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c->xAxis()->setReverse();

    c->xAxis()->setTickOffset(1);

    c->xAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    BoxWhiskerLayer *layer_gantt = c->addBoxWhiskerLayer2(DoubleArray(dataGantt.startDate, dataGantt.startDate_len), DoubleArray(dataGantt.endDate, dataGantt.endDate_len)
                                                    , DoubleArray(), DoubleArray()
                                                    , DoubleArray(), IntArray(dataGantt.colors, dataGantt.color_len));
    layer_gantt->setXData(DoubleArray(dataGantt.taskNo, dataGantt.task_len));
    layer_gantt->setBorderColor(Chart::Transparent);

    layer_gantt->setDataWidth(c->getPlotArea()->getHeight() / dataGantt.label_len * 2 / 3);

    delete dataGantt.labels;
    delete dataGantt.taskNo;
    delete dataGantt.startDate;
    delete dataGantt.endDate;
    delete dataGantt.colors;

    return c;
}

void SleepResult::makeDataGantt(DataGantt *dataGantt, QList<Bean::Sleep> sleepLst){
    QList<double> labels;
    QList<double> taskNos;
    QList<double> startDates;
    QList<double> endDates;
    QList<int> colors;

    int sleepCount = sleepLst.count();
    for(int i = 0;i < sleepCount;i++){
        Bean::Sleep sleep = sleepLst[i];

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

    dataGantt->lowlimit = lowlimit;
    dataGantt->uplimit = uplimit;
    dataGantt->labels = c_labels;
    dataGantt->label_len = labels.count();
    dataGantt->taskNo = c_taskNos;
    dataGantt->task_len = taskNos.count();
    dataGantt->startDate = c_startDates;
    dataGantt->startDate_len = startDates.count();
    dataGantt->endDate = c_endDates;
    dataGantt->endDate_len = endDates.count();
    dataGantt->colors = c_colors;
    dataGantt->color_len = colors.count();
}

BaseChart *SleepResult::sleepStack(int width, int height, QList<Bean::Sleep> sleepLst){
    if(sleepLst.count() == 0){
        return NULL;
    }

    DataStack dataStack;
    makeDataStack(&dataStack, sleepLst);

    //stack
    XYChart *c = new XYChart(width, height, GET_STYLE().main_bg_color, -1, 0);

    c->setPlotArea(40, 20, c->getWidth() - 40, c->getHeight() - 20
                         , GET_STYLE().plot_bg_color, -1
                         , -1
                         , GET_STYLE().grid_color
                         , GET_STYLE().grid_color
              )->setGridWidth(1, 1, 1, 1);

    c->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c->yAxis()->setLinearScale(0, 14);

    c->xAxis2()->setLabels(DoubleArray(dataStack.labels, dataStack.label_len));

    c->xAxis2()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c->xAxis2()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    AreaLayer *layer_stack = c->addAreaLayer(Chart::Stack);
    layer_stack->setBorderColor(Chart::SameAsMainColor);
    layer_stack->addDataSet(DoubleArray(dataStack.awakeSums, dataStack.awakeSum_len), AWAKE_COLOR,
        "awake");
    layer_stack->addDataSet(DoubleArray(dataStack.deepSleepSums, dataStack.deepSleepSum_len), DEEP_COLOR,
        "deep sleep");
    layer_stack->addDataSet(DoubleArray(dataStack.sleepSums, dataStack.sleepSum_len), LATENT_COLOR,
        "sleep");

    delete dataStack.labels;
    delete dataStack.awakeSums;
    delete dataStack.deepSleepSums;
    delete dataStack.sleepSums;

    return c;
}

void SleepResult::makeDataStack(DataStack *dataStack, QList<Bean::Sleep> sleepLst){
    QList<double> labels;
    QList<double> sleepSums;
    QList<double> deepSleepSums;
    QList<double> awakeSums;

    int sleepCount = sleepLst.count();
    for(int i = 0;i < sleepCount;i++){
        Bean::Sleep sleep = sleepLst[i];

        //date
        labels.append(sleep.date());

        //sleepSum
        sleepSums.append(sleep.sleepSum());

        //deepSleepSum
        deepSleepSums.append(sleep.deepSleepSum());

        //awakeSums
        awakeSums.append(sleep.awakeSum());
    }

    double *c_labels = new double[labels.count()];
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

    dataStack->labels = c_labels;
    dataStack->label_len = labels.count();
    dataStack->sleepSums = c_sleepSums;
    dataStack->sleepSum_len = sleepSums.count();
    dataStack->deepSleepSums = c_deepSleepSums;
    dataStack->deepSleepSum_len = deepSleepSums.count();
    dataStack->awakeSums = c_awakeSums;
    dataStack->awakeSum_len = awakeSums.count();
}

BaseChart *SleepResult::sleepLine(int width, int height, QList<Bean::Sleep> sleepLst){
    if(sleepLst.count() == 0){
        return NULL;
    }

    DataLine dataLine;
    makeDataLine(&dataLine, sleepLst);

    //line
    XYChart *c = new XYChart(width, height, GET_STYLE().main_bg_color, -1, 0);

    c->setPlotArea(40, 20, c->getWidth() - 40, c->getHeight() - 20
                         , GET_STYLE().plot_bg_color, -1
                         , -1
                         , GET_STYLE().grid_color
                         , GET_STYLE().grid_color
              )->setGridWidth(1, 1, 1, 1);

    c->yAxis()->setTickOffset(1.0);

    c->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    c->yAxis()->setMultiFormat(Chart::StartOfHourFilter(), "<*font=arialbd.ttf*>{value|h:n}"
                , Chart::StartOfMinuteFilter(), "<*font=arialbd.ttf*>{value|h:n}");

    c->xAxis2()->setLabels(DoubleArray(dataLine.labels, dataLine.label_len));

    c->xAxis2()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|d mmm}"
                , Chart::StartOfDayFilter(), "<*font=arialbd.ttf*>{value|d}");

    c->xAxis2()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);

    SplineLayer *layer0 = c->addSplineLayer(DoubleArray(dataLine.startDate, dataLine.startDate_len), DEEP_COLOR, "sleep");
    layer0->setLineWidth(2);

    LineLayer *layer1 = c->addLineLayer(DoubleArray(dataLine.endDate, dataLine.endDate_len),
        DEEP_COLOR, "wake");
    layer1->setLineWidth(2);

    c->addInterLineLayer(layer0->getLine(), layer1->getLine(), LATENT_COLOR, LATENT_COLOR);

    delete dataLine.labels;
    delete dataLine.startDate;
    delete dataLine.endDate;

    return c;
}

void SleepResult::makeDataLine(DataLine *dataLine, QList<Bean::Sleep> sleepLst){
    QList<double> labels;
    QList<double> startDates;
    QList<double> endDates;

    int sleepCount = sleepLst.count();
    for(int i = 0;i < sleepCount;i++){
        Bean::Sleep sleep = sleepLst[i];

        //date
        labels.append(sleep.date());

        //latent sleep
        startDates.append(sleep.start());
        endDates.append(sleep.end());
    }

    double *c_labels = new double[labels.count()];
    double *c_startDates = new double[startDates.count()];
    double *c_endDates = new double[endDates.count()];

    int index = 0;
    for(double label : labels){
        c_labels[index] = label;
        index++;
    }

    index = 0;
    for(double startDate : startDates){
        c_startDates[index] = startDate;
        index++;
    }

    index = 0;
    for(double endDate : endDates){
        c_endDates[index] = endDate;
        index++;
    }

    dataLine->labels = c_labels;
    dataLine->label_len = labels.count();
    dataLine->startDate = c_startDates;
    dataLine->startDate_len = startDates.count();
    dataLine->endDate = c_endDates;
    dataLine->endDate_len = endDates.count();
}
