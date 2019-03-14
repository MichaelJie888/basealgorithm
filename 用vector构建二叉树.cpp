#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
};
TreeNode* create(vector<int> &pre,vector<int> &in,int prel,int prer,int inl,int inr){
    if(prel>prer){
        return NULL;
    }
    TreeNode* root=new TreeNode;

    root->val=pre[prel];
    int k;
    for ( k = inl; k < inr; k++) {
        if (in[k]==pre[prel]){
            break;
        }
    }

    int numLeft=k-inl;
    root->lchild=create(pre,in,prel+1,prel+numLeft,inl,k-1);
    root->rchild=create(pre,in,prel+numLeft+1,prer,k+1,inr);
    return root;
}

TreeNode* buildtree(vector<int> &pre,vector<int> &in){
    return create(pre,in,0,pre.size()-1,0,in.size()-1);
}
void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val;
    preorder(root->lchild);
    preorder(root->rchild);


}

int main(){

    vector<int> a;
    vector<int> b;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d",&c);
        a.push_back(c);
    }
    for (int j = 0; j < n; ++j) {
        int d;
        scanf("%d",&d);
        b.push_back(d);
    }
    TreeNode* root=buildtree(a,b);
    preorder(root);
    return 0;
}