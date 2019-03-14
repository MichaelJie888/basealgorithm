#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int resu=0;
    scanf("%d",&n);
    string s[n];
    for (int i = 0; i <n ; ++i) {
        cin>>s[i];
    }
    int m=s[0].size();
    int res[n][m];

    for (int j = 0; j <m ; ++j) {
        if(s[0][j]=='0'){
            res[0][j]=0;
        }else{
            res[0][j]=1;
        }
    }
    for (int k = 0; k < n; ++k) {
        if(s[k][0]=='0'){
            res[k][0]=0;
        }else{
            res[k][0]=1;
        }
    }
    if(m==1){
        for (int i = 0; i < n; ++i) {
            if(s[i][0]=='1'){
                resu=1;
                break;
            }
        }
    }else if(n==1){
        for (int i = 0; i <m ; ++i) {
            if(s[0][i]=='1'){
                resu=1;
                break;
            }
        }
    }else if(n==0 && m==0){
        resu=0;
    }else{
        for (int l = 1; l < n; ++l) {
            for (int i = 1; i <m ; ++i) {

                if(s[l][i]=='0'){
                    res[l][i]=0;
                }else if(s[l-1][i]=='1' && s[l][i-1]=='1' ){
                    if(res[l-1][i]>=res[l-1][i-1] && res[l][i-1]>=res[l-1][i-1]){
                        res[l][i]=res[l-1][i-1]+1;
                        resu=max(resu,res[l][i]);
                    }else{
                        res[l][i]=min(res[l-1][i],res[l][i-1]);
                        resu=max(resu,res[l][i]);
                    }

                }else{
                    res[l][i]=1;
                }
            }
        }
    }


    cout<<resu*resu;
    return 0;
}