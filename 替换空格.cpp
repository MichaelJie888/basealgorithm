#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=2000;
int ug[maxn],c[maxn];

void replaceSpace(char *str,int length) {
    if(str==NULL || length<=0){
        return ;
    }
    int count=0,i=0;
    int orilen=0;//这个得到的长度已经是真实的长度了， 
    while(str[i]!='\0'){
        orilen++;
        if(str[i]==' '){
            count++;
        }
        i++;
    }
    int le=orilen+2*count;//真实的长度
    int j=orilen;
    while(j>=0 && le>=j) {//如果不加这个符号，不能对头部的字符进行替换
        if(str[j]!=' '){
            str[le--]=str[j];
        }else{
            str[le--]='0';
            str[le--]='2';
            str[le--]='%';
        }
        j--;
    }

}

int main(){
    char s[20]={' ' ,'h','u',' ','c','n',' ','i'};
    for (int i = 0; i <20 ; ++i) {
        printf("第%d个字符： %c\n",i,s[i]);

    }
    return 0;

}