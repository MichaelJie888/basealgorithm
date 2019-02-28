#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn=1000;
const int INF=100000000;

int n,m,st,ed,G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];

bool vis[maxn]={false};


void dijkstra(int s){
    fill(d,d+maxn,INF);
    memset(w,0, sizeof(w));
    memset(num,0, sizeof(num));
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for (int i = 0; i < n; i++) {
        int u=-1,M=INF;
        for (int j = 0; j < n; j++) {
            if(vis[j]== false && d[j]<M){
                u=j;
                M=d[j];
            }
        }

        if(u==-1) return;
        vis[u]=true;
        for (int k = 0; k < n; k++) {
            if(vis[k]== false && G[u][k]!=INF){
                if(d[u]+G[u][k]<d[k]){
                    d[k]=d[u]+G[u][k];
                    w[k]=w[u]+weight[k];
                    num[k]=num[u];//最开始每个点都可以看作是终点，最开始对起始点赋值是1，然后能够到的每个点都可以赋值为1，
                }else if(d[u]+G[u][k]==d[k]){
                    if(w[u]+weight[k]>w[k]){
                        w[k]=w[u]+weight[k];
                    }
                    num[k]+=num[u];//如果遇到两个路径相同的，那么就可以把u的数目加到k上，
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for (int i = 0; i < n; i++) {
        scanf("%d",&weight[i]);
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    int x,y;
    for (int j = 0; j < m; j++) {

        scanf("%d%d",&x,&y);
        scanf("%d",&G[x][y]);
        G[y][x]=G[x][y];
    }
    dijkstra(st);

    cout<<num[ed]<<" "<<w[ed];


    return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
 */