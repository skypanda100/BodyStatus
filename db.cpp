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

double Db::getTruncChartTime(QString dateTimeStr1, QString dateTimeStr2){
    if(dateTimeStr1.isEmpty() || dateTimeStr2.isEmpty()){
        return 0;
    }
    QDateTime dateTime1 = QDateTime::fromString(dateTimeStr1, "yyyy-MM-ddThh:mm:ss");
    int timet1 = dateTime1.toTime_t();
    QDateTime dateTime2 = QDateTime::fromString(dateTimeStr2, "yyyy-MM-ddThh:mm:ss");
    int timet2 = dateTime2.toTime_t();

    int minusTimet = timet1 - QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd 00:00:00"), "yyyy-MM-dd 00:00:00").toTime_t();
    timet2 -= minusTimet;

    return Chart::chartTime2(timet2);
}

QList<Bean::Sleep> Db::querySleep(QString queryStr){
    QList<Bean::Sleep> sleeps;

    QSqlQuery query(queryStr);
    while (query.next()){
        Bean::Sleep sleep;
        QString dateStr = query.value("date").toString();
        sleep.setDate(getChartTime(dateStr));
        sleep.setStart(getTruncChartTime(dateStr, query.value("start").toString()));
        sleep.setEnd(getTruncChartTime(dateStr, query.value("end").toString()));
        sleep.setDeepStart01(getTruncChartTime(dateStr, query.value("deepStart01").toString()));
        sleep.setDeepEnd01(getTruncChartTime(dateStr, query.value("deepEnd01").toString()));
        sleep.setDeepStart02(getTruncChartTime(dateStr, query.value("deepStart02").toString()));
        sleep.setDeepEnd02(getTruncChartTime(dateStr, query.value("deepEnd02").toString()));
        sleep.setDeepStart03(getTruncChartTime(dateStr, query.value("deepStart03").toString()));
        sleep.setDeepEnd03(getTruncChartTime(dateStr, query.value("deepEnd03").toString()));
        sleep.setDeepStart04(getTruncChartTime(dateStr, query.value("deepStart04").toString()));
        sleep.setDeepEnd04(getTruncChartTime(dateStr, query.value("deepEnd04").toString()));
        sleep.setDeepStart05(getTruncChartTime(dateStr, query.value("deepStart05").toString()));
        sleep.setDeepEnd05(getTruncChartTime(dateStr, query.value("deepEnd05").toString()));
        sleep.setDeepStart06(getTruncChartTime(dateStr, query.value("deepStart06").toString()));
        sleep.setDeepEnd06(getTruncChartTime(dateStr, query.value("deepEnd06").toString()));
        sleep.setDeepStart07(getTruncChartTime(dateStr, query.value("deepStart07").toString()));
        sleep.setDeepEnd07(getTruncChartTime(dateStr, query.value("deepEnd07").toString()));
        sleep.setDeepStart08(getTruncChartTime(dateStr, query.value("deepStart08").toString()));
        sleep.setDeepEnd08(getTruncChartTime(dateStr, query.value("deepEnd08").toString()));
        sleep.setDeepStart09(getTruncChartTime(dateStr, query.value("deepStart09").toString()));
        sleep.setDeepEnd09(getTruncChartTime(dateStr, query.value("deepEnd09").toString()));
        sleep.setDeepStart10(getTruncChartTime(dateStr, query.value("deepStart10").toString()));
        sleep.setDeepEnd10(getTruncChartTime(dateStr, query.value("deepEnd10").toString()));
        sleep.setAwakeStart01(getTruncChartTime(dateStr, query.value("awakeStart01").toString()));
        sleep.setAwakeEnd01(getTruncChartTime(dateStr, query.value("awakeEnd01").toString()));
        sleep.setAwakeStart02(getTruncChartTime(dateStr, query.value("awakeStart02").toString()));
        sleep.setAwakeEnd02(getTruncChartTime(dateStr, query.value("awakeEnd02").toString()));
        sleep.setAwakeStart03(getTruncChartTime(dateStr, query.value("awakeStart03").toString()));
        sleep.setAwakeEnd03(getTruncChartTime(dateStr, query.value("awakeEnd03").toString()));
        sleep.setAwakeStart04(getTruncChartTime(dateStr, query.value("awakeStart04").toString()));
        sleep.setAwakeEnd04(getTruncChartTime(dateStr, query.value("awakeEnd04").toString()));
        sleeps.append(sleep);
    }

    return sleeps;
}