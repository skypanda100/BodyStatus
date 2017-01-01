#include "sleepinput.h"

SleepInput::SleepInput(QWidget *parent)
    :QDialog(parent)
{
    this->initUI();
    this->initConnect();
}

SleepInput::~SleepInput(){
    delete m_fDateEdit;
    delete m_tDateEdit;
    delete m_searchButton;
}

void SleepInput::initUI(){
    //title
    this->setWindowTitle("Sleep");
    this->setWindowIcon(QIcon(":/image/sleep.png"));
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    QFont labelFont;
    labelFont.setBold(true);

    QLabel *fromLabel = new QLabel;
    fromLabel->setFont(labelFont);
    fromLabel->setText("From");

    m_fDateEdit = new QDateEdit;
    m_fDateEdit->setFixedWidth(100);
    m_fDateEdit->setDate(QDateTime::currentDateTime().date());
    m_fDateEdit->setCalendarPopup(true);

    QLabel *toLabel = new QLabel;
    toLabel->setFont(labelFont);
    toLabel->setText("To");

    m_tDateEdit = new QDateEdit;
    m_tDateEdit->setFixedWidth(100);
    m_tDateEdit->setDate(QDateTime::currentDateTime().date());
    m_tDateEdit->setCalendarPopup(true);

    m_searchButton = new QPushButton;
    m_searchButton->setText("Search");

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fromLabel, 0, 0);
    mainLayout->addWidget(m_fDateEdit, 0, 1);
    mainLayout->addWidget(toLabel, 1, 0);
    mainLayout->addWidget(m_tDateEdit, 1, 1);
    mainLayout->addWidget(m_searchButton, 2, 0, 1, 2);
    this->setLayout(mainLayout);
}

void SleepInput::initConnect(){
    connect(m_searchButton, SIGNAL(clicked()), this, SLOT(onSearchClicked()));
}

void SleepInput::onSearchClicked(){
    this->accept();
}
