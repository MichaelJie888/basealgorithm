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
        c++;
        return;
    }

    for (int j = 1; j <=n; j++) {

        if(hashTable[j]==false){
            bool flag=true;
            for (int pre = 1; pre < index; pre++) {
                if(abs(index-pre)==abs(j-P[pre])){
                    flag= false;
                    break;
                }
            }
            if(flag){
                P[index]=j;
                hashTable[j]= true;
                generateP(index+1);
                hashTable[j]= false;
            }
            
        }
    }
}
int main() {
    n=8;
    generateP(1);
    cout<<c;
    return 0;
}