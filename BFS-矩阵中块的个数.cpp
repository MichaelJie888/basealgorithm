#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=100;
struct node{
    int x,y;
}Node;

int n,m;
int matrix[maxn][maxn];
bool inq[maxn][maxn]={false};

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

bool judge(int x,int y){  //判断坐标（x,y）是否需要访问
    if(x>=n || x<0 ||y>=m || y<0) return false;
    if(matrix[x][y]==0 || inq[x][y]== true) return  false;

    return true;
}

void BFS(int x,int y){//从某一个点开始进行广度优先遍历
//    这里的队列不需要存储指针，这个是需要一个注意的点
    queue<node> Q;
    Node.x=x,Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while (!Q.empty()){
        node top=Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {//对四个方向进行遍历
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            if(judge(newX,newY)){
                Node.x=newX,Node.y=newY;
                Q.push(Node);
                inq[newX][newY]= true;
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
//输入矩阵大小以及矩阵数据
    int ans=0;
    for (int k = 0; k <n ; k++) {
        for (int i = 0; i < m; i++) {
            if(matrix[k][i]==1 && inq[k][i]== false){
                ans++;
                BFS(k,i);
            }
        }

    }
//   对矩阵的每个位置进行遍历，然后如果矩阵为1并且没有访问过，就把快加一，然后广度优先遍历
    cout<<ans<<endl;
    return 0;
}