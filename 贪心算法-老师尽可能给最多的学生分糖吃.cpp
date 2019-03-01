#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;
// 输入两组数据，一个是每个学生需要多大的糖，一个有多少糖，每块糖多重



int main(){
    int np,nc,p[1000],c[1000];
    scanf("%d",&np);
    for (int i = 0; i < np; i++) {
        scanf("%d",&p[i]);
    }
    scanf("%d",&nc);
    for (int j = 0; j <nc ; j++) {
        scanf("%d",&c[j]);
    }

    sort(p,p+np);
    sort(c,c+nc);

    int cc=0,pp=0,count=0;
    while(pp<np && cc<nc){
        if(p[pp]<=c[cc]){
            count++;
            pp++;
            cc++;
        }else{
            cc++;
        }
    }

    printf("%d",count);


    return 0;

}