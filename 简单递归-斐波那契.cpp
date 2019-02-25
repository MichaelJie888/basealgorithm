#include <cstdio>
#include <iostream>
using namespace std;
int F(int n){
    if(n==1 || n==0) return 1;
    else {
        return F(n-1)+F(n-2);
    }
}
int main() {
    cout<<F(1);
    return 0;
}