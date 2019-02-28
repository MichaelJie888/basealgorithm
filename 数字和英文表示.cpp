#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct student{
    char name[10];
    char id[10];
    int grade;
}s[10000];
int main(){
    stack<string> q;
    string s;
    cin>>s;
    int n=0;
    string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i <s.size() ; ++i) {
        n+=(s[i]-'0');
    }
    if(n==0) printf("zero");
    while(n!=0){
        q.push(num[n%10]);
        n=n/10;
    }
    while(q.size()>1){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<q.top()<<endl;
    return 0;
}