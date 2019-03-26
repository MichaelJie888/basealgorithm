/*
 * 位操作总结
 *
 * */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
//不用变量就可以交换两个数的值
void change(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}
//这个只能计算正数的
int count1num(int n){
    int res=0;
    while (n!=0){
        res+=n&1;
        n>>=1;
    }
    return res;
}
int main(){
    int a,b;

    cout<<count1num(78);

    return 0;
}