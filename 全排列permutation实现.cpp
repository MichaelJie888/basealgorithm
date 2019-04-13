#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

int main(){

    int n;
    int num[n];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d",&temp);
        num[i]=temp;
    }
    do{
        for (int i = 0; i <n ; ++i) {
            printf("%d",num[i]);
        }
        printf("\n");
    }while(next_permutation(num,num+n));

    return 0;
}