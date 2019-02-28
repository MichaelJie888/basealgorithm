#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n,m;
    int d[200000],p[200000],ans[100000];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&d[i]);
    }
    scanf("%d",&m);
    for (int j = 0; j < n; ++j) {
        scanf("%d",&p[j]);
    }
    int c=floor((m+n-1)/2);
    int u=0,l=0;

    for (int k = 1; k <=c ; ++k) {
        if(d[u]<=p[l]){
            u++;
            ans[k]=d[u];

        }else{
            l++;
            ans[k]=p[l];
        }
    }
    cout<<ans[c];
    return 0;
}