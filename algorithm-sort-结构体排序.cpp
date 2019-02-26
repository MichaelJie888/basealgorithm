#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
struct node{
    int x,y;
    
}p[10];
bool cmp(node a,node b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y<b.y;
}
int main(){
    
    return 0;
}