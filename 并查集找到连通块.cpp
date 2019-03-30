/*
 * 并查集，找到有多少个群落，实际上，这个如果用图表示的话，还是比较复杂的，
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
    int n,l,h;
    scanf("%d",&n);
    init(n);
    for (int j = 1; j <=n; ++j) {
        scanf("%d:",&l);
//        这个地方是可以不一次性输入完成的，可以分开进行输入
        for (int i = 0; i <l ; ++i) {
//            l只是记录有多少爱好
            scanf("%d",&h);
            if(course[h]==0){
                course[h]=j;
            }
            Union(j,findFather(course[h]));
//            要合并的只是当前这个人与当前爱好根父亲这两个人，所以j是需要放在最上边的，实际上这个，更明确的边并没有给出来，也就无法作出这张图，没有这张图，就更加无法找到图中有几个
//          连通块了
        }
    }

    for (int k = 1; k <=n ; ++k) {
        cout<<findFather(k)<<endl;
    }
    int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if(isroot[i]>0) cout<<isroot[i];
    }

    printf("%d",ans);

    return 0;
}