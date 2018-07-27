/*
一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，
袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一
跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到
最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1

输入描述:
输入分两行，第一行是数组长度N (1 ≤ N ≤ 10000)，第二行是每一项的值，用空格分隔。
输出描述:
输出最少的跳数，无法到达输出-1
*/

/*
思路：
动态规划问题：
使用dp[n]:表示n米时需要几跳
那么从0开始跳，dp[2]=dp[0]+1；从1开始跳，dp[2]=dp[1]+1。该取哪一个，当然是最小的啦。 
如果河宽3米，那么我有三种选择，从0、1、2开始跳……
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxnum = 0x3f3f3f3f;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> dp(n+1, 0);
    a[0] = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = maxnum;
        for (int j = 0; j <= i-1; j++)
        {
            if (a[j] >= i-j)
                dp[i] = min(dp[i], dp[j]+1);
        }
    }

    if (dp[n] != maxnum)
        cout << dp[n] << endl;
    else
        cout << -1 << endl;
    system("pause");
    return 0;
}