#include <stdio.h>
struct point{
    int x;
    int y;
    point(){}
    point(int _x,int _y):x(_x),y(_y) {}
}p[10];

int main(){
    int num=0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            p[num++]=point(i,j);
        }
    }

    for (int k = 0; k < num; ++k) {
        printf("%d %d\n",p[k].x,p[k].y);

    }

    return 0;
}