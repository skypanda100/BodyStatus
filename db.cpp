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

        sleep.setPerson(query.value("person").toInt(0));

        QString dateStr = query.value("date").toString();
        sleep.setDate(getChartTime(dateStr));

        QString startStr = query.value("start").toString();
        sleep.setStart(getTruncChartTime(dateStr, startStr));
        QString endStr = query.value("end").toString();
        sleep.setEnd(getTruncChartTime(dateStr, endStr));

        QString deepStart01Str = query.value("deepStart01").toString();
        sleep.setDeepStart01(getTruncChartTime(dateStr, deepStart01Str));
        QString deepEnd01Str = query.value("deepEnd01").toString();
        sleep.setDeepEnd01(getTruncChartTime(dateStr, deepEnd01Str));

        QString deepStart02Str = query.value("deepStart02").toString();
        sleep.setDeepStart02(getTruncChartTime(dateStr, deepStart02Str));
        QString deepEnd02Str = query.value("deepEnd02").toString();
        sleep.setDeepEnd02(getTruncChartTime(dateStr, deepEnd02Str));

        QString deepStart03Str = query.value("deepStart03").toString();
        sleep.setDeepStart03(getTruncChartTime(dateStr, deepStart03Str));
        QString deepEnd03Str = query.value("deepEnd03").toString();
        sleep.setDeepEnd03(getTruncChartTime(dateStr, deepEnd03Str));

        QString deepStart04Str = query.value("deepStart04").toString();
        sleep.setDeepStart04(getTruncChartTime(dateStr, deepStart04Str));
        QString deepEnd04Str = query.value("deepEnd04").toString();
        sleep.setDeepEnd04(getTruncChartTime(dateStr, deepEnd04Str));

        QString deepStart05Str = query.value("deepStart05").toString();
        sleep.setDeepStart05(getTruncChartTime(dateStr, deepStart05Str));
        QString deepEnd05Str = query.value("deepEnd05").toString();
        sleep.setDeepEnd05(getTruncChartTime(dateStr, deepEnd05Str));

        QString deepStart06Str = query.value("deepStart06").toString();
        sleep.setDeepStart06(getTruncChartTime(dateStr, deepStart06Str));
        QString deepEnd06Str = query.value("deepEnd06").toString();
        sleep.setDeepEnd06(getTruncChartTime(dateStr, deepEnd06Str));

        QString deepStart07Str = query.value("deepStart07").toString();
        sleep.setDeepStart07(getTruncChartTime(dateStr, deepStart07Str));
        QString deepEnd07Str = query.value("deepEnd07").toString();
        sleep.setDeepEnd07(getTruncChartTime(dateStr, deepEnd07Str));

        QString deepStart08Str = query.value("deepStart08").toString();
        sleep.setDeepStart08(getTruncChartTime(dateStr, deepStart08Str));
        QString deepEnd08Str = query.value("deepEnd08").toString();
        sleep.setDeepEnd08(getTruncChartTime(dateStr, deepEnd08Str));

        QString deepStart09Str = query.value("deepStart09").toString();
        sleep.setDeepStart09(getTruncChartTime(dateStr, deepStart09Str));
        QString deepEnd09Str = query.value("deepEnd09").toString();
        sleep.setDeepEnd09(getTruncChartTime(dateStr, deepEnd09Str));

        QString deepStart10Str = query.value("deepStart10").toString();
        sleep.setDeepStart10(getTruncChartTime(dateStr, deepStart10Str));
        QString deepEnd10Str = query.value("deepEnd10").toString();
        sleep.setDeepEnd10(getTruncChartTime(dateStr, deepEnd10Str));

        QString awakeStart01Str = query.value("awakeStart01").toString();
        sleep.setAwakeStart01(getTruncChartTime(dateStr, awakeStart01Str));
        QString awakeEnd01Str = query.value("awakeEnd01").toString();
        sleep.setAwakeEnd01(getTruncChartTime(dateStr, awakeEnd01Str));

        QString awakeStart02Str = query.value("awakeStart02").toString();
        sleep.setAwakeStart02(getTruncChartTime(dateStr, awakeStart02Str));
        QString awakeEnd02Str = query.value("awakeEnd02").toString();
        sleep.setAwakeEnd02(getTruncChartTime(dateStr, awakeEnd02Str));

        QString awakeStart03Str = query.value("awakeStart03").toString();
        sleep.setAwakeStart03(getTruncChartTime(dateStr, awakeStart03Str));
        QString awakeEnd03Str = query.value("awakeEnd03").toString();
        sleep.setAwakeEnd03(getTruncChartTime(dateStr, awakeEnd03Str));

        QString awakeStart04Str = query.value("awakeStart04").toString();
        sleep.setAwakeStart04(getTruncChartTime(dateStr, awakeStart04Str));
        QString awakeEnd04Str = query.value("awakeEnd04").toString();
        sleep.setAwakeEnd04(getTruncChartTime(dateStr, awakeEnd04Str));

        double sleepMinutes = 0;
        if(!awakeStart01Str.isEmpty() && !awakeEnd01Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(awakeStart01Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(awakeEnd01Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!awakeStart02Str.isEmpty() && !awakeEnd02Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(awakeStart02Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(awakeEnd02Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!awakeStart03Str.isEmpty() && !awakeEnd03Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(awakeStart03Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(awakeEnd03Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!awakeStart04Str.isEmpty() && !awakeEnd04Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(awakeStart04Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(awakeEnd04Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        sleep.setAwakeSum(sleepMinutes / 60);

        sleepMinutes = 0;
        if(!deepStart01Str.isEmpty() && !deepEnd01Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart01Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd01Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart02Str.isEmpty() && !deepEnd02Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart02Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd02Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart03Str.isEmpty() && !deepEnd03Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart03Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd03Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart04Str.isEmpty() && !deepEnd04Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart04Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd04Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart05Str.isEmpty() && !deepEnd05Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart05Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd05Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart06Str.isEmpty() && !deepEnd06Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart06Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd06Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart07Str.isEmpty() && !deepEnd07Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart07Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd07Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart08Str.isEmpty() && !deepEnd08Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart08Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd08Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart09Str.isEmpty() && !deepEnd09Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart09Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd09Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        if(!deepStart10Str.isEmpty() && !deepEnd10Str.isEmpty()){
            QDateTime startDate = QDateTime::fromString(deepStart10Str, "yyyy-MM-ddThh:mm:ss");
            QDateTime endDate = QDateTime::fromString(deepEnd10Str, "yyyy-MM-ddThh:mm:ss");
            sleepMinutes += startDate.secsTo(endDate) / 60;
        }
        sleep.setDeepSleepSum(sleepMinutes / 60 - sleep.awakeSum());

        sleepMinutes = 0;
        QDateTime startDate = QDateTime::fromString(startStr, "yyyy-MM-ddThh:mm:ss");
        QDateTime endDate = QDateTime::fromString(endStr, "yyyy-MM-ddThh:mm:ss");
        sleepMinutes = startDate.secsTo(endDate) / 60;
        sleep.setSleepSum(sleepMinutes / 60 - sleep.awakeSum() - sleep.deepSleepSum());

        sleeps.append(sleep);
    }

    return sleeps;
}

bool Db::insertSleep(QList<QVariant> argList){
    QString insertStr = QString("insert into status_sleep values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    QSqlQuery query;
    query.prepare(insertStr);
    for(QVariant arg : argList){
        query.addBindValue(arg);
    }
    return query.exec();
}

QString Db::lastError(){
    return db.lastError().text();
}
