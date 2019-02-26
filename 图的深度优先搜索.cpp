#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
 * 给出若干人的通话长度，将这些通话长度分为若干组，每个组的总边权设为该组内所有通话的长度之和
 * 每个人的点权设为该人参与的通话长度之和，给定一个阈值，总边权超过k并且成员人数超过2，
 * 这伙人被判为犯罪团伙
 * 第一行给出两个数据，一个是8组数据，一个是阈值
 * 然后输入两个人以及通话时间，
 * 由于是字符串，所以需要进行处理才好进行计算，
 *
 * */
const int maxn=2010;
const int INF=10000000;

map<int,string> intToString; //编号-姓名
map<string,int> stringToInt;
map<string,int> Gang; //head-人数

int G[maxn][maxn]={0},weight[maxn]={0};
int n,k,numPerson=0;//边数，下限k，总人数
bool vis[maxn]={false};

void DFS(int nowVisit,int& head,int& numMember,int& totalValue){
    numMember++;
    vis[nowVisit]= true;
    if(weight[nowVisit]>weight[head]){
        head=nowVisit;
    }
    for (int i = 0; i <numPerson ; ++i) {
        if(G[nowVisit][i]>0){
            totalValue+=G[nowVisit][i];
            G[nowVisit][i]=G[i][nowVisit]=0;
            if(vis[i]== false){
                DFS(i,head,numMember,totalValue);
            }
        }
    }
}
void DFSTrave(){
    for (int i = 0; i < numPerson; ++i) {
        if(vis[i]== false){
            int head=i,numMember=0,totalvalue=0;
            DFS(i,head,numMember,totalvalue);
            if(numMember>2 &&totalvalue>k){
                Gang[intToString[head]]=numMember;
            }
        }
    }
}

int change(string str){
    if(stringToInt.find(str)!=stringToInt.end()){
        return stringToInt[str];
    }else{
        stringToInt[str]=numPerson;
        intToString[numPerson]=str;
        return numPerson++;
    }
}

int main(){
    int w;
    string str1,str2;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>str1>>str2>>w;
//        输入原始数据，然后进行变换，人数最初设置为0，change一次，就加1，所以不会重复，
        int id1=change(str1);
        int id2=change(str2);
//        存储每个点的点权，以及存储边权，
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2]+=w;
        G[id2][id1]+=w;
    }
//    对所有人进行深度优先搜索
    DFSTrave();
    cout<<Gang.size()<<endl;
    map<string,int>::iterator it;
    for (it = Gang.begin();  it!=Gang.end() ; it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}