/*
 * 并查集寻找好朋友
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
        isroot[i]=0;
    }
}
int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    init(n);
    for (int j = 1; j <=m; ++j) {
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for (int k = 1; k <=n ; ++k) {
        isroot[findFather(k)]++;
    }
    int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if(isroot[i]>0) ans++;
    }

    printf("%d",ans);

    return 0;
}