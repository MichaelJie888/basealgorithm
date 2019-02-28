#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;


int main(){
    int n,count=0;
    cin>>n;
    string name,str;
    string minstr="z",minname="",maxstr="",maxname="";
    string start="1814/09/06";
    string end="2014/09/06";
    for (int i = 0; i < n; i++) {
        cin>>name>>str;
        if(str>=start && str<=end){
            count++;
            if(minstr>str){
                minstr=str;
                minname=name;
            }
            if(maxstr<str){
                maxstr=str;
                maxname=name;
            }
        }
    }
    cout<<count<<" "<<minname<<" "<<maxname<<endl;

    return 0;
}