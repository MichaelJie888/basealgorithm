#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int main ()
{
    int myints[] = {42,71,71,71,12};
    priority_queue<int,vector<int>,less<int>> p;
    for (int i = 0; i < 5; ++i) {
        p.push(myints[i]);
    }

    while(!p.empty()){
        printf("%d\n",p.top());
        p.pop();
    }

    return 0;
}