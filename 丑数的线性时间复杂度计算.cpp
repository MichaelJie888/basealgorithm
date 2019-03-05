#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=2000;
int ug[maxn],c[maxn];
int n;
int Min(int a,int b,int c){
    int min=(a<b) ? a : b;
    min=(min<c)? min:c;

    return min;
}
int Getugnum(int n){
    if(n<=0) return 0;
    ug[0]=1;
    int nextug=1;

    int *u1=ug,*u2=ug,*u3=ug;
    while (nextug<n){
        int min=Min(*u1*2,*u2*3,*u3*5);
        ug[nextug]=min;
        printf("%d ",min);
        while(*u1*2<=ug[nextug]) ++u1;
        while(*u2*3<=ug[nextug]) ++u2;
        while(*u3*5<=ug[nextug]) ++u3;

        ++nextug;

    }

    return ug[n-1];
}


int main(){
    Getugnum(100);

    return 0;

}