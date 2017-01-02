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
    delete m_printAction;
    delete m_sleepAction;
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
    QMenu *styleMenu = new QMenu("Style", this);
    styleMenu->setIcon(styleIcon);
    m_lightStyleAction = new QAction("Light", styleMenu);
    m_darkStyleAction = new QAction("Dark", styleMenu);
    styleMenu->addAction(m_lightStyleAction);
    styleMenu->addAction(m_darkStyleAction);
    otherToolBar->addAction(styleMenu->menuAction());

    //print
    QIcon printIcon = QIcon(":/image/print.png");
    m_printAction = new QAction(printIcon, "Print", this);
    otherToolBar->addAction(m_printAction);

    QToolBar *moduleToolBar = new QToolBar(this);
    moduleToolBar->setWindowTitle("Module");
    moduleToolBar->setIconSize(QSize(40, 40));
    this->addToolBar(moduleToolBar);

    //sleep
    QIcon sleepIcon = QIcon(":/image/sleep.png");
    m_sleepAction = new QAction(sleepIcon, "Sleep", this);
    moduleToolBar->addAction(m_sleepAction);

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
    connect(m_lightStyleAction, SIGNAL(triggered()), this, SLOT(onLightStyleTriggered()));
    connect(m_darkStyleAction, SIGNAL(triggered()), this, SLOT(onDarkStyleTriggered()));
    connect(m_sleepAction, SIGNAL(triggered()), this, SLOT(onSleepTriggered()));
    connect(m_printAction, SIGNAL(triggered()), this, SLOT(onPrintTriggered()));
    connect(m_sleepInput, SIGNAL(search(int, QList<Bean::Sleep>)), m_sleepResult, SLOT(onSearch(int, QList<Bean::Sleep>)));
}

void MainWindow::onSleepTriggered(){
    m_sleepInput->exec();
}

void MainWindow::onLightStyleTriggered(){
    SET_STYLE(0);
    m_sleepResult->onStyle();
}

void MainWindow::onDarkStyleTriggered(){
    SET_STYLE(1);
    m_sleepResult->onStyle();
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
