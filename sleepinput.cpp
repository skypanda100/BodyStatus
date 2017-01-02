#include "sleepinput.h"

SleepInput::SleepInput(QWidget *parent)
    :QDialog(parent)
{
    this->initUI();
    this->initConnect();
}

SleepInput::~SleepInput(){
    delete m_personComboBox;
    delete m_moduleComboBox;
    delete m_fDateEdit;
    delete m_tDateEdit;
    delete m_searchButton;
    delete m_db;
}

void SleepInput::initUI(){
    m_db = new Db;

    //title
    this->setWindowTitle("Sleep");
    this->setWindowIcon(QIcon(":/image/sleep.png"));
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    QFont labelFont;
    labelFont.setBold(true);

    QLabel *personLabel = new QLabel;
    personLabel->setFont(labelFont);
    personLabel->setText("Person");

    m_personComboBox = new QComboBox;
    m_personComboBox->insertItem(0, "gg");
    m_personComboBox->insertItem(1, "tt");
    m_personComboBox->insertItem(2, "both");

    QLabel *moduleLabel = new QLabel;
    moduleLabel->setFont(labelFont);
    moduleLabel->setText("Module");

    m_moduleComboBox = new QComboBox;
    m_moduleComboBox->insertItem(0, "Sleep Distribution");
    m_moduleComboBox->insertItem(1, "Sleep Duration");
    m_moduleComboBox->insertItem(2, "Sleep Interval");

    QLabel *fromLabel = new QLabel;
    fromLabel->setFont(labelFont);
    fromLabel->setText("From");

    m_fDateEdit = new QDateEdit;
    m_fDateEdit->setFixedWidth(100);
    m_fDateEdit->setDate(QDateTime::currentDateTime().addDays(-7).date());
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
    mainLayout->addWidget(personLabel, 0, 0);
    mainLayout->addWidget(m_personComboBox, 0, 1);
    mainLayout->addWidget(moduleLabel, 1, 0);
    mainLayout->addWidget(m_moduleComboBox, 1, 1);
    mainLayout->addWidget(fromLabel, 2, 0);
    mainLayout->addWidget(m_fDateEdit, 2, 1);
    mainLayout->addWidget(toLabel, 3, 0);
    mainLayout->addWidget(m_tDateEdit, 3, 1);
    mainLayout->addWidget(m_searchButton, 4, 0, 1, 2);
    this->setLayout(mainLayout);
}

void SleepInput::initConnect(){
    connect(m_searchButton, SIGNAL(clicked()), this, SLOT(onSearchClicked()));
}

void SleepInput::onSearchClicked(){
    int personId = m_personComboBox->currentIndex();
    int moduleId = m_moduleComboBox->currentIndex();
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
        emit search(moduleId, sleepLst);
    }else{
        QMessageBox::critical(0, QObject::tr("Search"), "there are no results");
    }

    this->accept();
}
