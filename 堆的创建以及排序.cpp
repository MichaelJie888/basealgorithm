#include <cstdio>
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10;
int heap[maxn]={2,3,4,1,33,44,23,11,33,9};
int n=10;
void downjust(int low,int high){
    int i=low,j=i*2;
    while(j<=high){
        if(j+1<=high && heap[j+1]>heap[j]){
            j=j+1;
        }
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
}
void createHeap(){
    for (int i = n/2; i >=1; i--) {
        downjust(i,n);
    }
}
int main() {

    createHeap();
    for (int i = 0; i < 10; i++) {
        cout<<heap[i]<<" ";
    }
    return 0;
}