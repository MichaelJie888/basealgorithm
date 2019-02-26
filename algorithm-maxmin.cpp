#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
int main(){
    int a=100,b=90;
    cout<<"a和b中最大的数是："<<max(a,b)<<endl;
    cout<<"a和b中最小的数是："<<min(a,b)<<endl;

    cout<<min(1.2,4.2)<<endl;


    return 0;
}
//min,max可以对比浮点数和整数，但是不能对比三个数，只能对比两个数