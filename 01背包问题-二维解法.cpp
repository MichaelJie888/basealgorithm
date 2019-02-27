#include<iostream>
using namespace std;
#include <algorithm>

int main()
{
    int w[] = { 0 , 3,5,1,2,2 };			//商品的体积2、3、4、5
    int c[] = { 0 , 4,5,2,1,3};			//商品的价值3、4、5、6
    int V = 8;					        //背包大小
    int dp[9] = {  0 } ;			        //动态规划表

    for (int i = 1; i <= 5; i++) {
        for (int v = V; v >=w[i]; v--) {
                dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
        for (int v = 0; v < 9; v++) {
            cout <<dp[v] << ' ';
        }
        cout<<endl;
    }

    return 0;
}
