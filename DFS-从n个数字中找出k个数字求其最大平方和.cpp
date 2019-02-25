#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int maxn=4;
int n,k,s,maxsq=-1;
int A[4]={2,3,3,4};
vector<int> temp,ans;
void DFS(int num,int nowk,int sum,int sumsq){
    if(nowk==k && sum==s){
        if(sumsq>maxsq){
            maxsq=sumsq;
            ans=temp;
        }
        return;
    }
    if(num==n || nowk>k ||sum>s) return;
    temp.push_back(A[num]);
    DFS(num+1,nowk+1,sum+A[num],sumsq+A[num]*A[num]);
    temp.pop_back();
    DFS(num+1,nowk,sum,sumsq);
}
int main() {

    n=4;
    k=2;
    s=6;
    DFS(0,0,0,0);

    cout<<maxsq<<endl;
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}