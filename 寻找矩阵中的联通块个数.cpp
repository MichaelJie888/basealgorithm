#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn=100;

char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int r,int c,int id){
    if(r<0 || r>=m ||c<0 ||c>=n) return;
    if(idx[r][c] >0 || pic[r][c]!='@') return;
    idx[r][c]=id;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <=1 ; ++j) {
            if(i!=0 ||j!=0) dfs(r+i,c+j,id);
        }
    }
}

int main(){
    while (scanf("%d%d",&m,&n)==2 && m && n){
        for (int i = 0; i < m; ++i) {
            scanf("%s",pic[i]);
        }
        memset(idx,0, sizeof(idx));
        int cnt=0;
        for (int j = 0; j <m ; ++j) {
            for (int i = 0; i <n ; ++i) {
                if (idx[i][j]==0 && pic[i][j]=='@') dfs(i,j,++cnt);
                printf("%d",cnt);
            }
        }
    }
    return 0;
}