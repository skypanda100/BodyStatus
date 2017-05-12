#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_sleepResult(NULL)
    , m_mainWidget(NULL)
{
    this->initUI();
    this->initConnect();
}

MainWindow::~MainWindow()
{
    delete m_lightStyleAction;
    delete m_darkStyleAction;
    delete m_styleMenu;
    delete m_printAction;
    delete m_sleepDistributionAction;
    delete m_sleepDurationAction;
    delete m_sleepIntervalAction;
    delete m_sleepMenu;
    delete m_sleepDataAction;
    delete m_sleepInput;

    if(m_sleepResult != NULL){
        delete m_sleepResult;
    }

    if(m_mainWidget != NULL){
        delete m_mainWidget;
    }
}

void MainWindow::initUI(){
    QToolBar *otherToolBar = new QToolBar(this);
    otherToolBar->setWindowTitle("Other");
    otherToolBar->setIconSize(QSize(40, 40));
    this->addToolBar(otherToolBar);

    //style
    QIcon styleIcon = QIcon(":/image/style.png");
    m_styleMenu = new QMenu("Style", this);
    m_styleMenu->setIcon(styleIcon);
    m_lightStyleAction = new QAction("Light", m_styleMenu);
    m_darkStyleAction = new QAction("Dark", m_styleMenu);
    m_styleMenu->addAction(m_lightStyleAction);
    m_styleMenu->addAction(m_darkStyleAction);
    otherToolBar->addAction(m_styleMenu->menuAction());

    //print
    QIcon printIcon = QIcon(":/image/print.png");
    m_printAction = new QAction(printIcon, "Print", this);
    otherToolBar->addAction(m_printAction);

    QToolBar *moduleToolBar = new QToolBar(this);
    moduleToolBar->setWindowTitle("Module");
    moduleToolBar->setIconSize(QSize(40, 40));
    this->addToolBar(moduleToolBar);

    //sleep
    QIcon sleepDataIcon = QIcon(":/image/sleep.png");
    m_sleepDataAction = new QAction(sleepDataIcon, "Sleep Data", this);
    moduleToolBar->addAction(m_sleepDataAction);

    QIcon sleepIcon = QIcon(":/image/sleep_visual.png");
    m_sleepMenu = new QMenu("Sleep", this);
    m_sleepMenu->setIcon(sleepIcon);
    m_sleepDistributionAction = new QAction("Sleep Distribution", m_sleepMenu);
    m_sleepDurationAction = new QAction("Sleep DurationAction", m_sleepMenu);
    m_sleepIntervalAction = new QAction("Sleep Interval", m_sleepMenu);
    m_sleepMenu->addAction(m_sleepDistributionAction);
    m_sleepMenu->addAction(m_sleepDurationAction);
    m_sleepMenu->addAction(m_sleepIntervalAction);
    moduleToolBar->addAction(m_sleepMenu->menuAction());

    //input
    m_sleepInput = new SleepInput;

    //result
    m_sleepResult = new SleepResult;

    m_mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_sleepResult);
    m_mainWidget->setLayout(mainLayout);

    this->setCentralWidget(m_mainWidget);

    this->move(0, 0);

}

void MainWindow::initConnect(){
    connect(m_styleMenu, SIGNAL(triggered(QAction *)), this, SLOT(onStyleTriggered(QAction *)));
    connect(m_printAction, SIGNAL(triggered()), this, SLOT(onPrintTriggered()));
    connect(m_sleepDataAction, SIGNAL(triggered()), this, SLOT(onSleepDataTriggered()));
    connect(m_sleepMenu, SIGNAL(triggered(QAction *)), this, SLOT(onSleepTriggered(QAction *)));
    connect(m_sleepInput, SIGNAL(search(QList<Bean::Sleep>)), m_sleepResult, SLOT(onSearch(QList<Bean::Sleep>)));
}

void MainWindow::onSleepDataTriggered(){
//    m_sleepInput->exec();
    m_sleepInput->show();
}

void MainWindow::onSleepTriggered(QAction *action){
    if(action == m_sleepDistributionAction){
        m_sleepResult->onModule(0);
    }else if(action == m_sleepDurationAction){
        m_sleepResult->onModule(1);
    }else if(action == m_sleepIntervalAction){
        m_sleepResult->onModule(2);
    }
}

void MainWindow::onStyleTriggered(QAction *action){
    if(action == m_lightStyleAction){
        SET_STYLE(0);
        m_sleepResult->onStyle();
    }else{
        SET_STYLE(1);
        m_sleepResult->onStyle();
    }
}

void MainWindow::onPrintTriggered(){
    QPixmap currentScreenPixmap;
    if(QApplication::activeWindow()){
        currentScreenPixmap = QPixmap::grabWindow(QApplication::activeWindow()->winId()
                                                  , -2
                                                  , -26
                                                  , QApplication::activeWindow()->width()
                                                  , QApplication::activeWindow()->height() + 25);
    }
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = currentScreenPixmap.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(),
                            size.width(), size.height());
        painter.setWindow(currentScreenPixmap.rect());
        painter.drawPixmap(0, 0, currentScreenPixmap);
    }
}
