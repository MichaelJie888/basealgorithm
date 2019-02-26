#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int a[6]={9,4,2,5,6,-1};
    sort(a,a+4);
    for (int i = 0; i < 6; ++i) {
        cout<<a[i]<<" ";
    }
    char c[]={'h','d','r','a'};
    sort(c,c+4);
    for (int j = 0; j < 4; ++j) {
        cout<<c[j]<<" ";
    }

    sort(a,a+6,cmp);
    cout<<endl;
    for (int k = 0; k < 6; ++k) {
        cout<<a[k]<<" ";
    }
    return 0;
}