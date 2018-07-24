#include <iostream>
#include <vector>

using namespace std;

/*
给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N元（N为0-10000的非负整数）的不同组合的个数。

输入描述:
输入为一个数字N，即需要拼凑的面额
输出描述:
输出也是一个数字，为组成N的组合个数。
*/

/*
思路：动态规划
需要平凑的面额是n，维护dp[i],表示取到i时的组合数目，dp[0]=1
面额数组a[6] = {1, 5, 10, 20, 50, 100};
dp[j]=dp[j]+dp[j-a[i]]  约束条件j>a[i]
因为面额数目任意，所以需要分别处理
*/

int main()
{
    int n;
    cin >> n;
    int a[6] = {1, 5, 10, 20, 50, 100};
    vector<long long> dp(n+1, 0);
    
    dp[0] = 1;              //谁的不取
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (j >= a[i])
                dp[j] = dp[j] + dp[j-a[i]];
        }
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}