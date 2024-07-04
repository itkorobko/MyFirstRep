#include "myclass.h"

MyClass::MyClass() {}
int MyClass::sum_of_numbers(int a){   int res=0;
    if(a<0)
        a*=-1;
    while(a>0){
        res+=a%10;
        a/=10;
    }
    return res;
}
