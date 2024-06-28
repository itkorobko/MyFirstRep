#include <QtTest>
#include "../untitled/calculator.h"
// add necessary includes here

class MyTest1 : public QObject
{
    Q_OBJECT

public:
    MyTest1();
    ~MyTest1();

private slots:
    void testSum();
    void testSub();
    void testMul();
    void testDiv();
};

MyTest1::MyTest1() {}

MyTest1::~MyTest1() {}

void MyTest1::testSum()
{
    Calculator calc;
    QCOMPARE(calc.sum(2.3,4.0),6.3);
    QCOMPARE(calc.sum(0.5,0.0),0.5);
    QCOMPARE(calc.sum(4.1,-5.0),-0.9);
    QCOMPARE(calc.sum(2.8,4.654),7.454);
    QCOMPARE(calc.sum(0.0,0.0),0.0);

}
void MyTest1::testSub()
{
    Calculator calc;
    QCOMPARE(calc.sub(2.3,4.0),-1.7);
    QCOMPARE(calc.sub(0.5,0.0),0.5);
    QCOMPARE(calc.sub(4.1,-5.0),9.1);

    QCOMPARE(calc.sub(0.0,0.0),0.0);

}
void MyTest1::testMul()
{
    Calculator calc;
    QCOMPARE(calc.mul(2.3,4.0),9.2);
    QCOMPARE(calc.mul(0.5,0.0),0.0);
    QCOMPARE(calc.mul(4.1,-5.0),-20.5);

    QCOMPARE(calc.mul(0.0,0.0),0.0);

}
void MyTest1::testDiv()
{
    Calculator calc;
    QCOMPARE(calc.div(4.0,4.0),1.0);
    //QCOMPARE(calc.div(0.5,0.0),0.5);
    QCOMPARE(calc.div(4.2,2.1),2.0);
   // QCOMPARE(calc.div(2.8,4.654),7.454);
   // QCOMPARE(calc.div(0.0,0.0),nan);

}
QTEST_APPLESS_MAIN(MyTest1)

#include "tst_mytest1.moc"
