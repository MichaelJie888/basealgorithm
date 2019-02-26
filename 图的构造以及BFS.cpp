#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1010;
/*
 * 给出n个用户的关注情况，他们各自关注了那些用户，以及一个转发层数上限L
 * 给出最初发出消息的用户编号，求在转发层数上限内消息最多会被多少用户转发
 * 第一行给两个整数，第一个是用户个数n，第二个是不直接关注层数
 * 下边n行跟随，每一行包含用户i的粉丝数，以及粉丝编号
 * 最后一个k给出来，给k个用户，问他们发出的信息会被多少人转发
 * */
struct Node{
    int id;
    int layer;
};
vector<Node> Adj[maxn];//建造图，每一个向量中存放的都是结构体，这样可以直接对结构体进行计算，
bool inq[maxn]={false};
//图中存放的是某个人关注的其他人
int BFS(int s,int L){//对图进行广度优先遍历
    int numForward=0;
    queue<Node> q;
    Node start;
//    刚开始把2放进去，然后对2号进行计算
    start.id=s;
    start.layer=0;
//    push进去，然后设置成正确的bool
    q.push(start);
    inq[start.id]=true;

    while(!q.empty()){
        Node topNode=q.front();
        q.pop();
        int u=topNode.id;
        for (int i = 0; i < Adj[u].size(); i++) {
            Node next=Adj[u][i];
            next.layer=topNode.layer+1;
            if(inq[next.id]==false && next.layer<=L){
                q.push(next);
                inq[next.id]=true;
                numForward++;
            }
        }
    }
//    实际上每个adj[i]中存储的都是关注i的人，但是在题目中说的太他妈拗口了，后边跟的都是第几个用户关注的人，我草
    return numForward;
}

int main(){
    Node user;
    int n,L,numFollow,idFollow;
    scanf("%d%d",&n,&L);
    for (int i = 1; i <=n ; ++i) {
        user.id=i;
        scanf("%d",&numFollow);
        for (int j = 0; j < numFollow; ++j) {
            scanf("%d",&idFollow);
            Adj[idFollow].push_back(user);
        }
    }
//    输入7个人的信息，并且其关注的其他人信息
    int numQuery,s;
    scanf("%d",&numQuery);
//想要计算的人的个数
    for (int k = 0; k < numQuery; ++k) {
        memset(inq,false, sizeof(inq));
        scanf("%d",&s);
        int numForward=BFS(s,L);
        printf("%d\n",numForward);
//        对某人发微博转发人数进行计算
    }
}