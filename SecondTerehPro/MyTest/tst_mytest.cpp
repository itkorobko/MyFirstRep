#include <QtTest>
#include "../SecondTerehApp/myclass.h"
// add necessary includes here

class MyTest : public QObject
{
    Q_OBJECT

public:
    MyTest();
    ~MyTest();

private slots:
    void test_case1();
};

MyTest::MyTest() {}

MyTest::~MyTest() {}

void MyTest::test_case1()
{
    MyClass mc;
    QCOMPARE(mc.prime_num(-1),false);
    QCOMPARE(mc.prime_num(0),false);
    QCOMPARE(mc.prime_num(1),false);
    QCOMPARE(mc.prime_num(3),true);

}

QTEST_APPLESS_MAIN(MyTest)

#include "tst_mytest.moc"
