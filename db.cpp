#include "db.h"
#include <QMessageBox>
#include "chartdir.h"

Db::Db(){
    this->openDb();
}

Db::~Db(){
    this->closeDb();
}

void Db::openDb(){
    db = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString::fromLocal8Bit("Driver={PostgreSQL ODBC Driver(ANSI)};server=127.0.0.1;port=5432;uid=posgres;pwd=123456;database=postgres");
    db.setDatabaseName(dsn);
    db.setUserName("postgres");
    db.setPassword("123456");
    if(!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
    }
}

void Db::closeDb(){
    db.close();
}

double Db::getChartTime(QString dateTimeStr){
    if(dateTimeStr.isEmpty()){
        return 0;
    }
    QDateTime dateTime = QDateTime::fromString(dateTimeStr, "yyyy-MM-ddThh:mm:ss");
    return Chart::chartTime2(dateTime.toTime_t());
}

QList<Bean::Sleep> Db::querySleep(QString queryStr){
    QList<Bean::Sleep> sleeps;

    QSqlQuery query(queryStr);
    while (query.next()){
        Bean::Sleep sleep;
        sleep.setDate(getChartTime(query.value("date").toString()));
        sleep.setStart(getChartTime(query.value("start").toString()));
        sleep.setEnd(getChartTime(query.value("end").toString()));
        sleep.setDeepStart01(getChartTime(query.value("deepStart01").toString()));
        sleep.setDeepEnd01(getChartTime(query.value("deepEnd01").toString()));
        sleep.setDeepStart02(getChartTime(query.value("deepStart02").toString()));
        sleep.setDeepEnd02(getChartTime(query.value("deepEnd02").toString()));
        sleep.setDeepStart03(getChartTime(query.value("deepStart03").toString()));
        sleep.setDeepEnd03(getChartTime(query.value("deepEnd03").toString()));
        sleep.setDeepStart04(getChartTime(query.value("deepStart04").toString()));
        sleep.setDeepEnd04(getChartTime(query.value("deepEnd04").toString()));
        sleep.setDeepStart05(getChartTime(query.value("deepStart05").toString()));
        sleep.setDeepEnd05(getChartTime(query.value("deepEnd05").toString()));
        sleep.setDeepStart06(getChartTime(query.value("deepStart06").toString()));
        sleep.setDeepEnd06(getChartTime(query.value("deepEnd06").toString()));
        sleep.setDeepStart07(getChartTime(query.value("deepStart07").toString()));
        sleep.setDeepEnd07(getChartTime(query.value("deepEnd07").toString()));
        sleep.setDeepStart08(getChartTime(query.value("deepStart08").toString()));
        sleep.setDeepEnd08(getChartTime(query.value("deepEnd08").toString()));
        sleep.setDeepStart09(getChartTime(query.value("deepStart09").toString()));
        sleep.setDeepEnd09(getChartTime(query.value("deepEnd09").toString()));
        sleep.setDeepStart10(getChartTime(query.value("deepStart10").toString()));
        sleep.setDeepEnd10(getChartTime(query.value("deepEnd10").toString()));
        sleep.setAwakeStart01(getChartTime(query.value("awakeStart01").toString()));
        sleep.setAwakeEnd01(getChartTime(query.value("awakeEnd01").toString()));
        sleep.setAwakeStart02(getChartTime(query.value("awakeStart02").toString()));
        sleep.setAwakeEnd02(getChartTime(query.value("awakeEnd02").toString()));
        sleep.setAwakeStart03(getChartTime(query.value("awakeStart03").toString()));
        sleep.setAwakeEnd03(getChartTime(query.value("awakeEnd03").toString()));
        sleep.setAwakeStart04(getChartTime(query.value("awakeStart04").toString()));
        sleep.setAwakeEnd04(getChartTime(query.value("awakeEnd04").toString()));
        sleeps.append(sleep);
    }

    return sleeps;
}
