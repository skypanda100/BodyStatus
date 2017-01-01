#ifndef EA_DB
#define EA_DB

#include <QObject>
#include <QtSql>
#include <QDateTime>
#include "sleep.h"

class Db : public QObject{
    Q_OBJECT

public:
    Db();
    ~Db();

    QList<Bean::Sleep> querySleep(QString);

private:
    void openDb();
    void closeDb();
    double getChartTime(QString);

private:
    QSqlDatabase db;
};

#endif // EA_DB

