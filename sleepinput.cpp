#include "sleepinput.h"

SleepQueryInput::SleepQueryInput(QWidget *parent)
    :QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

SleepQueryInput::~SleepQueryInput(){
    delete m_personComboBox;
    delete m_fDateEdit;
    delete m_tDateEdit;
    delete m_searchButton;
    delete m_db;
}

void SleepQueryInput::initUI(){
    m_db = new Db;

    QFont labelFont;
    labelFont.setBold(true);

    QLabel *personLabel = new QLabel;
    personLabel->setFont(labelFont);
    personLabel->setText("Person");

    m_personComboBox = new QComboBox;
    m_personComboBox->insertItem(0, "gg");
    m_personComboBox->insertItem(1, "tt");
    m_personComboBox->insertItem(2, "both");

    QLabel *fromLabel = new QLabel;
    fromLabel->setFont(labelFont);
    fromLabel->setText("From");

    m_fDateEdit = new QDateEdit;
    m_fDateEdit->setDate(QDateTime::currentDateTime().addDays(-30).date());
    m_fDateEdit->setCalendarPopup(true);

    QLabel *toLabel = new QLabel;
    toLabel->setFont(labelFont);
    toLabel->setText("To");

    m_tDateEdit = new QDateEdit;
    m_tDateEdit->setDate(QDateTime::currentDateTime().date());
    m_tDateEdit->setCalendarPopup(true);

    m_searchButton = new QPushButton;
    m_searchButton->setText("Search");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(personLabel);
    mainLayout->addWidget(m_personComboBox);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(fromLabel);
    mainLayout->addWidget(m_fDateEdit);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(toLabel);
    mainLayout->addWidget(m_tDateEdit);
    mainLayout->addStretch(1);
    mainLayout->addWidget(m_searchButton);
    this->setLayout(mainLayout);
}

void SleepQueryInput::initConnect(){
    connect(m_searchButton, SIGNAL(clicked()), this, SLOT(onSearchClicked()));
}

void SleepQueryInput::onSearchClicked(){
    int personId = m_personComboBox->currentIndex();
    QDate fDate = m_fDateEdit->date();
    QDate tDate = m_tDateEdit->date();

    QString queryStr;
    if(personId > 1){
        queryStr = QString("select * from status_sleep where date >= '%1' and date <= '%2' order by date asc")
                .arg(fDate.toString("yyyy-MM-dd 00:00:00"))
                .arg(tDate.toString("yyyy-MM-dd 00:00:00"));
    }else{
        queryStr = QString("select * from status_sleep where person = %1 and date >= '%2' and date <= '%3' order by date asc")
                .arg(personId)
                .arg(fDate.toString("yyyy-MM-dd 00:00:00"))
                .arg(tDate.toString("yyyy-MM-dd 00:00:00"));
    }

    QList<Bean::Sleep> sleepLst = m_db->querySleep(queryStr);
    if(sleepLst.count() > 0){
        emit search(sleepLst);
    }else{
        QMessageBox::critical(0, QObject::tr("Search"), "there are no results");
    }
}

SleepInsertInput::SleepInsertInput(QWidget *parent)
    :QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

SleepInsertInput::~SleepInsertInput(){
    delete m_dateEdit;
    delete m_sleepEditStart01;
    delete m_sleepEditEnd01;
    delete m_sleepEditStart02;
    delete m_sleepEditEnd02;
    delete m_sleepEditStart03;
    delete m_sleepEditEnd03;
    delete m_sleepEditStart04;
    delete m_sleepEditEnd04;
    delete m_sleepEditStart05;
    delete m_sleepEditEnd05;
    delete m_sleepEditStart06;
    delete m_sleepEditEnd06;
    delete m_sleepEditStart07;
    delete m_sleepEditEnd07;
    delete m_sleepEditStart08;
    delete m_sleepEditEnd08;
    delete m_sleepEditStart09;
    delete m_sleepEditEnd09;
    delete m_sleepEditStart10;
    delete m_sleepEditEnd10;
    delete m_awakeEditStart01;
    delete m_awakeEditEnd01;
    delete m_awakeEditStart02;
    delete m_awakeEditEnd02;
    delete m_awakeEditStart03;
    delete m_awakeEditEnd03;
    delete m_awakeEditStart04;
    delete m_awakeEditEnd04;
    delete m_insertButton;
}

