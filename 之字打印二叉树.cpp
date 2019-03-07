void PrintZword(node* root){
    if(root==NULL){
        return;
    }
    stack<node*> l[2];

    int current=0;
    int next=1;
    l[current].push(root);
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