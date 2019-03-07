#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
const int maxn=20;
int A[maxn][maxn]={0};
void PrintMatrix(int col,int row,int start){
    int endX=col-start-1;
    int endY=row-start-1;

    for (int i = start; i <=endX ; ++i) {
        printf("%d",A[start][i]);
    }

    if(start<endY){
        for (int i = start+1; i <=endY ; ++i) {
            printf("%d",A[i][endY]);
        }
    }

    if(start<endX && start<endY){
        for (int i = endX-1; i >=start ; i--) {
            printf("%d",A[endY][i]);
        }
    }

    if(start<endX && start<endY-1){
        for (int i = endY-1; i >start ; --i) {
            printf("%d",A[i][start]);
        }
    }
}


void printMatrix(int col,int row){
    if(A==NULL || col<=0 || row<=0){
        return;
    }

    int start=0;
    while(col>start*2 && row>start*2){
        PrintMatrix(col,row,start);
        start++;
    }
}



int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&A[i][j]);
        }
    }

    printMatrix(n,n);
    return 0;

}