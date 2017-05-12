#ifndef SLEEPINPUT
#define SLEEPINPUT

#include <QtWidgets>
#include "db.h"
#include "sleep.h"

class SleepQueryInput : public QWidget{
    Q_OBJECT

public:
    SleepQueryInput(QWidget *parent = NULL);
    ~SleepQueryInput();

signals:
    void search(QList<Bean::Sleep>);

private:
    void initUI();
    void initConnect();

private slots:
    void onSearchClicked();

private:
    Db *m_db;
    QComboBox *m_personComboBox;
    QDateEdit *m_fDateEdit;
    QDateEdit *m_tDateEdit;
    QPushButton *m_searchButton;
};

class SleepInsertInput : public QWidget{
    Q_OBJECT

public:
    SleepInsertInput(QWidget *parent = NULL);
    ~SleepInsertInput();

private:
    void initUI();
    void initConnect();

private slots:
    void onInsertClicked();
    void onEditingFinished();

private:
    Db *m_db;
    QComboBox *m_personComboBox;
    QDateEdit *m_dateEdit;
    QLineEdit *m_sleepEditStart00;
    QLineEdit *m_sleepEditEnd00;
    QLineEdit *m_sleepEditStart01;
    QLineEdit *m_sleepEditEnd01;
    QLineEdit *m_sleepEditStart02;
    QLineEdit *m_sleepEditEnd02;
    QLineEdit *m_sleepEditStart03;
    QLineEdit *m_sleepEditEnd03;
    QLineEdit *m_sleepEditStart04;
    QLineEdit *m_sleepEditEnd04;
    QLineEdit *m_sleepEditStart05;
    QLineEdit *m_sleepEditEnd05;
    QLineEdit *m_sleepEditStart06;
    QLineEdit *m_sleepEditEnd06;
    QLineEdit *m_sleepEditStart07;
    QLineEdit *m_sleepEditEnd07;
    QLineEdit *m_sleepEditStart08;
    QLineEdit *m_sleepEditEnd08;
    QLineEdit *m_sleepEditStart09;
    QLineEdit *m_sleepEditEnd09;
    QLineEdit *m_sleepEditStart10;
    QLineEdit *m_sleepEditEnd10;
    QLineEdit *m_awakeEditStart01;
    QLineEdit *m_awakeEditEnd01;
    QLineEdit *m_awakeEditStart02;
    QLineEdit *m_awakeEditEnd02;
    QLineEdit *m_awakeEditStart03;
    QLineEdit *m_awakeEditEnd03;
    QLineEdit *m_awakeEditStart04;
    QLineEdit *m_awakeEditEnd04;
    QPushButton *m_insertButton;
};

class SleepInput : public QDialog{
    Q_OBJECT

public:
    SleepInput(QWidget *parent = 0);
    ~SleepInput();

signals:
    void search(QList<Bean::Sleep>);

private:
    void initData();
    void initUI();
    void initConnect();

private:
    SleepQueryInput *m_sleepQueryInput;
    SleepInsertInput *m_sleepInsertInput;
    QTabWidget *tabWidget;
};

#endif // SLEEPINPUT

