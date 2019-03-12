#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int h[10000000]={0};
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i = 0; i <n ; ++i) {
        scanf("%d",&h[i]);
    }
    for (int j = 0; j <d ; ++j) {
        int q;
        scanf("%d",&q);
        if(q==2){
            int res=1,temp=h[0];
            for (int i = 1; i <n ; ++i) {
                if(h[i]!=temp){
                    res++;
                    temp=h[i];
                }
            }
            printf("%d\n",res);
        }else if(q==1){
            int x,y;
            scanf("%d%d",&x,&y);
            for (int i = 0; i < n; ++i) {
                if(h[i]==x){
                    h[i]=y;
                }
            }
        }
    }
    return 0;


}