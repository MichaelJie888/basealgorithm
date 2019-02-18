#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int product=1;
int y=0;
int tentranP(int x,int p){
    while(x!=0){
        y=y+(x%p)*product;
        x=x/p;
        product=product*10;
    }
    return y;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<tentranP(32,4);
    return 0;
}