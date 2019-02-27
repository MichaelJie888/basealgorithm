#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000;
const int INF=10000000;

int n,m,s,G[maxn][maxn];//n为顶点数，maxn为最大顶点数
int d[maxn];//起点到达各点的最短路径长度
bool vis[maxn]={false};//标记数组，vis[i]==true表示已访问，

//邻接矩阵版

void Dijkstra(int s){//s为起点
    fill(d,d+maxn,INF);
    d[s]=0;//起点s到达自身的距离都是0
    for (int i = 0; i < n; ++i) {
        int u=-1,min=INF;//u使d[u]最小，min存放最小的d[u]
        for (int j = 0; j <n ; ++j) {//找到未访问的顶点中的d[]最小的
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }
//        找不到小于INF的d[u],说明剩下的顶点和起点s不连通
        if(u==-1) return;
        vis[u]= true;//标记u为已访问
        for (int k = 0; k <n ; ++k) {
            //如果v未访问&&u能到达v&&以u为中介可以使d[k]更优
            if(vis[k]==false&&G[u][k]!=INF&&d[u]+G[u][k]<d[k]){
                d[k]=d[u]+G[u][k];
            }
        }
    }
}

int main(){
    int u,v,w;
    cin>>n>>m>>s;
    fill(G[0],G[0]+maxn*maxn,INF);
    for (int i = 0; i <m ; ++i) {
        cin>>u>>v>>w;
        G[u][v]=w;
    }
    Dijkstra(s);
    for (int j = 0; j < n; ++j) {
        cout<<d[j]<<" ";
    }
    return 0;
}