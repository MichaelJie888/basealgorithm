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

int father[maxn];
int isroot[maxn];
int course[maxn]={0};
bool vis[maxn];

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
int main(){
    int n,m,k;
    vector<int> G[maxn];//领接表

    scanf("%d%d%d",&n,&m,&k);
    for (int j = 0; j<m; ++j) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int nowpoint;
    for (int query = 0; query <k ; ++query) {
        scanf("%d",&nowpoint);
        init(n);
        for (int i = 1; i <=n ; ++i) {
            for (int j = 0; j <G[i].size() ; ++j) {
                int u=i,v=G[i][j];
                if(u==nowpoint || v==nowpoint) continue;
                Union(u,v);
            }
        }
        int block=0;
        for (int l = 1; l <=n; ++l) {
            if(l==nowpoint) continue;
            int fa_l=findFather(l);
            if(vis[fa_l]== false){
                block++;
                vis[fa_l]=true;
            }
        }

        printf("%d\n",block-1);
    }



    return 0;
}