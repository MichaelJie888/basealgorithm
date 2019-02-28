#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

bool prime(int x){
    double i=floor(sqrt(x));

    for (int j = 2; j <=i; ++j) {
        if(x%j==0){
            return false;
        }
    }

    return true;
}

int main(){
    int s,e;
    cin>>s>>e;
    int n=1000;
    int p[10000]={0};
    int j=1;
    for (int i = 2; i < n; ++i) {
        if(prime(i)){
            p[j]=i;
            j++;
        }
    }
    for (int k = s; k <=e; ++k) {
        cout<<p[k]<<" ";
    }
    return 0;
}