#include <QtTest>
#include "../ThirdTerehApp/myclass.h"
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
    QCOMPARE(mc.sum_of_numbers(0),0);
    QCOMPARE(mc.sum_of_numbers(4),4);
    QCOMPARE(mc.sum_of_numbers(-4),4);
    QCOMPARE(mc.sum_of_numbers(145),10);
}

QTEST_APPLESS_MAIN(MyTest)

#include "tst_mytest.moc"
