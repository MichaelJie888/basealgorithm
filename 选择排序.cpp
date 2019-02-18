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
void selectsort(int A[],int n){
    for (int i = 0; i <n; ++i) {
//        外循环，需要循环n次，
        int k=i;
        for (int j = i; j <n; ++j) {
            if(A[j]<A[k]){
                k=j;
            }
//            内循环，每一次找到比此范围内最小的元素索引
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
//        然后在此处进行交换，进行下一轮的循环，这个函数没有返回值
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A[10]={1,8,0,29,100,988,43,10,77,239};
    selectsort(A,10);
    for (int i = 0; i < 10; ++i) {
        cout<<A[i]<<endl;
    }
    return 0;
}