#include <cstdio>
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10010;
int A[maxn],dp[maxn];


int main() {

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    dp[0]=A[0];
    for (int j = 0; j <n ; ++j) {
        dp[j]=max(A[j],dp[j-1]+A[j]);
    }
    int k=0;
    for (int l = 1; l < n; l++) {
        if(dp[l]>dp[k]){
            k=l;
        }
    }

    cout<<dp[k]<<endl;
    return 0;
}