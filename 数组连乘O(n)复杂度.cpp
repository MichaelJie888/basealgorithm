#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=30;
int w[maxn],c[maxn];
int n,V,maxValue=0;
void mult(vector<int> &arr1,vector<int> &arr2){
    int len1=arr1.size();
    int len2=arr2.size();
//实际上这个地方定义用int存在风险，还是double比较好，如果数值太大，会溢出
    if(len1==len2 && len2>1){
        arr2[0]=1;
        for (int i = 1; i <=len1 ; ++i) {
            arr2[i]=arr2[i-1]*arr1[i-1];//也就是说arr2存储的是左半部分的成绩；第三个存储前两个，
//            第四个存储前四个
        }

        double temp=1;
        for (int j = len1-2; j >=0 ; --j) {
            temp*=arr1[j+1];//temp存储的是右边的，连乘，一直往左连乘
            arr2[j]*=temp;//arr2本来存储的是从左往右的连乘，现在从右往左算，因arr2[j]本身，就是
//            存储的是j左边的连乘结果，现在从右往左乘，就给乘出来连，而且temp这个相当简洁
        }
    }
}

int main(){
    scanf("%d",&n);
    vector<int> s,q;
    int a=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a);
        s.push_back(a);
        q.push_back(a);
    }

    mult(s,q);
    for (int j = 0; j < n; ++j) {
        cout<<q[j]<<" ";
    }
    return 0;

}