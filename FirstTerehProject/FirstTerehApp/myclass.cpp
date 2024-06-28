#include "myclass.h"
#include <iostream>
using namespace std;

MyClass::MyClass() {}
int MyClass::NOD(int a, int b)
{
    int res=1;
    if(a>b)
        swap(a,b);
    for(int i=1;i<=a;i++)
    {
        if(a%i==0 && b%i==0)
            res=i;
    }
    return res;
}
