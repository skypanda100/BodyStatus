#include "sleep.h"


using namespace Bean;

Sleep::Sleep()
    : m_person(0)
    , m_date(0)
    , m_start(0)
    , m_end(0)
    , m_sleepSum(0)
    , m_deepSleepSum(0)
    , m_awakeSum(0)
    , m_deepStart01(0)
    , m_deepEnd01(0)
    , m_deepStart02(0)
    , m_deepEnd02(0)
    , m_deepStart03(0)
    , m_deepEnd03(0)
    , m_deepStart04(0)
    , m_deepEnd04(0)
    , m_deepStart05(0)
    , m_deepEnd05(0)
    , m_deepStart06(0)
    , m_deepEnd06(0)
    , m_deepStart07(0)
    , m_deepEnd07(0)
    , m_deepStart08(0)
    , m_deepEnd08(0)
    , m_deepStart09(0)
    , m_deepEnd09(0)
    , m_deepStart10(0)
    , m_deepEnd10(0)
    , m_awakeStart01(0)
    , m_awakeEnd01(0)
    , m_awakeStart02(0)
    , m_awakeEnd02(0)
    , m_awakeStart03(0)
    , m_awakeEnd03(0)
    , m_awakeStart04(0)
    , m_awakeEnd04(0)
{

}

Sleep::~Sleep(){

}

double Sleep::date() const
{
    return m_date;
}

void Sleep::setDate(double date)
{
    m_date = date;
}

double Sleep::start() const
{
    return m_start;
}

void Sleep::setStart(double start)
{
    m_start = start;
}

double Sleep::end() const
{
    return m_end;
}

void Sleep::setEnd(double end)
{
    m_end = end;
}

double Sleep::deepStart01() const
{
    return m_deepStart01;
}

void Sleep::setDeepStart01(double deepStart01)
{
    m_deepStart01 = deepStart01;
}

double Sleep::deepEnd01() const
{
    return m_deepEnd01;
}

void Sleep::setDeepEnd01(double deepEnd01)
{
    m_deepEnd01 = deepEnd01;
}

double Sleep::deepStart02() const
{
    return m_deepStart02;
}

void Sleep::setDeepStart02(double deepStart02)
{
    m_deepStart02 = deepStart02;
}

double Sleep::deepEnd02() const
{
    return m_deepEnd02;
}

void Sleep::setDeepEnd02(double deepEnd02)
{
    m_deepEnd02 = deepEnd02;
}

double Sleep::deepStart03() const
{
    return m_deepStart03;
}

void Sleep::setDeepStart03(double deepStart03)
{
    m_deepStart03 = deepStart03;
}

double Sleep::deepEnd03() const
{
    return m_deepEnd03;
}

void Sleep::setDeepEnd03(double deepEnd03)
{
    m_deepEnd03 = deepEnd03;
}

double Sleep::deepStart04() const
{
    return m_deepStart04;
}

void Sleep::setDeepStart04(double deepStart04)
{
    m_deepStart04 = deepStart04;
}

double Sleep::deepEnd04() const
{
    return m_deepEnd04;
}

void Sleep::setDeepEnd04(double deepEnd04)
{
    m_deepEnd04 = deepEnd04;
}

double Sleep::deepStart05() const
{
    return m_deepStart05;
}

void Sleep::setDeepStart05(double deepStart05)
{
    m_deepStart05 = deepStart05;
}

double Sleep::deepEnd05() const
{
    return m_deepEnd05;
}

void Sleep::setDeepEnd05(double deepEnd05)
{
    m_deepEnd05 = deepEnd05;
}

double Sleep::deepStart06() const
{
    return m_deepStart06;
}

void Sleep::setDeepStart06(double deepStart06)
{
    m_deepStart06 = deepStart06;
}

double Sleep::deepEnd06() const
{
    return m_deepEnd06;
}

