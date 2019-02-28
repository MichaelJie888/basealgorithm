#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <vector>
using namespace std;

int d[1000];
vector<int> s[5];
int main(){
    int n;
    int sum1=0,max=0,sum=0,c=0;
    double sum2=0;
    scanf("%d",&n);
    for (int i = 0; i <n; i++) {
        scanf("%d",&d[i]);
    }
    for (int j = 0; j <n ; ++j) {
        if(d[j]%5==0 && d[j]%2==0){
            sum1+=d[j];
        }else if(d[j]%5==1){
            s[2].push_back(d[j]);
        }else if(d[j]%5==2){
            s[3].push_back(d[j]);//求个数
        }else if(d[j]%5==3){
            c++;
            sum2+=d[j];
        }else if(d[j]%5==4){
            if(d[j]>max){
                max=d[j];
            }
        }
    }
    if(sum1==0){
        printf("N ");
    }else{
        printf("%d ",sum1);
    }
    if (s[2].size()==0){
        printf("N ");
    }else{
        for (int k = 0; k < s[2].size(); ++k) {
            if(k%2==0){
                sum+=s[2][k];
            }else{
                sum-=s[2][k];
            }
        }
    }
    printf("%d ",sum);
    if(s[3].size()==0){
        printf("N ");
    }else{
        printf("%d ",s[3].size());
    }
    if(sum2==0){
        printf("N ");
    }else{
        printf("%0.1f ",sum2/c);
    }
    if(max==0){
        printf("N");
    }else{
        printf("%d",max);
    }

    return 0;
}