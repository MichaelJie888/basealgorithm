#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100000;
int main(){
    int n,m;
    int A[maxn];
    scanf("%d%d",&n,&m);

    for (int i = 1; i <=n; ++i) {
        scanf("%d",&A[i]);
    }
    sort(A,A+n+1);
    int j;
    int c=n-m;
    if(c==0){
        printf(0);
    }else{
        for (j = 1; j <=n ; ++j) {
            if(j==c){
                break;
            }
        }

        printf("%d",A[2*j]+A[1]);
    }

    return 0;

}