void Sleep::setDeepEnd06(double deepEnd06)
{
    m_deepEnd06 = deepEnd06;
}

double Sleep::deepStart07() const
{
    return m_deepStart07;
}

void Sleep::setDeepStart07(double deepStart07)
{
    m_deepStart07 = deepStart07;
}

double Sleep::deepEnd07() const
{
    return m_deepEnd07;
}

void Sleep::setDeepEnd07(double deepEnd07)
{
    m_deepEnd07 = deepEnd07;
}

double Sleep::deepStart08() const
{
    return m_deepStart08;
}

void Sleep::setDeepStart08(double deepStart08)
{
    m_deepStart08 = deepStart08;
}

double Sleep::deepEnd08() const
{
    return m_deepEnd08;
}

void Sleep::setDeepEnd08(double deepEnd08)
{
    m_deepEnd08 = deepEnd08;
}

double Sleep::deepStart09() const
{
    return m_deepStart09;
}

void Sleep::setDeepStart09(double deepStart09)
{
    m_deepStart09 = deepStart09;
}

double Sleep::deepEnd09() const
{
    return m_deepEnd09;
}

void Sleep::setDeepEnd09(double deepEnd09)
{
    m_deepEnd09 = deepEnd09;
}

double Sleep::deepStart10() const
{
    return m_deepStart10;
}

void Sleep::setDeepStart10(double deepStart10)
{
    m_deepStart10 = deepStart10;
}

double Sleep::deepEnd10() const
{
    return m_deepEnd10;
}

void Sleep::setDeepEnd10(double deepEnd10)
{
    m_deepEnd10 = deepEnd10;
}
double Sleep::awakeStart01() const
{
    return m_awakeStart01;
}

void Sleep::setAwakeStart01(double awakeStart01)
{
    m_awakeStart01 = awakeStart01;
}

double Sleep::awakeEnd01() const
{
    return m_awakeEnd01;
}

void Sleep::setAwakeEnd01(double awakeEnd01)
{
    m_awakeEnd01 = awakeEnd01;
}

double Sleep::awakeStart02() const
{
    return m_awakeStart02;
}

void Sleep::setAwakeStart02(double awakeStart02)
{
    m_awakeStart02 = awakeStart02;
}

double Sleep::awakeEnd02() const
{
    return m_awakeEnd02;
}

void Sleep::setAwakeEnd02(double awakeEnd02)
{
    m_awakeEnd02 = awakeEnd02;
}

double Sleep::awakeStart03() const
{
    return m_awakeStart03;
}

void Sleep::setAwakeStart03(double awakeStart03)
{
    m_awakeStart03 = awakeStart03;
}

double Sleep::awakeEnd03() const
{
    return m_awakeEnd03;
}

void Sleep::setAwakeEnd03(double awakeEnd03)
{
    m_awakeEnd03 = awakeEnd03;
}

double Sleep::awakeStart04() const
{
    return m_awakeStart04;
}

void Sleep::setAwakeStart04(double awakeStart04)
{
    m_awakeStart04 = awakeStart04;
}

double Sleep::awakeEnd04() const
{
    return m_awakeEnd04;
}

void Sleep::setAwakeEnd04(double awakeEnd04)
{
    m_awakeEnd04 = awakeEnd04;
}

double Sleep::sleepSum() const
{
    return m_sleepSum;
}

void Sleep::setSleepSum(double sleepSum)
{
    m_sleepSum = sleepSum;
}

double Sleep::deepSleepSum() const
{
    return m_deepSleepSum;
}

void Sleep::setDeepSleepSum(double deepSleepSum)
{
    m_deepSleepSum = deepSleepSum;
}

double Sleep::awakeSum() const
{
    return m_awakeSum;
}

void Sleep::setAwakeSum(double awakeSum)
{
    m_awakeSum = awakeSum;
}

int Sleep::person() const
{
    return m_person;
}

void Sleep::setPerson(int person)
{
    m_person = person;
}

