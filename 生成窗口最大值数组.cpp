#include<deque>
#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
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
int main(){

    vector<int> arr={4,3,5,4,3,3,6,7};
    int k=3;
    vector<int> r=getmaxwindow(arr,k);

    for (int i = 0; i <r.size() ; ++i) {
        cout<<r[i]<<endl;
    }

    return 0;
}