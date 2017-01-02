#ifndef SLEEP
#define SLEEP
#include <QDateTime>

namespace Bean{

class Sleep{
public:
    Sleep();
    ~Sleep();

    double date() const;
    void setDate(double date);

    double start() const;
    void setStart(double start);

    double end() const;
    void setEnd(double end);

    double deepStart01() const;
    void setDeepStart01(double deepStart01);

    double deepEnd01() const;
    void setDeepEnd01(double deepEnd01);

    double deepStart02() const;
    void setDeepStart02(double deepStart02);

    double deepEnd02() const;
    void setDeepEnd02(double deepEnd02);

    double deepStart03() const;
    void setDeepStart03(double deepStart03);

    double deepEnd03() const;
    void setDeepEnd03(double deepEnd03);

    double deepStart04() const;
    void setDeepStart04(double deepStart04);

    double deepEnd04() const;
    void setDeepEnd04(double deepEnd04);

    double deepStart05() const;
    void setDeepStart05(double deepStart05);

    double deepEnd05() const;
    void setDeepEnd05(double deepEnd05);

    double deepStart06() const;
    void setDeepStart06(double deepStart06);

    double deepEnd06() const;
    void setDeepEnd06(double deepEnd06);

    double deepStart07() const;
    void setDeepStart07(double deepStart07);

    double deepEnd07() const;
    void setDeepEnd07(double deepEnd07);

    double deepStart08() const;
    void setDeepStart08(double deepStart08);

    double deepEnd08() const;
    void setDeepEnd08(double deepEnd08);

    double deepStart09() const;
    void setDeepStart09(double deepStart09);

    double deepEnd09() const;
    void setDeepEnd09(double deepEnd09);

    double deepStart10() const;
    void setDeepStart10(double deepStart10);

    double deepEnd10() const;
    void setDeepEnd10(double deepEnd10);

    double awakeStart01() const;
    void setAwakeStart01(double awakeStart01);

    double awakeEnd01() const;
    void setAwakeEnd01(double awakeEnd01);

    double awakeStart02() const;
    void setAwakeStart02(double awakeStart02);

    double awakeEnd02() const;
    void setAwakeEnd02(double awakeEnd02);

    double awakeStart03() const;
    void setAwakeStart03(double awakeStart03);

    double awakeEnd03() const;
    void setAwakeEnd03(double awakeEnd03);

    double awakeStart04() const;
    void setAwakeStart04(double awakeStart04);

    double awakeEnd04() const;
    void setAwakeEnd04(double awakeEnd04);

    double sleepSum() const;
    void setSleepSum(double sleepSum);

    double deepSleepSum() const;
    void setDeepSleepSum(double deepSleepSum);

    double awakeSum() const;
    void setAwakeSum(double awakeSum);

private:
    double m_date;
    double m_start;
    double m_end;
    double m_sleepSum;
    double m_deepSleepSum;
    double m_awakeSum;
    double m_deepStart01;
    double m_deepEnd01;
    double m_deepStart02;
    double m_deepEnd02;
    double m_deepStart03;
    double m_deepEnd03;
    double m_deepStart04;
    double m_deepEnd04;
    double m_deepStart05;
    double m_deepEnd05;
    double m_deepStart06;
    double m_deepEnd06;
    double m_deepStart07;
    double m_deepEnd07;
    double m_deepStart08;
    double m_deepEnd08;
    double m_deepStart09;
    double m_deepEnd09;
    double m_deepStart10;
    double m_deepEnd10;
    double m_awakeStart01;
    double m_awakeEnd01;
    double m_awakeStart02;
    double m_awakeEnd02;
    double m_awakeStart03;
    double m_awakeEnd03;
    double m_awakeStart04;
    double m_awakeEnd04;
};

}

#endif // SLEEP

