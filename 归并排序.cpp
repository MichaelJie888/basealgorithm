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
// 只有自己写全部代码，才能够对代码非常理解，这个过程是如何操作的
// 辅助空间为n，然后这个辅助空间写在merge中还是最为简洁的，有的代码是写在main函数中，这个需要在另外两个函数中添加temp的参数，并不好用
// 实际上归并排序是在two point基础之上衍生而来的，因为其核心代码就是对两段数组进行合并，而合并过程用到了扫描指针
// 
void merge(int A[],int L1,int R1,int L2,int R2){
    int i=L1,j=L2;
    int temp[10],index=0;
    while(i<=R1 && j<=R2){
        if(A[i]<=A[j]){
            temp[index++]=A[i++];
        }else{
            temp[index++]=A[j++];
        }
    }
    while(i<=R1) temp[index++]=A[i++];
    while(j<=R2) temp[index++]=A[j++];
    for (int k = 0; k < index; k++) {
        A[L1+k]=temp[k];
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
    int B[]={10,1,3,4,5,6,7,8,9,2};
    mergeSort(B,0,9);
    for (int i = 0; i < 10; ++i) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    return 0;
