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
    char name[10];
    char num[10];
    int score;
}p[1000];
bool cmp(node a,node b){
    return a.score<b.score;
}
int main(){
    int n;
    scanf("%d",&n);
    int score;
    int max=0,min=100;
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d",&p[i].name,&p[i].num,&p[i].score);
    }
    sort(p,p+n,cmp);


    cout<<p[n-1].name<<" "<<p[n-1].num<<endl;
    cout<<p[0].name<<" "<<p[0].num<<endl;
    return 0;
}