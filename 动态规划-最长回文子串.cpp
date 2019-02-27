#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * Manacher O(n)
 * @param string str
 */
int manacher(string &str) {
    int length = str.size() * 2 + 1;
    string cur_str(length, '#');
    // 字符串中间 插入 特殊字符
    for (int i = 0; i < length; ++i) {
        cur_str[i] = (i % 2 == 1 ? str[(i+1)/2 - 1] : '#');
    }
    cout << cur_str << endl;
    vector<int> RL(length, 0); // 每一个位置的回文串 长度 (不包含特殊字符)
    int maxLength= 0; // 最大长度
    int pos      = 0; // 当前最大字串对称位置
    int maxRight = 0; // 当前最大字串所能到达的最右边
    for (int i = 0; i < length; ++i) {
        if (i >= maxRight) {
            RL[i] = 1; // 超出最右位置，与之前的对称串没有关系
        } else {
            // 当前位置 在最大回文串里面(maxRight 左边)
            int j = 2 * pos - i; // i 关于pos对称的j (j 以及求过)
            RL[i] = min(RL[j], maxRight - i);
            /* 因为 maxRight - i 的最大值是 maxRight - pos
             * RL[j] 的 maxRight 如果超过pos，则肯定取 maxGight-i
             */
        }
        while (i - RL[i] >= 0 && i + RL[i] < length && cur_str[i-RL[i]] == cur_str[i+RL[i]]) {
            RL[i]++;
        }
        // 对称位置i + 回文串长度 （回文串长度 在cur_str里面是对称半径长度）
        if (RL[i] - 1 + i > maxRight) {
            maxRight = RL[i] + i - 1;
            pos = i;
        }
        maxLength = max(maxLength, RL[i]);
    }
    return maxLength - 1;
}
/**
 * 动态规划， O(n^2)
 */
int dpAlgorithm(string &str) {
    int length = str.size();
    vector<vector<int> > dp(length, vector<int>(length, 0));
    for (int i = length - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < length; ++j) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }// end for
    return dp[0][length-1];
}
int main()
{
    string str;
    while (cin >> str) {
        cout << dpAlgorithm(str) << endl;
        cout << manacher(str) << endl;
    }
    return 0;
}