#include<iostream>
using namespace std;
#include <algorithm>

int main()
{
    int w[] = { 0 , 3,5,1,2,2 };			//商品的体积2、3、4、5
    int c[] = { 0 , 4,5,2,1,3};			//商品的价值3、4、5、6
    int V = 8;					        //背包大小
    int dp[6][9] = { {0} } ;			        //动态规划表

    for (int i = 1; i <= 5; i++) {
        for (int v = w[i]; v<=V; v++) {
                dp[i][v] = max(dp[i-1][v], dp[i-1][v - w[i]] + c[i]);
        }

    }

    //动态规划表的输出
    for (int j = 0; j < 6; ++j) {
        for (int v = 0; v < 9; v++) {
            cout <<dp[j][v] << ' ';
        }
        cout<<endl;
    }


    return 0;
}
/*
0 0 0 0 0 0 0 0 0 
0 0 0 4 4 4 4 4 4 
0 0 0 0 0 5 5 5 9 
0 2 2 2 2 5 7 7 9 
0 0 2 3 3 5 7 7 9 
0 0 3 3 5 6 7 8 10 
*/