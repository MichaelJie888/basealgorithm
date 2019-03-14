#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int n=6;
int A[100]={0};


int main(){
    int n,p[10];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&p[i]);
    }
    sort(p,p+n);
    do{
        for (int i = 0; i <n ; ++i)
            printf("%d ",p[i]);
        printf("\n");

    }while(next_permutation(p,p+n));
    
    return 0;
}