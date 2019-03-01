#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};

bool vis(){
    if(G[i][j]==0 || i<0 ||i>n||y<0 ||y>m) return false;
    if()
}

int dfs(){

}
/*
 * 
 * 5 5
02111
01a0A
01003
01001
01111
 **/
int main(){
    int n,m,st,ed;
    int G[maxn][maxn];
    scanf("%d%d",&n,&m);
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&G[i][j]);
            if(G[i][j]==2){
                st=i;
                ed=j;
            }
        }
    }
    
    return 0;

}