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
int LLPow(LL a,LL b,LL m){
    LL ans=1;
    for(int i=0;i<b;i++){
        ans=ans*a;
    }
    return ans%m;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<LLPow(2,50,190000);
    return 0;
}