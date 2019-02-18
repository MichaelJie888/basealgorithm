#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

string LeftRotateString(string str, int n) {
        int len=str.size();
        if(n==len){
            return str;
        }else if(n>len){
            n=n-len;
        }
        string res;
        res=str.substr(n,len-n)+str.substr(0,n);
        return res;
    }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<LeftRotateString("huangchuang",3);
    return 0;
}