/*
 * 并查集，如果一个图，丢掉每个点，需要多少条线才能够让图变成连通图
 * */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

const int maxn=100;
int nowpoint;
int father[maxn];
int isroot[maxn];
int course[maxn]={0};
bool vis[maxn];
bool visd[maxn]={false};
vector<int> G[maxn];//领接表

int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }

    while (a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }

    return x;
}

void Union(int a,int b){
    int a1=findFather(a);
    int a2=findFather(b);
    if(a1!=a2){
        father[a1]=a2;
    }
}

void init(int n){
    for (int i = 1; i <=n ; ++i) {
        father[i]=i;
        vis[i]= false;
    }
}
void DFS(int v){
//    if(v==nowpoint) return;
//    忽略nowpoint这个点，无法访问这个点，也无法通过这个点访问到其他的点，也就会隔断访问，增加块的数目。
    vis[v]=true;
    for (int i = 0; i <G[v].size() ; ++i) {
        if(vis[G[v][i]]== false){
            DFS(G[v][i]);
        }
    }
}
//检测过程可以写的这么简单，还要用并查集，简直不就是有病

void DDfs(int i,int dp,int& depth){
    visd[i]=true;
    if(depth<dp){
        depth=dp;
    }
    for (int j = 0; j <G[i].size() ; ++j) {
        if(visd[G[i][j]]==false){
            DDfs(G[i][j],dp+1,depth);
        }

    }
}

int main(){
    int n;

    scanf("%d",&n);
    for (int j = 0; j<n-1; ++j) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int maxdepth=1;

    for (int i = 1; i <=n ; ++i) {
        memset(visd, false, sizeof(visd));
        DDfs(i,1,maxdepth);
        printf("%d\n",maxdepth);
    }

    return 0;
}