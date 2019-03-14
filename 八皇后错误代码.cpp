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
bool vis[100]={false};
bool isp(int num){
    if(pri[num]){
        return true;
    }else{
        return false;
    }
}
bool flag;
void dfs(int cur){
    if(cur==n){
        for (int i = 0; i < n; ++i) printf("%d ",A[i]);//存储是从0到n-1存储
        printf("\n");
        return;
    }else
        for (int j = 0; j <n ; ++j) {//但是值的遍历是从1到n开始遍历
            if(vis[j]== false){
                flag=true;
                for (int i = 0; i < cur; ++i) {
                    if(abs(cur-i)==abs(j-A[i])){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) {
                A[cur]=j;
                vis[j]= true;
                dfs(cur+1);
                vis[j]= false;
            }

        }

}

int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}