/*
 * 优先队列实际上就是最大最小堆
 * 实际上这个确实是可以拿来用的，比如在做题的时候，我擦，
 * 另外，进一步的增加其功能
 * priority_queue<int,vector<int>,greater<int>> q;
 * 这个vector作为一个承载器，通过这样调整可以做到最大堆最小堆，
 * 但是如果是那种符合结构的数据的话，那么就需要另外的操作
 *
 * */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct fruit{
    string name;
    int price;
    friend bool operator<(fruit f1,fruit f2){
        return f1.price<f2.price;
    }
};
int main(){
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(3);
    q.push(10);
    q.push(90);
    q.push(-1);
    q.push(-90);
    q.push(1000);
    priority_queue<fruit> p;
    fruit a;
    fruit b,c;
    a.name="apple";
    a.price=4;
    b.name="banana";
    b.price=5;
    c.name="pea";
    c.price=2;
    p.push(a);
    p.push(b);
    p.push(c);
    cout<<p.top().name<<" "<<p.top().price<<endl;
    printf("%d",q.top());
    return 0;
}