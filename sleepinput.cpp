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
    delete m_personComboBox;
    delete m_sleepEditStart00;
    delete m_sleepEditEnd00;
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
    delete m_clearButton;
    delete m_insertButton;
}

void SleepInsertInput::initUI(){
    m_db = new Db;

    QFont labelFont;
    labelFont.setBold(true);

    QLabel *personLabel = new QLabel;
    personLabel->setFont(labelFont);
    personLabel->setText("Person");

    m_personComboBox = new QComboBox;
    m_personComboBox->insertItem(0, "gg");
    m_personComboBox->insertItem(1, "tt");

    QLabel *dateLabel = new QLabel;
    dateLabel->setFont(labelFont);
    dateLabel->setText("Date");

    m_dateEdit = new QDateEdit;
    m_dateEdit->setDate(QDateTime::currentDateTime().date());
    m_dateEdit->setCalendarPopup(true);

    QRegExp regExp("^(([0-1][0-9])|(2[0-3]))[0-5][0-9]$");
    QValidator *validator = new QRegExpValidator(regExp, 0);

    QLabel *sleepFullLabel = new QLabel;
    sleepFullLabel->setFont(labelFont);
    sleepFullLabel->setText("Sleep");

    m_sleepEditStart00 = new QLineEdit;
    m_sleepEditStart00->setValidator(validator);
    m_sleepEditEnd00 = new QLineEdit;
    m_sleepEditEnd00->setValidator(validator);
    QHBoxLayout *sleepEditLayout00 = new QHBoxLayout;
    sleepEditLayout00->addWidget(m_sleepEditStart00);
    sleepEditLayout00->addStretch(1);
    sleepEditLayout00->addWidget(m_sleepEditEnd00);

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

    m_clearButton = new QPushButton;
    m_clearButton->setText("Clear");
    m_insertButton = new QPushButton;
    m_insertButton->setText("Insert");
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_clearButton);
    buttonLayout->addWidget(m_insertButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(personLabel);
    mainLayout->addWidget(m_personComboBox);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(dateLabel);
    mainLayout->addWidget(m_dateEdit);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(sleepFullLabel);
    mainLayout->addLayout(sleepEditLayout00);
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
    mainLayout->addLayout(buttonLayout);
    this->setLayout(mainLayout);
}

