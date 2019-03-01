#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1000;
long long d[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",&d[i]);
    }

    sort(d,d+n);

    printf("%lld",d[n-2]*d[n-3]>d[0]*d[1]? d[n-1]*d[n-2]*d[n-3]:d[n-1]*d[0]*d[1]);

    return 0;

}
/*
事实证明，这个题还是比较复杂的，首先，数组中包含正数，负数，0，负数乘以负数，也是正数，但是相对来说还算简单，还要求，时间复杂度为
O(n),我实在不知道这个O(n)的时间复杂度是如何做到的，

全过了
*/