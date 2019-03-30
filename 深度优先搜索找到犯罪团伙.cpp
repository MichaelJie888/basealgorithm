/*
 * 深度优先搜索找到犯罪团伙
 *
 *
 * */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

const int maxn=2010;
const int INF=10000000;
map<int,string> inttostring;
map<string,int> stringtoint;
map<string,int> gang;

int G[maxn][maxn]={0},weight[maxn]={0};
int n,k,numPerson=0;
bool vis[maxn]={false};

void DFS(int nowVist,int& head,int& numMember,int& totalValue){
    numMember++;
    vis[nowVist]= true;
    if(weight[nowVist]>weight[head]){
        head=nowVist;
    }

    for (int i = 0; i <numPerson ; ++i) {
        if(G[nowVist][i]>0){
            totalValue+=G[nowVist][i];
            G[nowVist][i]=G[i][nowVist]=0;
            if(vis[i]== false){
                DFS(i,head,numMember,totalValue);
            }
        }
    }
}

void traveDFS(){
    for (int i = 0; i <numPerson ; ++i) {
        if(vis[i]== false){
            int head=i,numMember=0,totaValue=0;
            DFS(i,head,numMember,totaValue);
            if(numMember>2 && totaValue>k){
                gang[inttostring[head]]=numMember;
            }
        }
    }
}

int change(string str){
    if(stringtoint.find(str)!=stringtoint.end()){
        return stringtoint[str];
    }else{
        stringtoint[str]=numPerson;
        inttostring[numPerson]=str;
        return numPerson++;
    }
}

int main(){
    int w;
    string str1,str2;
    cin>>n>>k;
    for (int i = 0; i <n ; ++i) {
        cin>>str1>>str2>>w;
        int s1=change(str1);
        int s2=change(str2);
        G[s1][s2]+=w;
        G[s2][s1]+=w;
        weight[s1]+=w;
        weight[s2]+=w;


    }

    traveDFS();

    cout<<gang.size()<<endl;
    map<string,int>::iterator st;
    for (st=gang.begin(); st!=gang.end() ; st++) {
        cout<<st->first<<st->second<<endl;
    }

    return 0;
}