#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=11;
int n,P[maxn],hashTable[maxn]={false};
//使用的是递归思想
void generateP(int index){
    if(index==n+1){
        for (int i = 1; i <=n ; i++) {
            cout<<P[i];
        }
        cout<<endl;
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
    n=4;
    generateP(1);

    return 0;
}