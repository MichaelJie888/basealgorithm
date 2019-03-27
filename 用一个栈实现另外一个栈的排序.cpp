#include<deque>
#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
vector<int> getmaxwindow(vector<int>& A,int w){
    if(A.size()==0 || w<1 || A.size()<w )
        return A;
    deque<int> q;
    vector<int> res(A.size()-w+1);
    int index=0;
    for (int i = 0; i <A.size() ; ++i) {
        while(!q.empty() && A[q.back()]<=A[i]){
            q.pop_back();
        }

        q.push_back(i);
        if(q.front()==i-w)
            q.pop_front();
        if(i>=w-1)
            res[index++]=A[q.front()];
    }
    return res;

}
void sortstack(stack<int> &s){
    stack<int> help;
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        while(!help.empty() && help.top()<cur){

            s.push(help.top());
            help.pop();
        }
        help.push(cur);
    }
    while(!help.empty()){
        s.push(help.top());
        help.pop();
    }
}
int main(){

    vector<int> arr={3,4,5,6,2,1,9,7};
    stack<int> rr;
    for (int j = 0; j < arr.size(); ++j) {
        rr.push(arr[j]);
    }
    cout<<rr.size()<<endl;
    sortstack(rr);
    for (int i = 0; i <8 ; ++i) {
//        这个地方是不可以把i的边界设置为rr。size的，因为rr的大小是在变化的，所以输出就是只有一半，
        cout<<rr.top()<<endl;
        rr.pop();
    }

    return 0;
}