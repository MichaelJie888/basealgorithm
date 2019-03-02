#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;
long long d[maxn];

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int gcd1(int a,int b){
    return !b ? a:gcd(b,a%b);
}

//最大公约数都能够找到了，最小公倍数也能够找到，
//r=a-b*k
//r=a%b
//假设d是a和b的公约数，那么d也是r的公约数，
//所以g(a,b)和g(b,a%d)可以相等


int main(){

    return 0;

}
