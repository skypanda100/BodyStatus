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
    if(m_sleepResult != NULL){
        delete m_sleepResult;
    }

    if(m_mainWidget != NULL){
        delete m_mainWidget;
    }
}

void MainWindow::initUI(){
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

}
