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
int Ptran10(int x,int p){
    while(x!=0){
        y=y+(x%10)*product;
        x=x/10;
        product=product*p;
    }
    return y;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<Ptran10(1000010,2);
    return 0;
}