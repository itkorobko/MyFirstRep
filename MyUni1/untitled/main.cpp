#include <iostream>
#include"calculator.h"
using namespace std;

int main()
{
    double a=4.8;
    double b=2.4;
    Calculator calc;
    cout<<calc.sum(a,b)<<endl;
    cout<<calc.sub(a,b)<<endl;
    cout<<calc.mul(a,b)<<endl;
    cout<<calc.div(a,b)<<endl;
    return 0;
}
