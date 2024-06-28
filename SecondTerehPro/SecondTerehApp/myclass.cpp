#include "myclass.h"

MyClass::MyClass() {}
bool MyClass::prime_num(int a)
{
    if(a<2)
        return false;
    else
    {
        for(int i=2;i<a;i++)
        {
            if(a%i==0)
                return false;
        }
        return true;
    }
}