void SleepInsertInput::initConnect(){
    connect(m_sleepEditStart00, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd00, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart01, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd01, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart02, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd02, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart03, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd03, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart04, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd04, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart05, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd05, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart06, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd06, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart07, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd07, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart08, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd08, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart09, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd09, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditStart10, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_sleepEditEnd10, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditStart01, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditEnd01, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditStart02, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditEnd02, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditStart03, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditEnd03, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditStart04, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_awakeEditEnd04, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(m_clearButton, SIGNAL(clicked()), this, SLOT(onClearClicked()));
    connect(m_insertButton, SIGNAL(clicked()), this, SLOT(onInsertClicked()));
}

void SleepInsertInput::onClearClicked(){
    m_sleepEditStart00->clear();
    m_sleepEditEnd00->clear();
    m_sleepEditStart01->clear();
    m_sleepEditEnd01->clear();
    m_sleepEditStart02->clear();
    m_sleepEditEnd02->clear();
    m_sleepEditStart03->clear();
    m_sleepEditEnd03->clear();
    m_sleepEditStart04->clear();
    m_sleepEditEnd04->clear();
    m_sleepEditStart05->clear();
    m_sleepEditEnd05->clear();
    m_sleepEditStart06->clear();
    m_sleepEditEnd06->clear();
    m_sleepEditStart07->clear();
    m_sleepEditEnd07->clear();
    m_sleepEditStart08->clear();
    m_sleepEditEnd08->clear();
    m_sleepEditStart09->clear();
    m_sleepEditEnd09->clear();
    m_sleepEditStart10->clear();
    m_sleepEditEnd10->clear();
    m_awakeEditStart01->clear();
    m_awakeEditEnd01->clear();
    m_awakeEditStart02->clear();
    m_awakeEditEnd02->clear();
    m_awakeEditStart03->clear();
    m_awakeEditEnd03->clear();
    m_awakeEditStart04->clear();
    m_awakeEditEnd04->clear();
}

void SleepInsertInput::onInsertClicked(){
    int person = m_personComboBox->currentIndex();
    QString date = m_dateEdit->dateTime().toString("yyyy-MM-dd hh:mm:00");
    QString sleepStart00 = m_sleepEditStart00->text();
    QString sleepEnd00 = m_sleepEditEnd00->text();
    QString sleepStart01 = m_sleepEditStart01->text();
    QString sleepEnd01 = m_sleepEditEnd01->text();
    QString sleepStart02 = m_sleepEditStart02->text();
    QString sleepEnd02 = m_sleepEditEnd02->text();
    QString sleepStart03 = m_sleepEditStart03->text();
    QString sleepEnd03 = m_sleepEditEnd03->text();
    QString sleepStart04 = m_sleepEditStart04->text();
    QString sleepEnd04 = m_sleepEditEnd04->text();
    QString sleepStart05 = m_sleepEditStart05->text();
    QString sleepEnd05 = m_sleepEditEnd05->text();
    QString sleepStart06 = m_sleepEditStart06->text();
    QString sleepEnd06 = m_sleepEditEnd06->text();
    QString sleepStart07 = m_sleepEditStart07->text();
    QString sleepEnd07 = m_sleepEditEnd07->text();
    QString sleepStart08 = m_sleepEditStart08->text();
    QString sleepEnd08 = m_sleepEditEnd08->text();
    QString sleepStart09 = m_sleepEditStart09->text();
    QString sleepEnd09 = m_sleepEditEnd09->text();
    QString sleepStart10 = m_sleepEditStart10->text();
    QString sleepEnd10 = m_sleepEditEnd10->text();
    QString awakeStart01 = m_awakeEditStart01->text();
    QString awakeEnd01 = m_awakeEditEnd01->text();
    QString awakeStart02 = m_awakeEditStart02->text();
    QString awakeEnd02 = m_awakeEditEnd02->text();
    QString awakeStart03 = m_awakeEditStart03->text();
    QString awakeEnd03 = m_awakeEditEnd03->text();
    QString awakeStart04 = m_awakeEditStart04->text();
    QString awakeEnd04 = m_awakeEditEnd04->text();

    QList<QVariant> argList;
    argList.append(person);
    argList.append(date);
    argList.append(sleepStart00);
    argList.append(sleepEnd00);
    argList.append(sleepStart01.isEmpty() ? NULL : sleepStart01);
    argList.append(sleepEnd01.isEmpty() ? NULL : sleepEnd01);
    argList.append(sleepStart02.isEmpty() ? NULL : sleepStart02);
    argList.append(sleepEnd02.isEmpty() ? NULL : sleepEnd02);
    argList.append(sleepStart03.isEmpty() ? NULL : sleepStart03);
    argList.append(sleepEnd03.isEmpty() ? NULL : sleepEnd03);
    argList.append(sleepStart04.isEmpty() ? NULL : sleepStart04);
    argList.append(sleepEnd04.isEmpty() ? NULL : sleepEnd04);
    argList.append(sleepStart05.isEmpty() ? NULL : sleepStart05);
    argList.append(sleepEnd05.isEmpty() ? NULL : sleepEnd05);
    argList.append(sleepStart06.isEmpty() ? NULL : sleepStart06);
    argList.append(sleepEnd06.isEmpty() ? NULL : sleepEnd06);
    argList.append(sleepStart07.isEmpty() ? NULL : sleepStart07);
    argList.append(sleepEnd07.isEmpty() ? NULL : sleepEnd07);
    argList.append(sleepStart08.isEmpty() ? NULL : sleepStart08);
    argList.append(sleepEnd08.isEmpty() ? NULL : sleepEnd08);
    argList.append(sleepStart09.isEmpty() ? NULL : sleepStart09);
    argList.append(sleepEnd09.isEmpty() ? NULL : sleepEnd09);
    argList.append(sleepStart10.isEmpty() ? NULL : sleepStart10);
    argList.append(sleepEnd10.isEmpty() ? NULL : sleepEnd10);
    argList.append(awakeStart01.isEmpty() ? NULL : awakeStart01);
    argList.append(awakeEnd01.isEmpty() ? NULL : awakeEnd01);
    argList.append(awakeStart02.isEmpty() ? NULL : awakeStart02);
    argList.append(awakeEnd02.isEmpty() ? NULL : awakeEnd02);
    argList.append(awakeStart03.isEmpty() ? NULL : awakeStart03);
    argList.append(awakeEnd03.isEmpty() ? NULL : awakeEnd03);
    argList.append(awakeStart04.isEmpty() ? NULL : awakeStart04);
    argList.append(awakeEnd04.isEmpty() ? NULL : awakeEnd04);

    if(!(m_db->insertSleep(argList))){
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              "insert sleep data failed");
    }else{
        QMessageBox::information(0, QObject::tr("Database Infomation"),
                              "insert sleep data successfully");
    }
}

void SleepInsertInput::onEditingFinished(){
    int minutesFull = 24 * 60;
    int minutesStd = 18 * 60;
    QLineEdit *lineEdit = (QLineEdit *)(this->sender());
    QString hhmmStr = lineEdit->text().trimmed();
    QDateTime dateTime = m_dateEdit->dateTime();
    int hour = hhmmStr.mid(0, 2).toInt(0, 10);
    int minute = hhmmStr.mid(2, 2).toInt(0, 10);
    int minutes = hour * 60 + minute;
    if(minutes >= minutesStd){
        dateTime = dateTime.addSecs(-(minutesFull - minutes) * 60);
    }else{
        dateTime = dateTime.addSecs(minutes * 60);
    }
    lineEdit->setText(dateTime.toString("yyyy-MM-dd hh:mm"));
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
    this->setFixedHeight(700);

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
