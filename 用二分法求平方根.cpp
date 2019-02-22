#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const double eps=1e-5;
double f(double x){
    return x*x;
}

double calSqrt(){
    double left=1,right=2,mid;
    while(right-left>eps){
        mid=(left+right)/2;
        if(f(mid)>3){
            right=mid;
        }else{
            left=mid;
        }

    }

    return mid;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<calSqrt();
//    for (int i = 0; i < 10; ++i) {
//        cout<<A[i]<<endl;
//    }
    return 0;
}