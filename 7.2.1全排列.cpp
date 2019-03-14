#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int A[100]={0};
void print_permutation(int n,int *A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }else for (int j = 0; j <n ; ++j) {
        int ok=1;
        for (int i = 0; i <cur ; ++i)
            if(A[i]==j) ok=0;
        if(ok){
            A[cur]=j;
            print_permutation(n,A,cur+1);
        }

    }
}

int main(){
    int n,p[10];
    scanf("%d",&n);
    print_permutation(n,A,0);

    return 0;
}