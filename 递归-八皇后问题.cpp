#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=11;
int n,P[maxn],hashTable[maxn]={false};
int c=0;
//使用的是递归思想
void generateP(int index){
    if(index==n+1){
        bool flag= true;
        for (int i = 1; i <=n; i++) {
            for (int j = i+1; j <=n ; j++) {
                if(abs(i-j)==abs(P[i]-P[j])){
                    flag= false;
                }
            }
        }
        if(flag) c++;
        return;
    }
    for (int j = 1; j <=n; j++) {
        if(hashTable[j]==false){
            P[index]=j;
            hashTable[j]= true;
            generateP(index+1);
            hashTable[j]= false;
        }
    }
}
int main() {
    n=8;
    generateP(1);
    cout<<c;
    return 0;
}