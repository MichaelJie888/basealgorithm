#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int maxn=4;
int n,k,s,maxsq=-1;
int A[3]={1,4,7};
vector<int> temp,ans;
//如果不限制，也就是说在进入另外一个数的时候，需要另外修改边界
void DFS(int num,int nowk,int sum,int sumsq){
    if(nowk==k && sum==s){
        if(sumsq>maxsq){
            maxsq=sumsq;
            ans=temp;
        }
        cout<<maxsq<<endl;
        return;
    }
    if(num==n || nowk>k ||sum>s) return;
    temp.push_back(A[num]);
    DFS(num,nowk+1,sum+A[num],sumsq+A[num]*A[num]);

    temp.pop_back();
    DFS(num+1,nowk,sum,sumsq);
}
int main() {

    n=3;
    k=5;
    s=17;
    DFS(0,0,0,0);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}