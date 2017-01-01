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

    //test
    this->makeChart();
}

void SleepResult::initConnect(){

}

void SleepResult::makeChart(){
    if(m_ChartViewer->getChart() != NULL){
        delete m_ChartViewer->getChart();
    }
    m_ChartViewer->setChart(sleep());
}

BaseChart *SleepResult::sleep(){
    // The tasks for the gantt chart
    const char *labels[] = {"2016-12-01", "2016-12-02", "2016-12-03",
        "2016-12-04", "2016-12-05", "2016-12-06", "2016-12-07", "2016-12-08",
        "2016-12-09"};

    // The task index, start date, end date and color for each bar
    double taskNo[] = {0, 0, 1, 2, 3, 4, 5, 6, 6, 7, 8, 8};
    double startDate[] = {Chart::chartTime(2004, 8, 16), Chart::chartTime(2004, 10, 4),
        Chart::chartTime(2004, 8, 30), Chart::chartTime(2004, 9, 13), Chart::chartTime(2004, 9, 20),
        Chart::chartTime(2004, 9, 27), Chart::chartTime(2004, 10, 4), Chart::chartTime(2004, 10, 4),
        Chart::chartTime(2004, 10, 25), Chart::chartTime(2004, 11, 1), Chart::chartTime(2004, 10, 18
        ), Chart::chartTime(2004, 11, 8)};
    double endDate[] = {Chart::chartTime(2004, 8, 30), Chart::chartTime(2004, 10, 18),
        Chart::chartTime(2004, 9, 13), Chart::chartTime(2004, 9, 27), Chart::chartTime(2004, 10, 4),
        Chart::chartTime(2004, 10, 11), Chart::chartTime(2004, 11, 8), Chart::chartTime(2004, 10, 18
        ), Chart::chartTime(2004, 11, 8), Chart::chartTime(2004, 11, 22), Chart::chartTime(2004, 11,
        1), Chart::chartTime(2004, 11, 22)};
    int colors[] = {0x00cc00, 0x00cc00, 0x00cc00, 0x0000cc, 0x0000cc, 0xcc0000, 0xcc0000, 0x0000cc,
        0xcc0000, 0xcc0000, 0x00cc00, 0xcc0000};

    // Create a XYChart object of size 620 x 325 pixels. Set background color to light red
    // (0xffcccc), with 1 pixel 3D border effect.
    XYChart *c = new XYChart(this->width(), this->height(), GET_STYLE().main_bg_color, -1, 0);

    // Set the plotarea at (140, 55) and of size 460 x 200 pixels. Use alternative white/grey
    // background. Enable both horizontal and vertical grids by setting their colors to grey
    // (c0c0c0). Set vertical major grid (represents month boundaries) 2 pixels in width
    c->setPlotArea(60, 20, this->width() - 60, this->height() - 20
                   , GET_STYLE().plot_bg_color, -1
                   , -1
                   , GET_STYLE().grid_color
                   , GET_STYLE().grid_color
        )->setGridWidth(1, 1, 1, 1);

    // swap the x and y axes to create a horziontal box-whisker chart
    c->swapXY();

    // Set the y-axis scale to be date scale from Aug 16, 2004 to Nov 22, 2004, with ticks every 7
    // days (1 week)
//    c->yAxis()->setDateScale(Chart::chartTime(2004, 8, 16), Chart::chartTime(2004, 11, 22), 86400 *
//        7);

    // Set multi-style axis label formatting. Month labels are in Arial Bold font in "mmm d" format.
    // Weekly labels just show the day of month and use minor tick (by using '-' as first character
    // of format string).
    c->yAxis()->setMultiFormat(Chart::StartOfMonthFilter(), "<*font=arialbd.ttf*>{value|mmm d}",
        Chart::StartOfDayFilter(), "-{value|d}");

    c->yAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);
    // Set the y-axis to shown on the top (right + swapXY = top)
    c->setYAxisOnRight();

    // Set the labels on the x axis
    c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

    // Reverse the x-axis scale so that it points downwards.
    c->xAxis()->setReverse();

    // Set the horizontal ticks and grid lines to be between the bars
    c->xAxis()->setTickOffset(0.5);

    c->xAxis()->setColors(GET_STYLE().font_color, GET_STYLE().font_color);
    // Add a multi-color box-whisker layer to represent the gantt bars
    BoxWhiskerLayer *layer = c->addBoxWhiskerLayer2(DoubleArray(startDate, (int)(sizeof(startDate) /
        sizeof(startDate[0]))), DoubleArray(endDate, (int)(sizeof(endDate) / sizeof(endDate[0]))),
        DoubleArray(), DoubleArray(), DoubleArray(), IntArray(colors, (int)(sizeof(colors) / sizeof(
        colors[0]))));
    layer->setXData(DoubleArray(taskNo, (int)(sizeof(taskNo) / sizeof(taskNo[0]))));
    layer->setBorderColor(Chart::SameAsMainColor);

    // Divide the plot area height ( = 200 in this chart) by the number of tasks to get the height
    // of each slot. Use 80% of that as the bar height.
    layer->setDataWidth(200 * 4 / 5 / (int)(sizeof(labels) / sizeof(labels[0])));

    // Output the chart
    c->makeChart();

    return c;
}
