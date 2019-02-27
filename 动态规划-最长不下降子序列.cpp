#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;
/*
状态转移方程f[i] = max{f[j]} +1 (1 <= j < i);
f[i] 代表以 a[i] 结尾的最长不下降子序列
最后只需要遍历一遍f[0~n-1]最大的是谁就好
*/

int f[20];
int n;
void LIS_dp(int *a)
{
    for(int i = 0; i < n; i++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i] >= a[j] && f[j]+1 > f[i])
                f[i] = f[j] + 1;
        }
    }
}
int main()
{
    int a[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    LIS_dp(a);
    int t = 0;
    for(int i = 0; i < n; i++)
        if(f[i] > t)
            t = f[i];
    printf("%d", t);
    return 0;
}
/*
10
3 18 7 14 10 12 23 41 16 24
*/