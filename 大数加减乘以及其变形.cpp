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
}p[1000];

bign change(char str[]){//把字符串转变为数组上的数字
    bign a;
    a.len=strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i]=str[a.len-i-1]-'0';//为什么大数要这样存储，从底部开始存储，整数的高位存储在数组的高位
    }

    return a;
}
bign add(bign a,bign b){
    bign c;
    int carry=0;
    for (int i = 0; i < a.len || i<b.len; i++) {
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0){
        c.d[c.len++]=carry;
    }

    return c;
}

bign sub(bign a,bign b){
    bign c;
    for (int i = 0; i < a.len || i<b.len; i++) {
        if(a.d[i]<b.d[i]){
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.len++]=a.d[i]-b.d[i];

    }

    while(c.len-1>=1 && c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}

bign multi(bign a,int b,int p){
    bign c;
    int carry=0;
    c.len=p;
    for (int i = 0; i <a.len ; i++) {
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;

    }
    while(carry!=0){
        c.d[c.len++]=carry%10;
        carry/=10;
    }

    return c;
}



void print(bign a){
    for (int i = a.len-1; i >=0; i--) {
        printf("%d",a.d[i]);
    }
}


int main(){
    char str1[1010],str2[1010];
    scanf("%s%s",str1,str2);
    bign a=change(str1);
    bign b=change(str2);
    for (int i = 0; i < b.len; ++i) {
        p[i]=multi(a,b.d[i],i);
    }
    for (int j = 1; j < b.len; ++j) {
        p[0]=add(p[0],p[j]);
    }
    print(p[0]);
    return 0;

}