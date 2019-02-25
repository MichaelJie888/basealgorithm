#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=100;
void merge(int A[],int L1,int R1,int L2,int R2){
    int i=L1,j=L2;
    int temp[maxn],index=0;
    while(i<=R1 && j<=R2){
        if(A[i]<=A[j]){
            temp[index++]=A[i++];
        }else{
            temp[index++]=A[j++];
        }
    }
    while(i<=R1) temp[index++]=A[i++];
    while(j<R2) temp[index++]=A[j++];
    for (int k = 0; k < index; k++) {
        A[L1+i]=temp[i];
    }


}

void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);

        merge(A,left,mid,mid+1,right);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    double a=2,b=3;
    cout<<(a+b)/2;

    return 0;
}