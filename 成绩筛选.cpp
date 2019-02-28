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
bool cmp(student a,student b){
    return a.grade>b.grade;
}
int main(){
    int n,min,max;
    bool flag= false;
    scanf("%d",&n);

    for (int i = 0; i <n; ++i) {
        scanf("%s %s %d",&s[i].name,&s[i].id,&s[i].grade);
    }
    scanf("%d %d",&min,&max);
    sort(s,s+n,cmp);
    for (int j = 0; j < n; ++j) {
        if(s[j].grade>=min && max>=s[j].grade){
            cout<<s[j].name<<" "<<s[j].id<<endl;
            flag=true;
        }
    }
    if(flag== false){
        cout<<"NONE"<<endl;
    }
    return 0;
}