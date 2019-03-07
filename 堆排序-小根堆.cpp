#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int heap[11]={0,3,1,2,8,7,5,9,4,6,0};
int n=10;
void downjust(int low,int high){//大的往上调
    int i=low,j=i*2;
    while(j<=high){
        if(j+1<=high && heap[j+1]>heap[j]){
            j=j+1;
        }
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
}

void heapsort(){
    for (int i = n/2; i >=1; i--) {//从最后那个不是叶节点的地方开始
        downjust(i,n);
        }
        cout<<endl;
    }

    for (int j = n; j >1 ; j--) {//从最后一个节点开始，交换，下调
        swap(heap[j],heap[1]);
        downjust(1,j-1);
        }
        cout<<endl;
    }
}

int main(){
    heapsort();
    return 0;

}

/*
创建堆之后
0 3 1 2 8 7 5 9 4 6 0 
创建堆之后
0 3 1 2 8 7 5 9 4 6 0 
创建堆之后
0 3 1 9 8 7 5 2 4 6 0 
创建堆之后
0 3 8 9 6 7 5 2 4 1 0 
创建堆之后
0 9 8 5 6 7 3 2 4 1 0 
0 8 7 5 6 0 3 2 4 1 9 
0 7 6 5 4 0 3 2 1 8 9 
0 6 4 5 1 0 3 2 7 8 9 
0 5 4 3 1 0 2 6 7 8 9 
0 4 2 3 1 0 5 6 7 8 9 
0 3 2 0 1 4 5 6 7 8 9 
0 2 1 0 3 4 5 6 7 8 9 
0 1 0 2 3 4 5 6 7 8 9 
0 0 1 2 3 4 5 6 7 8 9 
*/ 
