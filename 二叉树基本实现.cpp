#include <iostream>
#include <queue>
using namespace std;
struct  node{
    int data;
    node* lchild;
    node* rchild;
    int lay;
};

node* root=NULl;

node* newNode(int v){
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}

void search(node* root,int x,int newdata){
    if(root==NULL){
        return;
    }
    if(root->data=x){
        root->data=newdata;
    }
    search(root->rchild,x,newdata);
    search(root->lchild,x,newdata);
}

void insert(node* &root,int x){
    if(root=NULL){
        root=newNode(x);
        return;
    }

    if(由二叉树的性质，x应该插在左子树){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);


}

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->lchild);
    cout<<root->data;
    inorder(root->rchild);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data;
}
//其实层次遍历的代码还是挺简单的
void layerorder(node* root){
    queue<node*> q;  //注意队列里存放地址
    q.push(root); //将根节点地址入队
    while(!q.empty()){
        node* now=q.front();
        q.pop();
        cout<<now->data;
        if(now->lchild!=NULL){
            now->lchild->lay=now->lay+1;
            q.push(now->lchild);
        }
        if(now->rchild!=NULL) q.push(now->rchild);
    }
}

//如果需要计算层数
struct nodel{
    int da;
    int layer;
    nodel* lchild;
    nodel* rchild;
};

void layercount(nodel* root){
    queue<nodel*> s;
    root->layer=1;
    s.push(root);
    
    while(!s.empty()){
        nodel* n=s.front();
        s.pop();
        if (n->rchild!=NULL){
            n->rchild->layer=n->layer+1;
        }
        if(n->lchild!=NULL){
            n->lchild->layer=n->layer+1;
        }
    }
}