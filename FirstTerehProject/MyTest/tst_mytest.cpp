#include <QtTest>

// add necessary includes here
#include"../FirstTerehApp/myclass.h"
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
    QCOMPARE(mc.NOD(3,8),1);
    QCOMPARE(mc.NOD(24,4),4);
    QCOMPARE(mc.NOD(12,16),4);

}

QTEST_APPLESS_MAIN(MyTest)
#include "tst_mytest.moc"
