#include <iostream>
#include <vector>

using namespace std;

/*
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。

输入描述:
输入为两行:
第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
第二行为n个正整数A[i](32位整数)，以空格隔开。
 
输出描述:
输出所求的方案数
*/

/*
思路：
动态规划，即保留先前的结果值

用dp，dp[i][j]表示用前i个值组成和为j的方案数
当遍历到第i个数a[i]时，
如果a[i]>j,  则dp[i][j] = dp[i-1][j]
如果a[i]<=j, 则dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]]
*/

long long dp[1000][1000];

int main()
{
    int n, sum;
    vector<long> A;
    int res = 0;
    cin >> n >> sum;
    
    for (int i = 0; i < n; i++)
    {
        long tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    
    /*初始化dp*/
    for (int i = 0; i < 1000; i++)
        dp[i][0] = 1;               //表示前i个数和为0的取法只有一种，就是不取任何数
    for (int i = 1; i < 1000; i++)
        dp[0][i] = 0;               //表示前0个数和为i的取法不存在
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (A[i] <= j)
                dp[i+1][j] = dp[i][j]+dp[i][j-A[i]];
            else
                dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[n][sum];
    system("pause");
    return 0;
}