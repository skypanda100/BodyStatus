#ifndef SLEEPINPUT
#define SLEEPINPUT

#include <QtWidgets>
#include "db.h"
#include "sleep.h"

class SleepInput : public QDialog{
    Q_OBJECT

public:
    SleepInput(QWidget *parent = NULL);
    ~SleepInput();

signals:
    void search(int, QList<Bean::Sleep>);

private:
    void initUI();
    void initConnect();

private slots:
    void onSearchClicked();

private:
    Db *m_db;
    QComboBox *m_personComboBox;
    QComboBox *m_moduleComboBox;
    QDateEdit *m_fDateEdit;
    QDateEdit *m_tDateEdit;
    QPushButton *m_searchButton;
};

#endif // SLEEPINPUT

