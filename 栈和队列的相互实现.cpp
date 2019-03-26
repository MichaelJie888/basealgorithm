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

class MyStack {
private:
    queue<int> data;
    queue<int> s;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(data.size()!=1){
            s.push(data.front());
            data.pop();
        }
        int res=data.front();
        data.pop();
        while(!s.empty()){
            data.push(s.front());
            s.pop();
        }
        return res;
    }

    /** Get the top element. */
    int top() {
        while(data.size()!=1){
            s.push(data.front());
            data.pop();
        }
        int res=data.front();
        s.push(res);
        data.pop();
        while(!s.empty()){
            data.push(s.front());
            s.pop();
        }
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int res=s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int res=s1.top();
        s2.push(res);
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};


int main(){
    MyQueue* m=new MyQueue();
    m->push(4);
    m->push(19);
    m->push(1);
    cout<<m->peek();

    return 0;
}