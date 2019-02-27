#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF=100000000;
const int maxn=200;

int n,m;
int dis[maxn][maxn];

void Floyd(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }

    }
}

int main(){
    int u,v,w;
    fill(dis[0],dis[0]+maxn*maxn,INF);
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        dis[i][i]=0;
    }
    for (int j = 0; j <m ; ++j) {
        cin>>u>>v>>w;
        dis[u][v]=w;
    }
    Floyd();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <n ; ++i) {
            printf("%d ",dis[k][i]);
        }
        printf("\n");
    }
    return 0;
}