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