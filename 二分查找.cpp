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
int binarysearch(int A[],int left,int right,int n){
//    二分查找
    int mid;
    while (left<right){
        mid=(left+right)/2;
        if(A[mid]==n) return mid;
        else if(A[mid]>n) {
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<binarysearch(A,0,9,8);
//    for (int i = 0; i < 10; ++i) {
//        cout<<A[i]<<endl;
//    }
    return 0;
}
