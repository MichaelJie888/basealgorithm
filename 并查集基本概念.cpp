//初始化
int father[100];
for(int i=1;i<=n;i++){
    father[i]=i;
}

//查找

int findFather(int x){
    while(x!=father[x]){
        x=father[x];
    }

    return x;
}


int findFather(int x){
    if(x==father[x]) return x;
    else return findFather(father[x]);
}
//合并

void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}

//路径压缩，应用于如果有10的5次方个节点链式组成，那么在这样的结构上进行查询效率就会很低，所以在查找过程中
//可以针对结构进行变换，就是把链式改成树式的

void findFather(int x){
    int a=x;
//    找到根节点
    while(x!=father[x]){
        x=father[x];
    }
//    修改此路径上所有的根节点为x，这样在下次查找的时候就会降低查找次数
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    
    return x;
}