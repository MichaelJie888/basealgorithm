#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=30;
int n,V,maxValue=0;
int w[maxn],c[maxn];
//递归能够很好的实现深度优先搜索，
//使用递归的时候，系统回到调用一个系统栈来存放递归中的每一层的状态，使用
//递归来实现dfs的本质还是栈
/*
 * 给定n件商品，每件商品都有体积和价值，现在想要
 * 在包里装下最大价值的物品，那么如何装？
 * 遍历
 * 实际上，全排列也是一种遍历，
 * 边界条件就是遍历到最后一件商品的时候，就是开始结算的时候，
 * 递归式子并不仅仅有一个，对于这种分叉递归的，有两个
 * 甚至有的可能有多个
 * */
void DFS(int index,int sumW,int sumC){
    if(index==n){
        if(sumW<=V && sumC>maxValue){
            maxValue=sumC;
        }
        return;
    }

    DFS(index+1,sumW,sumC);
    DFS(index+1,sumW+w[index],sumC+c[index]);
}
int main() {
    scanf("%d%d",&n,&V);
    for (int i = 0; i < n; i++) {
        scanf("%d",&w[i]);
    }
    for (int j = 0; j < n; j++) {
        scanf("%d",&c[j]);
    }
    DFS(0,0,0);
    cout<<maxValue;
    return 0;
}