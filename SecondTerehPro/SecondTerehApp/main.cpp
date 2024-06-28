#include <iostream>
#include"myclass.h"
using namespace std;

int main()
{
    MyClass mc;
    int a=7;
    if(mc.prime_num(a))
        cout<<a<<" is PRIME NUMBER!!!\n";
    else cout<<"Oh no, "<<a<<" is not prime number :((\n";
    return 0;
}
