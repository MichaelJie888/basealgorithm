#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct node{
    int ID;
    char num[10];
    int score;
}p[1000];
bool cmp3(node a,node b){
    if(a.score!=b.score){
        return a.score<b.score;
    }else{
        return a.ID<b.ID;
    }

}
bool cmp2(node a,node b){
    if(strcmp(a.num,b.num)!=0) return strcmp(a.num,b.num)<0;
    else return a.ID<b.ID;
}
bool cmp1(node a,node b){
    return a.ID<b.ID;
}
int main(){
    int n,c;
    scanf("%d%d",&n,&c);

    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d",&p[i].ID,&p[i].num,&p[i].score);
    }
    if(c==1){
        sort(p,p+n,cmp1);
    }else if(c==2){
        sort(p,p+n,cmp2);
    }else{
        sort(p,p+n,cmp3);
    }
    for (int j = 0; j <n ; ++j) {
        printf("%06d %s %d\n",p[j].ID,p[j].num,p[j].score);
    }
    return 0;
}