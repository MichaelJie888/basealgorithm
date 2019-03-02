#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;
long long d[maxn];
struct Fraction{
    int up,down;
};
int gcd1(int a,int b){
    return !b ? a:gcd(b,a%b);
}
// 分数的加减乘除用到了最大公约数，最小公倍数，
//分数的化简
Fraction reduction(Fraction result){
    if(result.down<0){
        result.up=-result.up;
        result.down=-result.down;
    }

    if(result.up==0){
        result.down=1;
    }else{
        int d=gcd1(abs(result.down),abs(result.up));
        result.up/=d;
        result.down/=d;
    }
}

//分数的加法

Fraction add(Fraction a,Fraction b){
    Fraction result;
    result.up=a.up*b.down+b.up*a.down;
    result.down=a.down*b.down;
    return reduction(result);
}

Fraction sub(Fraction a,Fraction b){
    Fraction result;
    result.up=a.up*b.down-b.up*a.down;
    
    result.down=a.down*b.down;
    return reduction(result);
}

Fraction multi(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.down;
    result.up=a.up*b.up;
    return reduction(result);
}

Fraction divide(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.up;
    result.up=a.up*b.down;
    return reduction(result);
}





int main(){

    return 0;

}
