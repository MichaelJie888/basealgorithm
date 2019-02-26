#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int a[5]={1,2,3,4,5};
    fill(a,a+5,233);
    for (int k = 0; k < 5; ++k) {
        printf("%d ",a[k]);

    }
    memset(a,0, sizeof(a));
    for (int k = 0; k < 5; ++k) {
        printf("%d ",a[k]);

    }

    return 0;
}