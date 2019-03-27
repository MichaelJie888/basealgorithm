#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;



int main(){
    string c;
    cin>>c;
    set<char> res;
    set<char>::iterator it;
    queue<char> q;
    int max=0;
    for (int i = 0; i <c.size() ; ++i) {
        if(res.find(c[i])==res.end() || res.empty()){
            q.push(c[i]);
            res.insert(c[i]);
            max=max > q.size() ? max : q.size();
        }else{
            while(q.front()!=c[i]){
                res.erase(res.find(q.front()));
                q.pop();
            }
            res.erase(res.find(c[i]));
            q.pop();
            q.push(c[i]);
            res.insert(c[i]);
            max=max > q.size() ? max : q.size();
        }

    }
    printf("%d",max);
    while(!q.empty()){
        printf("%c",q.front());
        q.pop();
    }
    return 0;
}