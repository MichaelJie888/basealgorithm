#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn=50;
struct node{
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn],in[maxn],post[maxn];//前序，中序，后序
int n;//数组的长度

node* create(int prel,int prer,int inl,int inr){
    if(prel>prer){
        return NULL;
    }
//    如果左大于右，则返回空
//新建一个节点
    node* root=new node;
//    对节点赋值
    root->data=pre[prel];
//找到和当前节点在中序中的位置，
    int k;
    for ( k = inl; k < inr; k++) {
        if (in[k]==pre[prel]){
            break;
        }
    }
    //在中序数组中找到和后序中一样的那个数，k记录索引
    int numLeft=k-inl;//找到左子树的个数，就是在左子树中的排列
//    递归创建节点
    root->lchild=create(prel+1,prel+numLeft,inl,k-1);
    root->rchild=create(prel+numLeft+1,prer,k+1,inr);
//返回节点
    return root;
}

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now=q.front();
        q.pop();
        cout<<now->data<<" ";
        if(now->lchild!=NULL) q.push(now->lchild);
        if(now->rchild!=NULL) q.push(now->rchild);
    }
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&pre[i]);

    }
    for (int j = 0; j <n ; j++) {
        scanf("%d",&in[j]);
    }

    node* root=create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}