void SleepInsertInput::initUI(){
    m_db = new Db;

    QFont labelFont;
    labelFont.setBold(true);

    QLabel *dateLabel = new QLabel;
    dateLabel->setFont(labelFont);
    dateLabel->setText("Date");

    m_dateEdit = new QDateEdit;
    m_dateEdit->setDate(QDateTime::currentDateTime().date());
    m_dateEdit->setCalendarPopup(true);

    QRegExp regExp("^[0-9]{4}$");
    QValidator *validator = new QRegExpValidator(regExp, 0);

    QLabel *sleepLabel = new QLabel;
    sleepLabel->setFont(labelFont);
    sleepLabel->setText("Deep Sleep");

    m_sleepEditStart01 = new QLineEdit;
    m_sleepEditStart01->setValidator(validator);
    m_sleepEditEnd01 = new QLineEdit;
    m_sleepEditEnd01->setValidator(validator);
    QHBoxLayout *sleepEditLayout01 = new QHBoxLayout;
    sleepEditLayout01->addWidget(m_sleepEditStart01);
    sleepEditLayout01->addStretch(1);
    sleepEditLayout01->addWidget(m_sleepEditEnd01);

    m_sleepEditStart02 = new QLineEdit;
    m_sleepEditStart02->setValidator(validator);
    m_sleepEditEnd02 = new QLineEdit;
    m_sleepEditEnd02->setValidator(validator);
    QHBoxLayout *sleepEditLayout02 = new QHBoxLayout;
    sleepEditLayout02->addWidget(m_sleepEditStart02);
    sleepEditLayout02->addStretch(1);
    sleepEditLayout02->addWidget(m_sleepEditEnd02);

    m_sleepEditStart03 = new QLineEdit;
    m_sleepEditStart03->setValidator(validator);
    m_sleepEditEnd03 = new QLineEdit;
    m_sleepEditEnd03->setValidator(validator);
    QHBoxLayout *sleepEditLayout03 = new QHBoxLayout;
    sleepEditLayout03->addWidget(m_sleepEditStart03);
    sleepEditLayout03->addStretch(1);
    sleepEditLayout03->addWidget(m_sleepEditEnd03);

    m_sleepEditStart04 = new QLineEdit;
    m_sleepEditStart04->setValidator(validator);
    m_sleepEditEnd04 = new QLineEdit;
    m_sleepEditEnd04->setValidator(validator);
    QHBoxLayout *sleepEditLayout04 = new QHBoxLayout;
    sleepEditLayout04->addWidget(m_sleepEditStart04);
    sleepEditLayout04->addStretch(1);
    sleepEditLayout04->addWidget(m_sleepEditEnd04);

    m_sleepEditStart05 = new QLineEdit;
    m_sleepEditStart05->setValidator(validator);
    m_sleepEditEnd05 = new QLineEdit;
    m_sleepEditEnd05->setValidator(validator);
    QHBoxLayout *sleepEditLayout05 = new QHBoxLayout;
    sleepEditLayout05->addWidget(m_sleepEditStart05);
    sleepEditLayout05->addStretch(1);
    sleepEditLayout05->addWidget(m_sleepEditEnd05);

    m_sleepEditStart06 = new QLineEdit;
    m_sleepEditStart06->setValidator(validator);
    m_sleepEditEnd06 = new QLineEdit;
    m_sleepEditEnd06->setValidator(validator);
    QHBoxLayout *sleepEditLayout06 = new QHBoxLayout;
    sleepEditLayout06->addWidget(m_sleepEditStart06);
    sleepEditLayout06->addStretch(1);
    sleepEditLayout06->addWidget(m_sleepEditEnd06);

    m_sleepEditStart07 = new QLineEdit;
    m_sleepEditStart07->setValidator(validator);
    m_sleepEditEnd07 = new QLineEdit;
    m_sleepEditEnd07->setValidator(validator);
    QHBoxLayout *sleepEditLayout07 = new QHBoxLayout;
    sleepEditLayout07->addWidget(m_sleepEditStart07);
    sleepEditLayout07->addStretch(1);
    sleepEditLayout07->addWidget(m_sleepEditEnd07);

    m_sleepEditStart08 = new QLineEdit;
    m_sleepEditStart08->setValidator(validator);
    m_sleepEditEnd08 = new QLineEdit;
    m_sleepEditEnd08->setValidator(validator);
    QHBoxLayout *sleepEditLayout08 = new QHBoxLayout;
    sleepEditLayout08->addWidget(m_sleepEditStart08);
    sleepEditLayout08->addStretch(1);
    sleepEditLayout08->addWidget(m_sleepEditEnd08);

    m_sleepEditStart09 = new QLineEdit;
    m_sleepEditStart09->setValidator(validator);
    m_sleepEditEnd09 = new QLineEdit;
    m_sleepEditEnd09->setValidator(validator);
    QHBoxLayout *sleepEditLayout09 = new QHBoxLayout;
    sleepEditLayout09->addWidget(m_sleepEditStart09);
    sleepEditLayout09->addStretch(1);
    sleepEditLayout09->addWidget(m_sleepEditEnd09);

    m_sleepEditStart10 = new QLineEdit;
    m_sleepEditStart10->setValidator(validator);
    m_sleepEditEnd10 = new QLineEdit;
    m_sleepEditEnd10->setValidator(validator);
    QHBoxLayout *sleepEditLayout10 = new QHBoxLayout;
    sleepEditLayout10->addWidget(m_sleepEditStart10);
    sleepEditLayout10->addStretch(1);
    sleepEditLayout10->addWidget(m_sleepEditEnd10);

    QLabel *awakeLabel = new QLabel;
    awakeLabel->setFont(labelFont);
    awakeLabel->setText("Awake");

    m_awakeEditStart01 = new QLineEdit;
    m_awakeEditStart01->setValidator(validator);
    m_awakeEditEnd01 = new QLineEdit;
    m_awakeEditEnd01->setValidator(validator);
    QHBoxLayout *awakeEditLayout01 = new QHBoxLayout;
    awakeEditLayout01->addWidget(m_awakeEditStart01);
    awakeEditLayout01->addStretch(1);
    awakeEditLayout01->addWidget(m_awakeEditEnd01);

    m_awakeEditStart02 = new QLineEdit;
    m_awakeEditStart02->setValidator(validator);
    m_awakeEditEnd02 = new QLineEdit;
    m_awakeEditEnd02->setValidator(validator);
    QHBoxLayout *awakeEditLayout02 = new QHBoxLayout;
    awakeEditLayout02->addWidget(m_awakeEditStart02);
    awakeEditLayout02->addStretch(1);
    awakeEditLayout02->addWidget(m_awakeEditEnd02);

    m_awakeEditStart03 = new QLineEdit;
    m_awakeEditStart03->setValidator(validator);
    m_awakeEditEnd03 = new QLineEdit;
    m_awakeEditEnd03->setValidator(validator);
    QHBoxLayout *awakeEditLayout03 = new QHBoxLayout;
    awakeEditLayout03->addWidget(m_awakeEditStart03);
    awakeEditLayout03->addStretch(1);
    awakeEditLayout03->addWidget(m_awakeEditEnd03);

    m_awakeEditStart04 = new QLineEdit;
    m_awakeEditStart04->setValidator(validator);
    m_awakeEditEnd04 = new QLineEdit;
    m_awakeEditEnd04->setValidator(validator);
    QHBoxLayout *awakeEditLayout04 = new QHBoxLayout;
    awakeEditLayout04->addWidget(m_awakeEditStart04);
    awakeEditLayout04->addStretch(1);
    awakeEditLayout04->addWidget(m_awakeEditEnd04);

    m_insertButton = new QPushButton;
    m_insertButton->setText("Insert");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(dateLabel);
    mainLayout->addWidget(m_dateEdit);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(sleepLabel);
    mainLayout->addLayout(sleepEditLayout01);
    mainLayout->addLayout(sleepEditLayout02);
    mainLayout->addLayout(sleepEditLayout03);
    mainLayout->addLayout(sleepEditLayout04);
    mainLayout->addLayout(sleepEditLayout05);
    mainLayout->addLayout(sleepEditLayout06);
    mainLayout->addLayout(sleepEditLayout07);
    mainLayout->addLayout(sleepEditLayout08);
    mainLayout->addLayout(sleepEditLayout09);
    mainLayout->addLayout(sleepEditLayout10);
    mainLayout->addWidget(awakeLabel);
    mainLayout->addLayout(awakeEditLayout01);
    mainLayout->addLayout(awakeEditLayout02);
    mainLayout->addLayout(awakeEditLayout03);
    mainLayout->addLayout(awakeEditLayout04);
    mainLayout->addStretch(1);
    mainLayout->addWidget(m_insertButton);
    this->setLayout(mainLayout);
}

void SleepInsertInput::initConnect(){

}

void SleepInsertInput::onInsertClicked(){

}
















SleepInput::SleepInput(QWidget *parent)
    :QDialog(parent)
{
    this->initData();
    this->initUI();
    this->initConnect();
}

SleepInput::~SleepInput(){
    delete m_sleepQueryInput;
    delete m_sleepInsertInput;
    delete tabWidget;
}

void SleepInput::initData(){

}

void SleepInput::initUI(){
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedWidth(300);
    this->setFixedHeight(600);

    this->setWindowIcon(QIcon(":/images/sleep.png"));
    this->setWindowTitle("Sleep Data");

    m_sleepQueryInput = new SleepQueryInput;
    m_sleepInsertInput = new SleepInsertInput;

    tabWidget = new QTabWidget;
    tabWidget->setContentsMargins(5, 5, 5, 5);
    tabWidget->addTab(m_sleepQueryInput, "Sleep Query");
    tabWidget->addTab(m_sleepInsertInput, "Sleep Insert");

    //布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    this->setLayout(mainLayout);
}

void SleepInput::initConnect(){
    connect(m_sleepQueryInput, SIGNAL(search(QList<Bean::Sleep>)), this, SIGNAL(search(QList<Bean::Sleep>)));
}
