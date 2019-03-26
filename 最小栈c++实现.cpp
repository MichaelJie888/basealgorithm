#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MinStack(){
    }
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};



int main(){
    MinStack* g=new MinStack();
    g->push(4);
    g->push(10);
    cout<<g->getMin()<<endl;
    g->pop();
    cout<<g->getMin()<<endl;

    return 0;
}