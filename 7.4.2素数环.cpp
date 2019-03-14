#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef int State[9];
const int maxstate=1000000;//状态数组

//int dist[maxstate];  //距离数组
//
//const int dx[]={-1,-1,0,0};
//const int dy[]={0,0,-1,-1};
int A[1000]={0};
int n;
int pri[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1};
int vis[100]={0};
bool isp(int num){
    if(pri[num]){
        return true;
    }else{
        return false;
    }
}
void dfs(int cur){
    if(cur==n && isp(A[0]+A[n-1])){
        for (int i = 0; i < n; ++i) printf("%d ",A[i]);
        printf("\n");
    }else
        for (int j = 2; j <=n ; ++j) {
            if(!vis[j] && isp(j+A[cur-1])){
                A[cur]=j;
                vis[j]=1;
                dfs(cur+1);
                vis[j]=0;
            }
        }

}

int main(){
    A[0]=1;
    scanf("%d",&n);
    dfs(1);
    return 0;
}