#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int A[100]={0};
void print_permutation(int n,int *P,int *A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }else for (int j = 0; j <n ; ++j) if(!j || P[j]!=P[j-1]){
        int c1=0,c2=0;
        for (int i = 0; i <cur ; ++i) if(A[i]==P[j]) c1++;
        for(int k=0;k<n;k++) if(P[k]==P[j]) c2++;
        if(c1<c2){
            A[cur]=P[j];
            print_permutation(n,P,A,cur+1);
        }

    }
}

int main(){
    int n,P[10];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&P[i]);
    }
    print_permutation(n,P,A,0);

    return 0;
}
