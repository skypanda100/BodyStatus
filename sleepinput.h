#ifndef SLEEPINPUT
#define SLEEPINPUT

#include <QtWidgets>

class SleepInput : public QDialog{
    Q_OBJECT

public:
    SleepInput(QWidget *parent = NULL);
    ~SleepInput();

private:
    void initUI();
    void initConnect();

private slots:
    void onSearchClicked();

private:
    QDateEdit *m_fDateEdit;
    QDateEdit *m_tDateEdit;
    QPushButton *m_searchButton;
};

#endif // SLEEPINPUT

