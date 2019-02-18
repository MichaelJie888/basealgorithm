#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int Partition(int A[],int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right && A[right]>temp) right--;
        A[left]=A[right];
        while(left<right && A[left]<temp) left++;
        A[right]=A[left];
    }

    A[left]=temp;
    return left;
}

void quicksort(int A[],int left,int right){
    if(left<right){
        int pos=Partition(A,left,right);
        quicksort(A,left,pos-1);
        quicksort(A,pos+1,right);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A[10]={100,200,39,1,34,10000,33,98,23,38};
    /* 数组定义我都忘记了，三门语言也并不是那么容易就能够掌握的*/
    quicksort(A,0,9);
    for (int i = 0; i < 10; ++i) {
        cout<<A[i]<<endl;
    }
    return 0;
}