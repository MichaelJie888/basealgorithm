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
//    如果不加修改就直接进行递归，这个程序的时间复杂度就是2的n次方，如果n足够大，那么这将是非常复杂的，那么有没有什么办法降低时间复杂度了
//办法就是对第二条支路进行条件选择，选择的条件就是，只有加入这件商品后，如果体积没有超过书包体积，那么继续
//如果加入这个商品会增加价值，就更新最大价值
    if(sumW+w[index]<=V){
        if(sumC+c[index]>maxValue){
            maxValue=sumC+c[index];
        }
        DFS(index+1,sumW+w[index],sumC+c[index]);
    }

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