#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

struct node{
    int data;
    int next;
}p[100000];

int main(){
    int a,n,k;
    scanf("%d%d%d",&a,&n,&k);
    int address,data,next;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d",&address,&data,&next);
        p[address].data=data;
        p[address].next=next;
    }

    
    return 0;
}

