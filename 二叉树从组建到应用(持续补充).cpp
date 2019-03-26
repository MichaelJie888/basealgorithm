#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
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
//分层打印
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
//分层打印二叉树
void PrintLayer(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> s;
    s.push(root);
    int toBePrint=1;
    int nextlevel=0;
    while(!s.empty()){
        node* now=s.front();

        printf("%d",now->data);

        if(now->rchild){
            nextlevel++;
            // 统计下一组数目
            s.push(now->rchild);
        }
        if(now->lchild){
            nextlevel++;
            s.push(now->lchild);
        }

        s.pop();
        --toBePrint;
        // 每统计一个就减少一个需要被打印的数目，然后
        if(toBePrint==0){
            printf("\n");
            toBePrint=nextlevel;
            nextlevel=0;
        }

    }
}
//之字形打印二叉树
void PrintZword(node* root){
    if(root==NULL){
        return;
    }
    stack<node*> l[2];
// 定义两个栈
    int current=0;
    int next=1;
//    一个是目前需要打印的栈索引，一个是下一个栈的索引，也就是0和1
    l[current].push(root);
//    目前这个栈的索引所需要把root放到
    while(!l[current].empty() || !l[next].empty()){
        node* now=l[current].top();
        l[current].pop();

        printf("%d",now->data);

        if(current==0){
            if(now->lchild!=NULL){
                l[next].push(now->lchild);

            }
            if(now->rchild!=NULL){
                l[next].push(now->rchild);
            }

        } else{
            if(now->lchild!=NULL){
                l[next].push(now->lchild);

            }
            if(now->rchild!=NULL){
                l[next].push(now->rchild);
            }
        }

        if(l[current].empty()){
            printf("\n");
            current=1-current;
            next=1-next;
        }
    }

}
//寻找路径和为某个特定值的序列
void FindPath(node* root,int sum,vector<int> p,int currentsum){
    currentsum+=root->data;
    p.push_back(root->data);
    bool isleaf=root->lchild==NULL && root->rchild==NULL;
    if(currentsum==sum && isleaf){
        printf("a path is found");
        vector<int>::iterator st=p.begin();
        for (; st!=p.end() ; st++) {
            printf("%d ",*st);
        }
        printf("\n");
    }
//    还是一种递归的思想，也就是分别进行测试的想法，有的递归一个函数就可以解决了，但是有的需要两个才能够解决
    if(root->lchild!=NULL){
        FindPath(root->lchild,sum,p,currentsum);
    }
    if(root->rchild!=NULL)
        FindPath(root->rchild,sum,p,currentsum);
    p.pop_back();
}
void Findpath(node* root ,int sum){
    if(root=NULL){
        return;
    }
    vector<int> p;
    int currentsum=0;
    FindPath(root,sum,p,currentsum);
}
//寻找二叉树的深度
int Treedepth(node* root){
    if(root==NULL)
        return 0;
    int left=Treedepth(root->lchild);
    int right=Treedepth(root->rchild);

    return (left>right) ? left+1 :right+1;
}
//判断一个二叉树是不是平衡二叉树+调用了上面的那个找到二叉树的深度
bool isBanlanced(node* root){
    if(root==NULL)
        return true;
    int left=Treedepth(root->lchild);
    int right=Treedepth(root->rchild);

    int diff=left-right;
    if(diff>1 || diff<-1)
        return false;
    return isBanlanced(root->lchild) && isBanlanced(root->rchild);
}

//二叉树镜像
void mirror(node* root){
    if(root==NULL)
        return;
    if(root->rchild==NULL && root->lchild==NULL)
        return;

    node* temp=root->lchild;
    root->lchild=root->rchild;
    root->rchild=temp;

    if(root->lchild)
        mirror(root->lchild);
    if(root->rchild)
        mirror(root->rchild);
}

//对称二叉树
bool issymme(node* root1,node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;

    if(root1->data!=root2->data)
        return false

    return issymme(root1->lchild,root2->rchild) && issymme(root1->rchild,root2->lchild);
}
bool issys(node* root){
    return issymme(root,root);
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
    PrintLayer(root);
    PrintZword(root);
    Findpath(root,10);
    return 0;
}