#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，
然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。 例如： 如果{2,1,2,7}是你有的一系
列数，小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，他说的数字是6，那么你没有办法拼凑
出和为6 现在小易给你n个数，让你找出无法从n个数中选取部分求和的数字中的最小数。
*/

/*
输入描述:
输入第一行为数字个数n (n ≤ 20)
第二行为n个数xi (1 ≤ xi ≤ 100000)

输入描述：
输出最小不能由n个数选取求和组成的数
*/

/*思路：
将输入的数组进行从小到大排序
当前i项的和与第i+1项不连续时，那么最小不能到达的数就是前i项的和加1
*/
int main()
{
    int n;
    long tmp;
    vector<long> all;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &tmp);
        all.push_back(tmp);
    }
    sort(all.begin(), all.end());
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (all[i] > sum+1)
            break;
        else
            sum += all[i];
    }
    cout << sum+1;
    system("pause");
    return 0;
}