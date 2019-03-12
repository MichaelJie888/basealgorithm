#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int maxn=60;
int h[200000]={0};
int main(){
    int n,d;
    vector<int> S[20000];
    int maxv=0;
    scanf("%d%d",&n,&d);
    for (int i = 0; i <n ; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        S[b].push_back(a);
        h[i]=b;
    }
    sort(h,h+n);
    int m=n-1;
    while(m>0){
        if(h[m]+h[m-1]>maxv && abs(S[h[m]][0]-S[h[m-1]][0])>=d){
            maxv=h[m]+h[m-1];
        }
        m--;
    }

    printf("%d",maxv);
    return 0;


}

