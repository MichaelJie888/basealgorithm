#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;

struct bign{//存储大数，
    int d[1000];
    int len;
    bign(){
        memset(d,0, sizeof(d));
        len=0;
    }
};

bign change(char str[]){//把字符串转变为数组上的数字
    bign a;
    a.len=strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i]=str[a.len-i-1]-'0';//为什么大数要这样存储，从底部开始存储，整数的高位存储在数组的高位
    }

    return a;
}

bign divide(bign a,int b,int &r){
    bign c;
    c.len=a.len;//被除数的每一位和商的每一位是一一对应的
    for (int i = a.len-1; i >=0; i--) {//从高位开始计算
        r=r*10+a.d[i];
        if(r<b) c.d[i]=0;
        else {
            c.d[i]=r/b;
            r=r%b;
        }
    }
    while(c.len-1>=1 && c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}

void print(bign a){
    for (int i = a.len-1; i >=0; i--) {
        printf("%d",a.d[i]);
    }
}


int main(){
    char str1[1010];
    int b,r=0;
    scanf("%s%d",str1,&b);
    bign a=change(str1);
    print(divide(a,b,r));
    printf("  %d",r);

    return 0;

}