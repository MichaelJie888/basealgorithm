#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
const int maxn=20;
int A[maxn][maxn]={0};
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int in[maxn],pos[maxn];
node* create(int inl,int inr,int posl,int posr){
    if(posl<posr){
        return NULL;
    }

    node* root=new node;
    root->data=pos[posr];
    int i;
    for (i = inl; i <=inr ; ++i) {
        if(in[i]==pos[posr]){
            break;
        }
    }

    int numleft=i-inl;
    root->lchild=create(inl,inl+numleft-1,posl,posl+numleft-1);
    root->rchild=create(numleft,inr,posl+numleft,posr-1);

}
bool isSymmetrial(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data!=root2->data){
        return false;//也不是，如果这样算的话，就无法做到让他们两边的产生对比，也就是分开
    }

    return isSymmetrial(root1->rchild,root2->lchild) && isSymmetrial(root1->lchild,root2->rchild);

}

bool isSymmetrialTree(node* root){
    return isSymmetrial(root,root);
}

//二叉树镜像
void MirrorTree(node *root){
    if(root==NULL){
        return;
    }
    if(root->lchild==NULL && root->rchild==NULL){
        return;
    }

    node* temp=root->lchild;
    root->lchild=root->rchild;
    root->rchild=temp;

    if(root->lchild){
        MirrorTree(root->lchild);
    }

    if(root->rchild){
        MirrorTree(root->rchild);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&A[i][j]);
        }
    }

    printMatrix(n,n);
    return 0;

}