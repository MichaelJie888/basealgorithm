/*
 * 链表操作总结，
 * 链表的建立
 * 链表的归并以及删除查找还有逆转等
 * */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct node{
    int data;
    node* next;
};
//创建链表
node* create(vector<int> A){
    node *p,*pre,*head;
//    pre保存当前节点的前驱节点，head为头节点
    head = new node;
    head->next=NULL;
    pre=head;
    for (int i = 0; i < A.size(); ++i) {
        p=new node;
//        这个操作意义非凡，node* 只是声明这样类型的指针，而new node就是实例化是一个节点，然后赋值给这个指针，
        p->data=A[i];
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
    return head;
}
//计算链表中某个数值的数目
int search(node* head,int x){
    int count=0;
    node* p=head->next;
    while(p!=NULL){
        if(p->data!=x){
            count++;
        }

        count++;
    }
    return count;
}
//在链表中插入元素
void insert(node* head,int x,int pos){
    node* p=head;
    for (int i = 0; i <pos-1 ; ++i) {
        p=p->next;
    }
    node* q=new node;
    q->data=x;
    q->next=p->next;
    p->next=q;
}
//打印链表
void print(node* head){
    node* p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//反转链表
node* reverse(node* head){
    node* rhead = new node;
    // 1
    rhead->data=0;
    rhead->next=NULL;
    node* p=head->next;
    // 2
//    扫描节点
    node* pre=NULL;
//    存储当前扫描节点，然后把p往后推进
    // 3

    while(p!=NULL){
        node* pnext=p->next;
        // 4
//        存储当前节点的后边节点，实际上也就是说反转链表需要四个节点，一个用来当头节点，
//         一个用来当扫描节点，一个用来存储后边的，一个用来存储前边的
//          存储前边的主要是为了把当前节点之前前边，实际上就是断链，然后
//          这个就是前插法
        if(pnext==NULL){
            rhead->next=p;
        }
        p->next=pre;
        pre=p;
        p=pnext;
    }
    return rhead;
}

//倒数第k个节点
node* findknode(node* root,int k){
    node* head=root;
    node* behind;
//这种方法是不会关心两个指针的起点在哪，只需要考虑k的值就可以了
    for (int i = 0; i <k ; ++i) {
        head=head->next;
    }
    behind=root->next;
    while(head->next!=NULL){
        head=head->next;
        behind=behind->next;
    }

    return behind;
}
//找到链表中环的入口

//两个链表的合并
node* merge(node* head1,node* head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    node* mergehead=NULL;
    if(head1->data<head2->data){
        mergehead=head1;
        mergehead->next=merge(head1->next,head2);
    }else{
        mergehead=head2;
        mergehead->next=merge(head1,head2->next);
    }

    return mergehead;
}
//寻找两个链表的第一个公共结点
//int getlistlength(node* root){
//    int length=0;
//    node* head=root;
//    while(head!=NULL){
//        length++;
//        head=head.next;
//
//    }
//    return length;
//}
//node* findfirstcommonnode(node* root1,node* root2){
//    int length1=getlistlength(root1);
//    int length2=getlistlength(root2);
//
//    int lendif=length1-length2;
//    return root1;
//}
node* headinsert(node* root,node* reshead,int k){
//    root是那个逆置过的头节，需要对这个链表进行遍历
    node* now;
    now=root->next;
    int yushu=0;
    int temp=0;
    while(now!=NULL){

        int res=temp+now->data*k;

        if(res>9){
            yushu=res%10;
            temp=res/10;
        }else{
            yushu=res;
            temp=0;
        }
        node* r=new node;
        r->data=yushu;
        r->next=reshead->next;
        reshead->next=r;
        now=now->next;
    }
    return reshead;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> A;

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d",&temp);
        A.push_back(temp);
    }
    node *h;
    h=create(A);
    node* r;
    r=reverse(h);
    print(r);
    node* res;
    node* head=new node;
    head->data=0;
    head->next=NULL;
    res=headinsert(r,head,k);
    print(res);
    return 0;
}